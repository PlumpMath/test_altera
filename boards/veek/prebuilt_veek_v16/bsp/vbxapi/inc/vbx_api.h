/**
 * @defgroup VBXapi
 * @brief VBX API library
 */
/**
 * @file
 * @defgroup VBX_API
 * @brief VBX API
 *
 * @ingroup VBXapi
 */
/**@{*/
//VBXCOPYRIGHTTAG

#ifndef __VBX_API_H
#define __VBX_API_H

#ifdef __cplusplus
extern "C" {
#endif
// -----------------------------------------------------------
// DEVELOPER API SECTION
// -----------------------------------------------------------

void        _vbx_init( vbx_mxp_t *this_mxp );

// Scratchpad APIs

vbx_void_t *vbx_sp_malloc_nodebug(                      size_t num_bytes );
vbx_void_t *vbx_sp_malloc_debug( int LINE, char *FNAME, size_t num_bytes );

void        vbx_sp_free_debug( int LINE, char *FNAME );
void        vbx_sp_free_nodebug();

vbx_void_t *vbx_sp_get();

void        vbx_sp_set_nodebug(                      vbx_void_t *new_sp );
void        vbx_sp_set_debug( int LINE, char *FNAME, vbx_void_t *new_sp );

int         vbx_sp_getused();
int         vbx_sp_getfree();

void        vbx_sp_push_nodebug();
void        vbx_sp_push_debug( int LINE, char *FNAME );

void        vbx_sp_pop_nodebug();
void        vbx_sp_pop_debug( int LINE, char *FNAME );

// Memory APIs

void       *vbx_shared_alloca_nodebug( size_t num_bytes, void *p );
void       *vbx_shared_alloca_debug( int LINE, char *FNAME, size_t num_bytes, void *p );
void       *vbx_shared_malloc( size_t num_bytes );
void        vbx_shared_free( void *shared_ptr );

// MXP device APIs
vbx_mxp_t  *vbx_open( const char* name );

#ifdef __cplusplus
}
#endif

#endif // __VBX_API_H
/**@}*/
