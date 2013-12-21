/**@file*/
//VBXCOPYRIGHTTAG

#include "vbx_copyright.h"
VBXCOPYRIGHT( api )

#include "vbx.h"
#include "vbx_port.h"



// --------------------------------------------------------
// System-wide global variables

#if VBX_USE_GLOBAL_MXP_PTR
vbx_mxp_t *vbx_mxp_ptr;
#endif

// --------------------------------------------------------
// Local variables
//#define vbx_sp        (this_mxp->sp)
#define sp_stack      (this_mxp->spstack)
#define sp_stack_top  (this_mxp->spstack_top)
#define sp_stack_max  (this_mxp->spstack_max)

// --------------------------------------------------------
// System-wide initialization
 
/** Initialize MXP processor
 *
 * param[out] this_mxp
 */
void _vbx_init( vbx_mxp_t *this_mxp )
{
	// initialize the sp stack
	// max = depth of scratchpad
	this_mxp->spstack_max = (int)( this_mxp->scratchpad_size / this_mxp->vector_lanes );
	this_mxp->spstack_top = 0;
// don't malloc spstack for MicroBlaze simulation, because axi_bram isn't
// large enough.
#if !VBX_DEBUG_NO_SPSTACK
	if( !this_mxp->spstack ) {
		int spstack_size = this_mxp->spstack_max * sizeof(vbx_void_t *);
		this_mxp->spstack = (vbx_void_t **)malloc( spstack_size );
		if ( !this_mxp->spstack ) {
			VBX_PRINTF("ERROR: failed to malloc %d bytes for spstack.\n", spstack_size);
			VBX_FATAL(__LINE__, __FILE__, -1);
		}
#if VBX_DEBUG_MALLOC
		printf("_vbx_init: malloc %d bytes\n", spstack_size);
#endif
	}
#endif

#if VBX_USE_GLOBAL_MXP_PTR
	// Must be set before any MXP instructions can be issued!
	vbx_mxp_ptr = this_mxp;
#endif

	// FIXME WARNING: the function call below only works for uniprocessors
	// The function must only be called by the CPU that owns the accelerator
	// described by 'mxp' instance.
	vbx_set_reg( VBX_REG_MXPCPU, (int)this_mxp ); // FIXME

	this_mxp->init = 1;
}


// --------------------------------------------------------
// Allocate and deallocate scratchpad memory.

static void print_sp_malloc_null()
{	printf( "WARNING: vbx_sp_malloc() requested 0 bytes.\n" );
}

static void print_sp_malloc_full( size_t num_bytes, size_t padded_bytes )
{
	printf( "ERROR: vbx_sp_malloc() requested %d bytes, ", (int)num_bytes );
	printf( "aligned needs %d bytes, ",       (int)padded_bytes );
	printf( "but only %d bytes available.\n", (int)vbx_sp_getfree() );
}

vbx_void_t *vbx_sp_malloc_debug( int LINE, char *FNAME, size_t num_bytes )
{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp || !this_mxp->init ) {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	}

	size_t padded = VBX_PAD_UP( num_bytes, this_mxp->dma_alignment_bytes );
	size_t freesp = (size_t)(this_mxp->scratchpad_end - this_mxp->sp); //VBX_SCRATCHPAD_END - (size_t)vbx_sp; // vbx_sp_getfree();

	vbx_void_t  *result = NULL;
	if( VBX_DEBUG_LEVEL && (num_bytes==0) ) {
		print_sp_malloc_null();
	} else if( VBX_DEBUG_LEVEL && freesp < padded ) {
		print_sp_malloc_full( num_bytes, padded );
	} else if( num_bytes > 0  &&  freesp >= padded ) {
		result        = this_mxp->sp;
		this_mxp->sp += padded;
#if VBX_DEBUG_MALLOC
		printf("sp_malloc %d bytes padded to %d, sp=0x%08x\n", num_bytes, padded, this_mxp->sp);
#endif
	}

	if( !result ) {
		VBX_FATAL(LINE,FNAME,-1);
	}
	return result;
}

vbx_void_t *vbx_sp_malloc_nodebug( size_t num_bytes )
{
	if( VBX_DEBUG_LEVEL ) {
		// print pretty error messages
		return vbx_sp_malloc_debug( __LINE__, __FILE__, num_bytes );
	}

	// do it, but do not print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();

	// check for valid argument values
	if( !this_mxp  ||  num_bytes==0 )
		return NULL;

	// add padding and allocate
	size_t padded = VBX_PAD_UP( num_bytes, this_mxp->dma_alignment_bytes );
	vbx_void_t *old_sp = this_mxp->sp;
	this_mxp->sp += padded;

	// scratchpad full
	if( this_mxp->sp > this_mxp->scratchpad_end ) {
		this_mxp->sp = old_sp;
		return NULL;
	}

	// success
	return old_sp;
}

void vbx_sp_free_debug( int LINE, char *FNAME )
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp )  {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else {
		this_mxp->sp = this_mxp->scratchpad_addr;
		this_mxp->spstack_top = 0;
	}
}

void vbx_sp_free_nodebug()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( this_mxp )  {
		this_mxp->sp = this_mxp->scratchpad_addr;
		this_mxp->spstack_top = 0;
	}
}


// --------------------------------------------------------
// Scratchpad manipulation routines

int vbx_sp_getused()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	int used = 0;
	if( this_mxp )
		used = (int)(this_mxp->sp - this_mxp->scratchpad_addr);
	return used;
}

int vbx_sp_getfree()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	int free = 0;
	if( this_mxp )
		free = (int)(this_mxp->scratchpad_end - this_mxp->sp);
	return free;
}

vbx_void_t *vbx_sp_get()
{
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	return this_mxp ? this_mxp->sp : NULL;
}

void vbx_sp_set_debug( int LINE, char *FNAME, vbx_void_t *new_sp )
{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp )  {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else if( (this_mxp->scratchpad_addr <= new_sp && new_sp <= this_mxp->scratchpad_end)
	           && VBX_IS_ALIGNED(new_sp,this_mxp->dma_alignment_bytes) ) {
		this_mxp->sp = new_sp;
	} else {
		VBX_PRINTF( "ERROR: attempt to set scratchpad to illegal or unaligned address 0x%08lx.\n", (long int)new_sp );
		VBX_FATAL(LINE,FNAME,-1);
	}
}

void vbx_sp_set_nodebug( vbx_void_t *new_sp )
{
	if( VBX_DEBUG_LEVEL ) {
		// print pretty error messages
		vbx_sp_set_debug( __LINE__, __FILE__, new_sp );
	}

	// do it, but do not print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( this_mxp
	           && (this_mxp->scratchpad_addr <= new_sp && new_sp <= this_mxp->scratchpad_end)
	           && VBX_IS_ALIGNED(new_sp,this_mxp->dma_alignment_bytes) ) {
		this_mxp->sp = new_sp;
	}
}


#define DO_THE_PUSH    this_mxp->spstack[ this_mxp->spstack_top++ ] = this_mxp->sp

void vbx_sp_push_debug( int LINE, char *FNAME )
{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp || !this_mxp->spstack ) {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else if( this_mxp->spstack_top >= this_mxp->spstack_max ) {
		VBX_PRINTF("ERROR: attempted to use vbx_sp_push() past top of stack.\n");
		VBX_FATAL(LINE,FNAME,-1);
	}
	DO_THE_PUSH;
}

void vbx_sp_push_nodebug()
{
	if( VBX_DEBUG_LEVEL ) {
		// print pretty error messages
		vbx_sp_push_debug( __LINE__, __FILE__ );
	}

	// do it, but do not print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( this_mxp && this_mxp->spstack && this_mxp->spstack_top < this_mxp->spstack_max ) {
		DO_THE_PUSH;
	}
}


#define DO_THE_POP     this_mxp->sp = this_mxp->spstack[ --this_mxp->spstack_top ]

void vbx_sp_pop_debug( int LINE, char *FNAME )
{
	// print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( !this_mxp || !this_mxp->spstack ) {
		VBX_PRINTF( "ERROR: failed to call _vbx_init().\n" );
		VBX_FATAL(LINE,FNAME,-1);
	} else if( this_mxp->spstack_top==0 ) {
		VBX_PRINTF("ERROR: attempted vbx_sp_pop() before first push.\n");
		VBX_FATAL(LINE,FNAME,-1);
	}
	DO_THE_POP;
}

void vbx_sp_pop_nodebug()
{
	if( VBX_DEBUG_LEVEL ) {
		// print pretty error messages
		vbx_sp_pop_debug( __LINE__, __FILE__ );
	}

	// do it, but do not print pretty error messages
	vbx_mxp_t *this_mxp = VBX_GET_THIS_MXP();
	if( this_mxp  &&  this_mxp->spstack  &&  0 < this_mxp->spstack_top ) {
		DO_THE_POP;
	}
}


// --------------------------------------------------------
// Memory allocation routines

// Allocate and deallocate memory that is shared between Nios II core and vector processor core.
// This shared memory is (1) uncached, and (2) properly aligned so DMA operations are permitted,
// and (3) aligned to a Data cache linesize so a fraction of the line is not cachable.
//
// The alloca() version allocates from the local stack. It will be automatically freed when the
// current function returns.

void *vbx_shared_alloca_nodebug( size_t num_bytes, void *p )
{
	void *alloced_ptr;
	void *aligned_ptr = NULL;

	unsigned int padding = VBX_PADDING();

	alloced_ptr = (void *)p;
	if( alloced_ptr ) {
		aligned_ptr = (void *)VBX_PAD_UP( alloced_ptr, padding );
		aligned_ptr = (void *)vbx_remap_uncached_flush( aligned_ptr, num_bytes );
	}

	return aligned_ptr;
}

void *vbx_shared_alloca_debug( int LINE, char *FNAME, size_t num_bytes, void *p )
{
	return vbx_shared_alloca_nodebug( num_bytes, p );
}

void *vbx_shared_malloc( size_t num_bytes )
{
	void *alloced_ptr;
	void *aligned_ptr = NULL;

	unsigned int padding = VBX_PADDING();

#if VBX_DEBUG_MALLOC
	printf("shared_malloc %d bytes\n", num_bytes);
#endif
	alloced_ptr = (void *)vbx_uncached_malloc(num_bytes+sizeof(void*)+2*padding);
	if( alloced_ptr ) {
		aligned_ptr = (void *)VBX_PAD_UP( (alloced_ptr+sizeof(void*)), padding );
		*((void **)(aligned_ptr-sizeof(void*))) = alloced_ptr;
	}

	return aligned_ptr;
}


void vbx_shared_free(void *shared_ptr)
{
	void *alloced_ptr;
	if( shared_ptr ) {
		alloced_ptr = *((void **)(shared_ptr-sizeof(void*)));
		vbx_uncached_free(alloced_ptr);
	}
}