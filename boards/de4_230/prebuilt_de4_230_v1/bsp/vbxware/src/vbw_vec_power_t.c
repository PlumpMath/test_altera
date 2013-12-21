/**@file*/
//VBXCOPYRIGHTTAG

// This is a templated file.
// Do not include a copyright header function.

// This file is meant to be #included in another .c file
// Do not define VBX_TEMPLATE_T locally in this file.
// Only define it externally in the file that includes
// this file.

// Protect this file from inclusion if VBX_TEMPLATE_T is not properly defined.
#ifdef VBX_TEMPLATE_T
#if (VBX_TEMPLATE_T==VBX_BYTESIZE_DEF  || \
		VBX_TEMPLATE_T==VBX_HALFSIZE_DEF  || \
		VBX_TEMPLATE_T==VBX_WORDSIZE_DEF  || \
		VBX_TEMPLATE_T==VBX_UBYTESIZE_DEF || \
		VBX_TEMPLATE_T==VBX_UHALFSIZE_DEF || \
		VBX_TEMPLATE_T==VBX_UWORDSIZE_DEF )

#include "vbw_vec_power_t.h"


/** VBX software power routine
 * 
 * @param[out] v_out.
 * @param[in] v_in1.
 * @param[in] v_in2.
 */
void VBX_T(vbw_vec_power)(vbx_sp_t *v_out, vbx_sp_t *v_in1, vbx_sp_t *v_in2)
{
	int i, vl;
	vbx_get_vl( &vl );
	vbx_sp_push();

	vbx_sp_t *vaa = (vbx_sp_t *)vbx_sp_malloc( vl*sizeof(vbx_sp_t) );
	vbx_sp_t *v_bb = (vbx_sp_t *)vbx_sp_malloc( vl*sizeof(vbx_sp_t) );
	vbx( SV(T), VMOV, v_out,    1, 0 );
	vbx( VV(T), VMOV,  vaa, v_in1, 0 );
	vbx( VV(T), VMOV,  v_bb, v_in2, 0 );

	vbx_sp_t *v_flg = (vbx_sp_t *)vbx_sp_malloc( vl*sizeof(vbx_sp_t) );
	vbx_sp_t *v_tmp = (vbx_sp_t *)vbx_sp_malloc( vl*sizeof(vbx_sp_t) );

	const int len_bits = sizeof(vbx_sp_t)*8;
	for( i=0; i <len_bits; i++ ) {
		vbx( SV(T), VAND,    v_flg,    1, v_bb  );
		vbx( VV(T), VMUL,    v_tmp, v_out, vaa  ); // tmp = out * aa
		vbx( VV(T), VCMV_NZ, v_out, v_tmp, v_flg );
		vbx( VV(T), VMUL,     vaa,  vaa, vaa  ); // aa = aa * aa
		vbx( SV(T), VSHR,     v_bb,    1, v_bb  ); //  b = b >> 1
		if( ((i&3) == 3) && (i < len_bits-1) ) {// check every 4 cycles
			vbx_acc( SV(T), VCMV_NZ, v_tmp, 1, v_bb );
			vbx_sync();
			if( !(*v_tmp) ) break;
		}
	}

#ifdef VBX_SIGNED
// if( 0 > v_in2 ) power = 0
	vbx( SV(T), VSUB,     v_tmp,  0, v_in2 );
	vbx( SV(T), VCMV_GTZ, v_out,  0, v_tmp );
#endif

	vbx_sp_pop();
}

#endif // properly defined VBX_TEMPLATE_T
#endif // defined(VBX_TEMPLATE_T)
