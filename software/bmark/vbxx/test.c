/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 *
 * Copyright (C) 2012-2014 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *
 *     * Neither the name of VectorBlox Computing Inc. nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * This agreement shall be governed in all respects by the laws of the Province
 * of British Columbia and by the laws of Canada.
 *
 * This file is part of the VectorBlox MXP Software Development Kit.
 *
 */


#include "vbx_copyright.h"
VBXCOPYRIGHT( test_vbx_cproto )

#include "vbx.h"
#include "vbx_test.h"

int compare_results_uhalf(vbx_uhalf_t *v_acc, vbx_uhalf_t *v_1, vbx_uhalf_t *v_2){
  vbx_acc(VVHU, VABSDIFF, v_acc, v_1, v_2);
  vbx_sync();
  return v_acc[0];
}

int compare_results_ubyte(vbx_ubyte_t *v_acc, vbx_ubyte_t *v_1, vbx_ubyte_t *v_2){
  vbx_acc(VVBU, VABSDIFF, v_acc, v_1, v_2);
  vbx_sync();
  return v_acc[0];
}

int compare_results_uword(vbx_uword_t *v_acc, vbx_uword_t *v_1, vbx_uword_t *v_2){
  vbx_acc(VVWU, VABSDIFF, v_acc, v_1, v_2);
  vbx_sync();
  return v_acc[0];
}

int compare_results_half(vbx_half_t *v_acc, vbx_half_t *v_1, vbx_half_t *v_2){
  vbx_acc(VVH, VABSDIFF, v_acc, v_1, v_2);
  vbx_sync();
  return v_acc[0];
}

int compare_results_byte(vbx_byte_t *v_acc, vbx_byte_t *v_1, vbx_byte_t *v_2){
  vbx_acc(VVB, VABSDIFF, v_acc, v_1, v_2);
  vbx_sync();
  return v_acc[0];
}

int compare_results_word(vbx_word_t *v_acc, vbx_word_t *v_1, vbx_word_t *v_2){
  vbx_acc(VVW, VABSDIFF, v_acc, v_1, v_2);
  vbx_sync();
  return v_acc[0];
}

int compare_accumulated_uhalf(vbx_uhalf_t *v_1, vbx_uhalf_t *v_2){
  vbx_sync();
  return v_1[0] - v_2[0];
}

int compare_accumulated_ubyte(vbx_ubyte_t *v_1, vbx_ubyte_t *v_2){
  vbx_sync();
  return v_1[0] - v_2[0];
}

int compare_accumulated_uword(vbx_uword_t *v_1, vbx_uword_t *v_2){
  vbx_sync();
  return v_1[0] - v_2[0];
}

int compare_accumulated_half(vbx_half_t *v_1, vbx_half_t *v_2){
  vbx_sync();
  return v_1[0] - v_2[0];
}

int compare_accumulated_byte(vbx_byte_t *v_1, vbx_byte_t *v_2){
  vbx_sync();
  return v_1[0] - v_2[0];
}

int compare_accumulated_word(vbx_word_t *v_1, vbx_word_t *v_2){
  vbx_sync();
  return v_1[0] - v_2[0];
}

// function version
int test_vec_function()
{
	int N = 8;
	int errors = 0;

	vbx_uhalf_t *v_uhalf_out1 = (vbx_uhalf_t *)vbx_sp_malloc( N*sizeof(vbx_uhalf_t) );
	vbx_uhalf_t *v_uhalf_out2 = (vbx_uhalf_t *)vbx_sp_malloc( N*sizeof(vbx_uhalf_t) );
	vbx_uhalf_t *v_uhalf_in1 = (vbx_uhalf_t *)vbx_sp_malloc( N*sizeof(vbx_uhalf_t) );
	vbx_uhalf_t *v_uhalf_in2 = (vbx_uhalf_t *)vbx_sp_malloc( N*sizeof(vbx_uhalf_t) );
	vbx_uhalf_t *v_uhalf_acc = (vbx_uhalf_t *)vbx_sp_malloc( sizeof(vbx_uhalf_t) );

	vbx_uword_t *v_uword_out1 = (vbx_uword_t *)vbx_sp_malloc( N*sizeof(vbx_uword_t) );
	vbx_uword_t *v_uword_out2 = (vbx_uword_t *)vbx_sp_malloc( N*sizeof(vbx_uword_t) );
	vbx_uword_t *v_uword_in1 = (vbx_uword_t *)vbx_sp_malloc( N*sizeof(vbx_uword_t) );
	vbx_uword_t *v_uword_in2 = (vbx_uword_t *)vbx_sp_malloc( N*sizeof(vbx_uword_t) );
	vbx_uword_t *v_uword_acc = (vbx_uword_t *)vbx_sp_malloc( sizeof(vbx_uword_t) );

	vbx_ubyte_t *v_ubyte_out1 = (vbx_ubyte_t *)vbx_sp_malloc( N*sizeof(vbx_ubyte_t) );
	vbx_ubyte_t *v_ubyte_out2 = (vbx_ubyte_t *)vbx_sp_malloc( N*sizeof(vbx_ubyte_t) );
	vbx_ubyte_t *v_ubyte_in1 = (vbx_ubyte_t *)vbx_sp_malloc( N*sizeof(vbx_ubyte_t) );
	vbx_ubyte_t *v_ubyte_in2 = (vbx_ubyte_t *)vbx_sp_malloc( N*sizeof(vbx_ubyte_t) );
	vbx_ubyte_t *v_ubyte_acc = (vbx_ubyte_t *)vbx_sp_malloc( sizeof(vbx_ubyte_t) );

	vbx_half_t *v_half_out1 = (vbx_half_t *)vbx_sp_malloc( N*sizeof(vbx_half_t) );
	vbx_half_t *v_half_out2 = (vbx_half_t *)vbx_sp_malloc( N*sizeof(vbx_half_t) );
	vbx_half_t *v_half_in1 = (vbx_half_t *)vbx_sp_malloc( N*sizeof(vbx_half_t) );
	vbx_half_t *v_half_in2 = (vbx_half_t *)vbx_sp_malloc( N*sizeof(vbx_half_t) );
	vbx_half_t *v_half_acc = (vbx_half_t *)vbx_sp_malloc( sizeof(vbx_half_t) );

	vbx_word_t *v_word_out1 = (vbx_word_t *)vbx_sp_malloc( N*sizeof(vbx_word_t) );
	vbx_word_t *v_word_out2 = (vbx_word_t *)vbx_sp_malloc( N*sizeof(vbx_word_t) );
	vbx_word_t *v_word_in1 = (vbx_word_t *)vbx_sp_malloc( N*sizeof(vbx_word_t) );
	vbx_word_t *v_word_in2 = (vbx_word_t *)vbx_sp_malloc( N*sizeof(vbx_word_t) );
	vbx_word_t *v_word_acc = (vbx_word_t *)vbx_sp_malloc( sizeof(vbx_word_t) );

	vbx_byte_t *v_byte_out1 = (vbx_byte_t *)vbx_sp_malloc( N*sizeof(vbx_byte_t) );
	vbx_byte_t *v_byte_out2 = (vbx_byte_t *)vbx_sp_malloc( N*sizeof(vbx_byte_t) );
	vbx_byte_t *v_byte_in1 = (vbx_byte_t *)vbx_sp_malloc( N*sizeof(vbx_byte_t) );
	vbx_byte_t *v_byte_in2 = (vbx_byte_t *)vbx_sp_malloc( N*sizeof(vbx_byte_t) );
	vbx_byte_t *v_byte_acc = (vbx_byte_t *)vbx_sp_malloc( sizeof(vbx_byte_t) );

	vbx_set_vl( N );

  //initialize ops
	vbx( SEH, VAND, (vbx_half_t *)v_ubyte_in1,       0xf, 0 );
	vbx( SEH, VAND, (vbx_half_t *)v_uhalf_in1,       0xf, 0 );
	vbx( SEH, VAND, (vbx_half_t *)v_uword_in1,       0xf, 0 );
	vbx( SEH, VAND, (vbx_half_t *)v_byte_in1,       0xf, 0 );
	vbx( SEH, VAND, (vbx_half_t *)v_half_in1,       0xf, 0 );
	vbx( SEH, VAND, (vbx_half_t *)v_word_in1,       0xf, 0 );

	vbx( SEH, VMUL, (vbx_half_t *)v_ubyte_in2, 0x00101010, 0 );
	vbx( SEH, VMUL, (vbx_half_t *)v_uhalf_in2, 0x00101010, 0 );
	vbx( SEH, VMUL, (vbx_half_t *)v_uword_in2, 0x00101010, 0 );
	vbx( SEH, VMUL, (vbx_half_t *)v_byte_in2, 0x00101010, 0 );
	vbx( SEH, VMUL, (vbx_half_t *)v_half_in2, 0x00101010, 0 );
	vbx( SEH, VMUL, (vbx_half_t *)v_word_in2, 0x00101010, 0 );

	vbx_sync();

  //-------------------------------------------------
	vbx_enum_t *v_enum = 0;

#if 1 //enable tests
	vbx( VVB, VABSDIFF, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VABSDIFF, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVB, VOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVB, VROTR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VROTR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVB, VCMV_GEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VCMV_GEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBB, VSUBB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VSUBB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBB, VAND, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VAND, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBB, VROTL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VROTL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBB, VCMV_LTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVB, VCMV_LTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBS, VADDC, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VADDC, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBS, VMULFXP, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VMULFXP, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBS, VSHR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VSHR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBS, VCMV_GTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VCMV_GTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBS, VSUB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VSUB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBS, VMULHI, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VMULHI, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBS, VSHL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VSHL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBS, VCMV_LEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VCMV_LEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBS, VCMV_NZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBS, VCMV_NZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBU, VADD, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VADD, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBU, VMUL, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VMUL, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBU, VXOR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VXOR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBU, VMOV, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VMOV, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBU, VCMV_Z, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VCMV_Z, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBU, VABSDIFF, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VABSDIFF, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBU, VOR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VOR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBU, VROTR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VROTR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBBU, VCMV_GEZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBU, VCMV_GEZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBH, VSUBB, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBH, VSUBB, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBH, VAND, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBH, VAND, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBH, VROTL, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBH, VROTL, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBH, VCMV_LTZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBH, VCMV_LTZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHS, VADDC, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBHS, VADDC, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHS, VMULFXP, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBHS, VMULFXP, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHS, VSHR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBHS, VSHR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHS, VCMV_GTZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBHS, VCMV_GTZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHU, VSUB, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBHU, VSUB, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHU, VMULHI, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBHU, VMULHI, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHU, VSHL, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBHU, VSHL, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHU, VCMV_LEZ, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBHU, VCMV_LEZ, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBHU, VCMV_NZ, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBHU, VCMV_NZ, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBW, VADD, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBW, VADD, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBW, VMUL, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBW, VMUL, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBW, VXOR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBW, VXOR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBW, VMOV, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBW, VMOV, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBW, VCMV_Z, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBW, VCMV_Z, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWS, VABSDIFF, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBWS, VABSDIFF, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWS, VOR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBWS, VOR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWS, VROTR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBWS, VROTR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWS, VCMV_GEZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm( VVBWS, VCMV_GEZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWU, VSUBB, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBWU, VSUBB, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWU, VAND, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBWU, VAND, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWU, VROTL, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBWU, VROTL, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVBWU, VCMV_LTZ, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm( VVBWU, VCMV_LTZ, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHB, VADDC, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHB, VADDC, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHB, VMULFXP, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHB, VMULFXP, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHB, VSHR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHB, VSHR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHB, VCMV_GTZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHB, VCMV_GTZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBS, VSUB, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHBS, VSUB, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBS, VMULHI, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHBS, VMULHI, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBS, VSHL, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHBS, VSHL, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBS, VCMV_LEZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHBS, VCMV_LEZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBS, VCMV_NZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHBS, VCMV_NZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBU, VADD, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHBU, VADD, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBU, VMUL, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHBU, VMUL, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBU, VXOR, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHBU, VXOR, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBU, VMOV, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHBU, VMOV, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHBU, VCMV_Z, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHBU, VCMV_Z, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVH, VABSDIFF, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VABSDIFF, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVH, VOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVH, VROTR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VROTR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVH, VCMV_GEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VCMV_GEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHH, VSUBB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VSUBB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHH, VAND, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VAND, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHH, VROTL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VROTL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHH, VCMV_LTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVH, VCMV_LTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHS, VADDC, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VADDC, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHS, VMULFXP, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VMULFXP, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHS, VSHR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VSHR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHS, VCMV_GTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VCMV_GTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHS, VSUB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VSUB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHS, VMULHI, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VMULHI, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHS, VSHL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VSHL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHS, VCMV_LEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VCMV_LEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHS, VCMV_NZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHS, VCMV_NZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHU, VADD, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VADD, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHU, VMUL, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VMUL, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHU, VXOR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VXOR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHU, VMOV, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VMOV, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHU, VCMV_Z, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VCMV_Z, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHU, VABSDIFF, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VABSDIFF, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHU, VOR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VOR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHU, VROTR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VROTR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHHU, VCMV_GEZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHU, VCMV_GEZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHW, VSUBB, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHW, VSUBB, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHW, VAND, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHW, VAND, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHW, VROTL, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHW, VROTL, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHW, VCMV_LTZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHW, VCMV_LTZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWS, VADDC, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHWS, VADDC, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWS, VMULFXP, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHWS, VMULFXP, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWS, VSHR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHWS, VSHR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWS, VCMV_GTZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm( VVHWS, VCMV_GTZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWU, VSUB, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHWU, VSUB, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWU, VMULHI, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHWU, VMULHI, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWU, VSHL, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHWU, VSHL, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWU, VCMV_LEZ, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHWU, VCMV_LEZ, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVHWU, VCMV_NZ, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm( VVHWU, VCMV_NZ, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWB, VADD, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWB, VADD, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWB, VMUL, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWB, VMUL, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWB, VXOR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWB, VXOR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWB, VMOV, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWB, VMOV, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWB, VCMV_Z, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWB, VCMV_Z, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBS, VABSDIFF, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWBS, VABSDIFF, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBS, VOR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWBS, VOR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBS, VROTR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWBS, VROTR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBS, VCMV_GEZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWBS, VCMV_GEZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBU, VSUBB, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWBU, VSUBB, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBU, VAND, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWBU, VAND, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBU, VROTL, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWBU, VROTL, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWBU, VCMV_LTZ, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWBU, VCMV_LTZ, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWH, VADDC, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWH, VADDC, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWH, VMULFXP, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWH, VMULFXP, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWH, VSHR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWH, VSHR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWH, VCMV_GTZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWH, VCMV_GTZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHS, VSUB, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWHS, VSUB, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHS, VMULHI, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWHS, VMULHI, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHS, VSHL, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWHS, VSHL, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHS, VCMV_LEZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWHS, VCMV_LEZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHS, VCMV_NZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWHS, VCMV_NZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHU, VADD, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWHU, VADD, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHU, VMUL, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWHU, VMUL, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHU, VXOR, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWHU, VXOR, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHU, VMOV, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWHU, VMOV, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWHU, VCMV_Z, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWHU, VCMV_Z, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVW, VABSDIFF, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VABSDIFF, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVW, VOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVW, VROTR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VROTR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVW, VCMV_GEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VCMV_GEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWW, VSUBB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VSUBB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWW, VAND, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VAND, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWW, VROTL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VROTL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWW, VCMV_LTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVW, VCMV_LTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWS, VADDC, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VADDC, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWS, VMULFXP, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VMULFXP, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWS, VSHR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VSHR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWS, VCMV_GTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VCMV_GTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWS, VSUB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VSUB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWS, VMULHI, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VMULHI, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWS, VSHL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VSHL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWS, VCMV_LEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VCMV_LEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWS, VCMV_NZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm( VVWS, VCMV_NZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWU, VADD, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VADD, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWU, VMUL, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VMUL, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWU, VXOR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VXOR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWU, VMOV, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VMOV, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWU, VCMV_Z, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VCMV_Z, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWU, VABSDIFF, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VABSDIFF, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWU, VOR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VOR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWU, VROTR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VROTR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VVWWU, VCMV_GEZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm( VVWU, VCMV_GEZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVB, VSUBB, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VSUBB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVB, VAND, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VAND, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVB, VROTL, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VROTL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVB, VCMV_LTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VCMV_LTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBB, VADDC, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VADDC, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBB, VMULFXP, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VMULFXP, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBB, VSHR, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VSHR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBB, VCMV_GTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVB, VCMV_GTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBS, VSUB, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VSUB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBS, VMULHI, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VMULHI, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBS, VSHL, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VSHL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBS, VCMV_LEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VCMV_LEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBS, VCMV_NZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VCMV_NZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBS, VADD, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VADD, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBS, VMUL, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VMUL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBS, VXOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VXOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBS, VMOV, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VMOV, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBS, VCMV_Z, v_byte_out1, 8, v_byte_in2 );
	vbxasm( SVBS, VCMV_Z, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBU, VABSDIFF, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VABSDIFF, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBU, VOR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VOR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBU, VROTR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VROTR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBU, VCMV_GEZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VCMV_GEZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBU, VSUBB, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VSUBB, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBU, VAND, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VAND, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBU, VROTL, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VROTL, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBBU, VCMV_LTZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm( SVBU, VCMV_LTZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBH, VADDC, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBH, VADDC, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBH, VMULFXP, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBH, VMULFXP, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBH, VSHR, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBH, VSHR, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBH, VCMV_GTZ, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBH, VCMV_GTZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHS, VSUB, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBHS, VSUB, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHS, VMULHI, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBHS, VMULHI, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHS, VSHL, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBHS, VSHL, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHS, VCMV_LEZ, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBHS, VCMV_LEZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHS, VCMV_NZ, v_half_out1, 8, v_byte_in2 );
	vbxasm( SVBHS, VCMV_NZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHU, VADD, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm( SVBHU, VADD, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHU, VMUL, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm( SVBHU, VMUL, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHU, VXOR, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm( SVBHU, VXOR, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHU, VMOV, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm( SVBHU, VMOV, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBHU, VCMV_Z, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm( SVBHU, VCMV_Z, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBW, VABSDIFF, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBW, VABSDIFF, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBW, VOR, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBW, VOR, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBW, VROTR, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBW, VROTR, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBW, VCMV_GEZ, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBW, VCMV_GEZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWS, VSUBB, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBWS, VSUBB, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWS, VAND, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBWS, VAND, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWS, VROTL, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBWS, VROTL, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWS, VCMV_LTZ, v_word_out1, 8, v_byte_in2 );
	vbxasm( SVBWS, VCMV_LTZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWU, VADDC, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm( SVBWU, VADDC, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWU, VMULFXP, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm( SVBWU, VMULFXP, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWU, VSHR, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm( SVBWU, VSHR, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVBWU, VCMV_GTZ, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm( SVBWU, VCMV_GTZ, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHB, VSUB, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHB, VSUB, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHB, VMULHI, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHB, VMULHI, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHB, VSHL, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHB, VSHL, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHB, VCMV_LEZ, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHB, VCMV_LEZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHB, VCMV_NZ, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHB, VCMV_NZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBS, VADD, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHBS, VADD, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBS, VMUL, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHBS, VMUL, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBS, VXOR, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHBS, VXOR, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBS, VMOV, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHBS, VMOV, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBS, VCMV_Z, v_byte_out1, 8, v_half_in2 );
	vbxasm( SVHBS, VCMV_Z, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBU, VABSDIFF, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm( SVHBU, VABSDIFF, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBU, VOR, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm( SVHBU, VOR, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBU, VROTR, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm( SVHBU, VROTR, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHBU, VCMV_GEZ, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm( SVHBU, VCMV_GEZ, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVH, VSUBB, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VSUBB, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVH, VAND, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VAND, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVH, VROTL, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VROTL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVH, VCMV_LTZ, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VCMV_LTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHH, VADDC, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VADDC, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHH, VMULFXP, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VMULFXP, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHH, VSHR, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VSHR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHH, VCMV_GTZ, v_half_out1, 8, v_half_in2 );
	vbxasm( SVH, VCMV_GTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHS, VSUB, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VSUB, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHS, VMULHI, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VMULHI, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHS, VSHL, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VSHL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHS, VCMV_LEZ, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VCMV_LEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHS, VCMV_NZ, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VCMV_NZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHS, VADD, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VADD, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHS, VMUL, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VMUL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHS, VXOR, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VXOR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHS, VMOV, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VMOV, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHS, VCMV_Z, v_half_out1, 8, v_half_in2 );
	vbxasm( SVHS, VCMV_Z, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHU, VABSDIFF, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VABSDIFF, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHU, VOR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VOR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHU, VROTR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VROTR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHU, VCMV_GEZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VCMV_GEZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHU, VSUBB, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VSUBB, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHU, VAND, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VAND, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHU, VROTL, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VROTL, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHHU, VCMV_LTZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm( SVHU, VCMV_LTZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHW, VADDC, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHW, VADDC, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHW, VMULFXP, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHW, VMULFXP, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHW, VSHR, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHW, VSHR, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHW, VCMV_GTZ, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHW, VCMV_GTZ, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWS, VSUB, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHWS, VSUB, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWS, VMULHI, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHWS, VMULHI, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWS, VSHL, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHWS, VSHL, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWS, VCMV_LEZ, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHWS, VCMV_LEZ, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWS, VCMV_NZ, v_word_out1, 8, v_half_in2 );
	vbxasm( SVHWS, VCMV_NZ, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWU, VADD, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm( SVHWU, VADD, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWU, VMUL, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm( SVHWU, VMUL, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWU, VXOR, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm( SVHWU, VXOR, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWU, VMOV, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm( SVHWU, VMOV, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVHWU, VCMV_Z, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm( SVHWU, VCMV_Z, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWB, VABSDIFF, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWB, VABSDIFF, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWB, VOR, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWB, VOR, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWB, VROTR, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWB, VROTR, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWB, VCMV_GEZ, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWB, VCMV_GEZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBS, VSUBB, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWBS, VSUBB, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBS, VAND, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWBS, VAND, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBS, VROTL, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWBS, VROTL, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBS, VCMV_LTZ, v_byte_out1, 8, v_word_in2 );
	vbxasm( SVWBS, VCMV_LTZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBU, VADDC, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm( SVWBU, VADDC, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBU, VMULFXP, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm( SVWBU, VMULFXP, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBU, VSHR, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm( SVWBU, VSHR, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWBU, VCMV_GTZ, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm( SVWBU, VCMV_GTZ, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWH, VSUB, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWH, VSUB, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWH, VMULHI, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWH, VMULHI, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWH, VSHL, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWH, VSHL, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWH, VCMV_LEZ, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWH, VCMV_LEZ, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWH, VCMV_NZ, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWH, VCMV_NZ, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHS, VADD, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWHS, VADD, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHS, VMUL, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWHS, VMUL, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHS, VXOR, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWHS, VXOR, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHS, VMOV, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWHS, VMOV, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHS, VCMV_Z, v_half_out1, 8, v_word_in2 );
	vbxasm( SVWHS, VCMV_Z, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHU, VABSDIFF, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm( SVWHU, VABSDIFF, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHU, VOR, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm( SVWHU, VOR, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHU, VROTR, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm( SVWHU, VROTR, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWHU, VCMV_GEZ, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm( SVWHU, VCMV_GEZ, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVW, VSUBB, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VSUBB, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVW, VAND, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VAND, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVW, VROTL, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VROTL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVW, VCMV_LTZ, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VCMV_LTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWW, VADDC, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VADDC, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWW, VMULFXP, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VMULFXP, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWW, VSHR, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VSHR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWW, VCMV_GTZ, v_word_out1, 8, v_word_in2 );
	vbxasm( SVW, VCMV_GTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWS, VSUB, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VSUB, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWS, VMULHI, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VMULHI, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWS, VSHL, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VSHL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWS, VCMV_LEZ, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VCMV_LEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWS, VCMV_NZ, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VCMV_NZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWS, VADD, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VADD, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWS, VMUL, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VMUL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWS, VXOR, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VXOR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWS, VMOV, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VMOV, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWS, VCMV_Z, v_word_out1, 8, v_word_in2 );
	vbxasm( SVWS, VCMV_Z, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWU, VABSDIFF, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VABSDIFF, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWU, VOR, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VOR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWU, VROTR, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VROTR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWU, VCMV_GEZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VCMV_GEZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWU, VSUBB, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VSUBB, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWU, VAND, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VAND, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWU, VROTL, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VROTL, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SVWWU, VCMV_LTZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm( SVWU, VCMV_LTZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEB, VADDC, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VADDC, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEB, VMULFXP, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VMULFXP, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEB, VSHR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VSHR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEB, VCMV_GTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VCMV_GTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBB, VSUB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VSUB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBB, VMULHI, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VMULHI, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBB, VSHL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VSHL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBB, VCMV_LEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VCMV_LEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBB, VCMV_NZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEB, VCMV_NZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBS, VADD, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VADD, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBS, VMUL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VMUL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBS, VXOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VXOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBS, VMOV, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VMOV, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBS, VCMV_Z, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VCMV_Z, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBS, VABSDIFF, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VABSDIFF, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBS, VOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBS, VROTR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VROTR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBS, VCMV_GEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm( VEBS, VCMV_GEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBU, VSUBB, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VSUBB, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBU, VAND, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VAND, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBU, VROTL, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VROTL, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBU, VCMV_LTZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VCMV_LTZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBU, VADDC, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VADDC, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBU, VMULFXP, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VMULFXP, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBU, VSHR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VSHR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEBBU, VCMV_GTZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm( VEBU, VCMV_GTZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEH, VSUB, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VSUB, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEH, VMULHI, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VMULHI, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEH, VSHL, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VSHL, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEH, VCMV_LEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VCMV_LEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEH, VCMV_NZ, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VCMV_NZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHH, VADD, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VADD, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHH, VMUL, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VMUL, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHH, VXOR, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VXOR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHH, VMOV, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VMOV, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHH, VCMV_Z, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEH, VCMV_Z, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHS, VABSDIFF, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VABSDIFF, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHS, VOR, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VOR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHS, VROTR, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VROTR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHS, VCMV_GEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VCMV_GEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHS, VSUBB, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VSUBB, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHS, VAND, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VAND, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHS, VROTL, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VROTL, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHS, VCMV_LTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm( VEHS, VCMV_LTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHU, VADDC, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VADDC, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHU, VMULFXP, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VMULFXP, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHU, VSHR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VSHR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHU, VCMV_GTZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VCMV_GTZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHU, VSUB, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VSUB, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHU, VMULHI, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VMULHI, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHU, VSHL, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VSHL, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHU, VCMV_LEZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VCMV_LEZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEHHU, VCMV_NZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm( VEHU, VCMV_NZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEW, VADD, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VADD, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEW, VMUL, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VMUL, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEW, VXOR, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VXOR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEW, VMOV, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VMOV, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEW, VCMV_Z, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VCMV_Z, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWW, VABSDIFF, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VABSDIFF, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWW, VOR, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VOR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWW, VROTR, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VROTR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWW, VCMV_GEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEW, VCMV_GEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWS, VSUBB, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VSUBB, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWS, VAND, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VAND, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWS, VROTL, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VROTL, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWS, VCMV_LTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VCMV_LTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWS, VADDC, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VADDC, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWS, VMULFXP, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VMULFXP, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWS, VSHR, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VSHR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWS, VCMV_GTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm( VEWS, VCMV_GTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWU, VSUB, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VSUB, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWU, VMULHI, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VMULHI, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWU, VSHL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VSHL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWU, VCMV_LEZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VCMV_LEZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWU, VCMV_NZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VCMV_NZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWU, VADD, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VADD, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWU, VMUL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VMUL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWU, VXOR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VXOR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWU, VMOV, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VMOV, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( VEWWU, VCMV_Z, v_uword_out1, v_uword_in1, v_enum );
	vbxasm( VEWU, VCMV_Z, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEB, VABSDIFF, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VABSDIFF, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEB, VOR, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VOR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEB, VROTR, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VROTR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEB, VCMV_GEZ, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VCMV_GEZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBB, VSUBB, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VSUBB, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBB, VAND, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VAND, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBB, VROTL, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VROTL, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBB, VCMV_LTZ, v_byte_out1, 8, v_enum );
	vbxasm( SEB, VCMV_LTZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBS, VADDC, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VADDC, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBS, VMULFXP, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VMULFXP, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBS, VSHR, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VSHR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBS, VCMV_GTZ, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VCMV_GTZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBS, VSUB, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VSUB, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBS, VMULHI, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VMULHI, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBS, VSHL, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VSHL, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBS, VCMV_LEZ, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VCMV_LEZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBS, VCMV_NZ, v_byte_out1, 8, v_enum );
	vbxasm( SEBS, VCMV_NZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBU, VADD, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VADD, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBU, VMUL, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VMUL, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBU, VXOR, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VXOR, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBU, VMOV, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VMOV, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBU, VCMV_Z, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VCMV_Z, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBU, VABSDIFF, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VABSDIFF, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBU, VOR, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VOR, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBU, VROTR, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VROTR, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEBBU, VCMV_GEZ, v_ubyte_out1, 8, v_enum );
	vbxasm( SEBU, VCMV_GEZ, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEH, VSUBB, v_half_out1, 8, v_enum );
	vbxasm( SEH, VSUBB, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEH, VAND, v_half_out1, 8, v_enum );
	vbxasm( SEH, VAND, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEH, VROTL, v_half_out1, 8, v_enum );
	vbxasm( SEH, VROTL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEH, VCMV_LTZ, v_half_out1, 8, v_enum );
	vbxasm( SEH, VCMV_LTZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHH, VADDC, v_half_out1, 8, v_enum );
	vbxasm( SEH, VADDC, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHH, VMULFXP, v_half_out1, 8, v_enum );
	vbxasm( SEH, VMULFXP, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHH, VSHR, v_half_out1, 8, v_enum );
	vbxasm( SEH, VSHR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHH, VCMV_GTZ, v_half_out1, 8, v_enum );
	vbxasm( SEH, VCMV_GTZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHS, VSUB, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VSUB, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHS, VMULHI, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VMULHI, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHS, VSHL, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VSHL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHS, VCMV_LEZ, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VCMV_LEZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHS, VCMV_NZ, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VCMV_NZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHS, VADD, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VADD, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHS, VMUL, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VMUL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHS, VXOR, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VXOR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHS, VMOV, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VMOV, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHS, VCMV_Z, v_half_out1, 8, v_enum );
	vbxasm( SEHS, VCMV_Z, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHU, VABSDIFF, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VABSDIFF, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHU, VOR, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VOR, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHU, VROTR, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VROTR, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHU, VCMV_GEZ, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VCMV_GEZ, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHU, VSUBB, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VSUBB, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHU, VAND, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VAND, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHU, VROTL, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VROTL, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEHHU, VCMV_LTZ, v_uhalf_out1, 8, v_enum );
	vbxasm( SEHU, VCMV_LTZ, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEW, VADDC, v_word_out1, 8, v_enum );
	vbxasm( SEW, VADDC, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEW, VMULFXP, v_word_out1, 8, v_enum );
	vbxasm( SEW, VMULFXP, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEW, VSHR, v_word_out1, 8, v_enum );
	vbxasm( SEW, VSHR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEW, VCMV_GTZ, v_word_out1, 8, v_enum );
	vbxasm( SEW, VCMV_GTZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWW, VSUB, v_word_out1, 8, v_enum );
	vbxasm( SEW, VSUB, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWW, VMULHI, v_word_out1, 8, v_enum );
	vbxasm( SEW, VMULHI, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWW, VSHL, v_word_out1, 8, v_enum );
	vbxasm( SEW, VSHL, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWW, VCMV_LEZ, v_word_out1, 8, v_enum );
	vbxasm( SEW, VCMV_LEZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWW, VCMV_NZ, v_word_out1, 8, v_enum );
	vbxasm( SEW, VCMV_NZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWS, VADD, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VADD, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWS, VMUL, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VMUL, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWS, VXOR, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VXOR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWS, VMOV, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VMOV, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWS, VCMV_Z, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VCMV_Z, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWS, VABSDIFF, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VABSDIFF, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWS, VOR, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VOR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWS, VROTR, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VROTR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWS, VCMV_GEZ, v_word_out1, 8, v_enum );
	vbxasm( SEWS, VCMV_GEZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWU, VSUBB, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VSUBB, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWU, VAND, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VAND, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWU, VROTL, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VROTL, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWU, VCMV_LTZ, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VCMV_LTZ, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWU, VADDC, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VADDC, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWU, VMULFXP, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VMULFXP, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWU, VSHR, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VSHR, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx( SEWWU, VCMV_GTZ, v_uword_out1, 8, v_enum );
	vbxasm( SEWU, VCMV_GTZ, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVB, VSUB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VSUB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVB, VMULHI, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VMULHI, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVB, VSHL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VSHL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVB, VCMV_LEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VCMV_LEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVB, VCMV_NZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VCMV_NZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBB, VADD, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VADD, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBB, VMUL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VMUL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBB, VXOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VXOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBB, VMOV, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VMOV, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBB, VCMV_Z, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVB, VCMV_Z, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBS, VABSDIFF, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VABSDIFF, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBS, VOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBS, VROTR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VROTR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBS, VCMV_GEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VCMV_GEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBS, VSUBB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VSUBB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBS, VAND, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VAND, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBS, VROTL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VROTL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBS, VCMV_LTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBS, VCMV_LTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBU, VADDC, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VADDC, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBU, VMULFXP, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VMULFXP, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBU, VSHR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VSHR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBU, VCMV_GTZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VCMV_GTZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBU, VSUB, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VSUB, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBU, VMULHI, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VMULHI, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBU, VSHL, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VSHL, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBU, VCMV_LEZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VCMV_LEZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBBU, VCMV_NZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBU, VCMV_NZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBH, VADD, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBH, VADD, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBH, VMUL, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBH, VMUL, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBH, VXOR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBH, VXOR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBH, VMOV, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBH, VMOV, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBH, VCMV_Z, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBH, VCMV_Z, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHS, VABSDIFF, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBHS, VABSDIFF, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHS, VOR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBHS, VOR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHS, VROTR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBHS, VROTR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHS, VCMV_GEZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBHS, VCMV_GEZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHU, VSUBB, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBHU, VSUBB, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHU, VAND, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBHU, VAND, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHU, VROTL, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBHU, VROTL, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBHU, VCMV_LTZ, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBHU, VCMV_LTZ, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBW, VADDC, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBW, VADDC, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBW, VMULFXP, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBW, VMULFXP, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBW, VSHR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBW, VSHR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBW, VCMV_GTZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBW, VCMV_GTZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWS, VSUB, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBWS, VSUB, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWS, VMULHI, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBWS, VMULHI, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWS, VSHL, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBWS, VSHL, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWS, VCMV_LEZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBWS, VCMV_LEZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWS, VCMV_NZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc( VVBWS, VCMV_NZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWU, VADD, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBWU, VADD, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWU, VMUL, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBWU, VMUL, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWU, VXOR, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBWU, VXOR, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWU, VMOV, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBWU, VMOV, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVBWU, VCMV_Z, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc( VVBWU, VCMV_Z, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHB, VABSDIFF, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHB, VABSDIFF, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHB, VOR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHB, VOR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHB, VROTR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHB, VROTR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHB, VCMV_GEZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHB, VCMV_GEZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBS, VSUBB, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHBS, VSUBB, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBS, VAND, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHBS, VAND, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBS, VROTL, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHBS, VROTL, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBS, VCMV_LTZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHBS, VCMV_LTZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBU, VADDC, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHBU, VADDC, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBU, VMULFXP, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHBU, VMULFXP, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBU, VSHR, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHBU, VSHR, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHBU, VCMV_GTZ, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHBU, VCMV_GTZ, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVH, VSUB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VSUB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVH, VMULHI, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VMULHI, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVH, VSHL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VSHL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVH, VCMV_LEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VCMV_LEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVH, VCMV_NZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VCMV_NZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHH, VADD, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VADD, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHH, VMUL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VMUL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHH, VXOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VXOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHH, VMOV, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VMOV, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHH, VCMV_Z, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVH, VCMV_Z, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHS, VABSDIFF, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VABSDIFF, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHS, VOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHS, VROTR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VROTR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHS, VCMV_GEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VCMV_GEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHS, VSUBB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VSUBB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHS, VAND, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VAND, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHS, VROTL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VROTL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHS, VCMV_LTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHS, VCMV_LTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHU, VADDC, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VADDC, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHU, VMULFXP, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VMULFXP, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHU, VSHR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VSHR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHU, VCMV_GTZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VCMV_GTZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHU, VSUB, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VSUB, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHU, VMULHI, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VMULHI, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHU, VSHL, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VSHL, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHU, VCMV_LEZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VCMV_LEZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHHU, VCMV_NZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHU, VCMV_NZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHW, VADD, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHW, VADD, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHW, VMUL, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHW, VMUL, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHW, VXOR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHW, VXOR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHW, VMOV, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHW, VMOV, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHW, VCMV_Z, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHW, VCMV_Z, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWS, VABSDIFF, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHWS, VABSDIFF, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWS, VOR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHWS, VOR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWS, VROTR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHWS, VROTR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWS, VCMV_GEZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc( VVHWS, VCMV_GEZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWU, VSUBB, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHWU, VSUBB, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWU, VAND, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHWU, VAND, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWU, VROTL, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHWU, VROTL, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVHWU, VCMV_LTZ, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc( VVHWU, VCMV_LTZ, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWB, VADDC, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWB, VADDC, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWB, VMULFXP, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWB, VMULFXP, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWB, VSHR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWB, VSHR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWB, VCMV_GTZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWB, VCMV_GTZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBS, VSUB, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWBS, VSUB, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBS, VMULHI, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWBS, VMULHI, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBS, VSHL, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWBS, VSHL, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBS, VCMV_LEZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWBS, VCMV_LEZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBS, VCMV_NZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWBS, VCMV_NZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBU, VADD, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWBU, VADD, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBU, VMUL, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWBU, VMUL, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBU, VXOR, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWBU, VXOR, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBU, VMOV, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWBU, VMOV, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWBU, VCMV_Z, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWBU, VCMV_Z, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWH, VABSDIFF, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWH, VABSDIFF, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWH, VOR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWH, VOR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWH, VROTR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWH, VROTR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWH, VCMV_GEZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWH, VCMV_GEZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHS, VSUBB, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWHS, VSUBB, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHS, VAND, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWHS, VAND, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHS, VROTL, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWHS, VROTL, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHS, VCMV_LTZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWHS, VCMV_LTZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHU, VADDC, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWHU, VADDC, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHU, VMULFXP, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWHU, VMULFXP, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHU, VSHR, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWHU, VSHR, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWHU, VCMV_GTZ, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWHU, VCMV_GTZ, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVW, VSUB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VSUB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVW, VMULHI, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VMULHI, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVW, VSHL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VSHL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVW, VCMV_LEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VCMV_LEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVW, VCMV_NZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VCMV_NZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWW, VADD, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VADD, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWW, VMUL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VMUL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWW, VXOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VXOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWW, VMOV, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VMOV, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWW, VCMV_Z, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVW, VCMV_Z, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWS, VABSDIFF, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VABSDIFF, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWS, VOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWS, VROTR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VROTR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWS, VCMV_GEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VCMV_GEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWS, VSUBB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VSUBB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWS, VAND, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VAND, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWS, VROTL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VROTL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWS, VCMV_LTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc( VVWS, VCMV_LTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWU, VADDC, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VADDC, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWU, VMULFXP, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VMULFXP, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWU, VSHR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VSHR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWU, VCMV_GTZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VCMV_GTZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWU, VSUB, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VSUB, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWU, VMULHI, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VMULHI, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWU, VSHL, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VSHL, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWU, VCMV_LEZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VCMV_LEZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VVWWU, VCMV_NZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc( VVWU, VCMV_NZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVB, VADD, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VADD, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVB, VMUL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VMUL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVB, VXOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VXOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVB, VMOV, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VMOV, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVB, VCMV_Z, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VCMV_Z, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBB, VABSDIFF, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VABSDIFF, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBB, VOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBB, VROTR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VROTR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBB, VCMV_GEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVB, VCMV_GEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBS, VSUBB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VSUBB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBS, VAND, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VAND, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBS, VROTL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VROTL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBS, VCMV_LTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VCMV_LTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBS, VADDC, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VADDC, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBS, VMULFXP, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VMULFXP, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBS, VSHR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VSHR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBS, VCMV_GTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBS, VCMV_GTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBU, VSUB, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VSUB, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBU, VMULHI, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VMULHI, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBU, VSHL, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VSHL, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBU, VCMV_LEZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VCMV_LEZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBU, VCMV_NZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VCMV_NZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBU, VADD, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VADD, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBU, VMUL, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VMUL, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBU, VXOR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VXOR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBU, VMOV, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VMOV, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBBU, VCMV_Z, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBU, VCMV_Z, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBH, VABSDIFF, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBH, VABSDIFF, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBH, VOR, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBH, VOR, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBH, VROTR, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBH, VROTR, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBH, VCMV_GEZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBH, VCMV_GEZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHS, VSUBB, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBHS, VSUBB, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHS, VAND, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBHS, VAND, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHS, VROTL, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBHS, VROTL, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHS, VCMV_LTZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBHS, VCMV_LTZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHU, VADDC, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBHU, VADDC, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHU, VMULFXP, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBHU, VMULFXP, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHU, VSHR, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBHU, VSHR, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBHU, VCMV_GTZ, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBHU, VCMV_GTZ, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBW, VSUB, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBW, VSUB, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBW, VMULHI, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBW, VMULHI, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBW, VSHL, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBW, VSHL, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBW, VCMV_LEZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBW, VCMV_LEZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBW, VCMV_NZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBW, VCMV_NZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWS, VADD, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBWS, VADD, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWS, VMUL, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBWS, VMUL, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWS, VXOR, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBWS, VXOR, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWS, VMOV, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBWS, VMOV, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWS, VCMV_Z, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc( SVBWS, VCMV_Z, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWU, VABSDIFF, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBWU, VABSDIFF, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWU, VOR, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBWU, VOR, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWU, VROTR, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBWU, VROTR, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVBWU, VCMV_GEZ, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc( SVBWU, VCMV_GEZ, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHB, VSUBB, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHB, VSUBB, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHB, VAND, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHB, VAND, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHB, VROTL, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHB, VROTL, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHB, VCMV_LTZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHB, VCMV_LTZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBS, VADDC, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHBS, VADDC, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBS, VMULFXP, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHBS, VMULFXP, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBS, VSHR, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHBS, VSHR, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBS, VCMV_GTZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc( SVHBS, VCMV_GTZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBU, VSUB, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHBU, VSUB, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBU, VMULHI, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHBU, VMULHI, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBU, VSHL, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHBU, VSHL, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBU, VCMV_LEZ, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHBU, VCMV_LEZ, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHBU, VCMV_NZ, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHBU, VCMV_NZ, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVH, VADD, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VADD, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVH, VMUL, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VMUL, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVH, VXOR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VXOR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVH, VMOV, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VMOV, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVH, VCMV_Z, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VCMV_Z, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHH, VABSDIFF, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VABSDIFF, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHH, VOR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VOR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHH, VROTR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VROTR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHH, VCMV_GEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVH, VCMV_GEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHS, VSUBB, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VSUBB, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHS, VAND, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VAND, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHS, VROTL, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VROTL, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHS, VCMV_LTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VCMV_LTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHS, VADDC, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VADDC, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHS, VMULFXP, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VMULFXP, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHS, VSHR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VSHR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHS, VCMV_GTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc( SVHS, VCMV_GTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHU, VSUB, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VSUB, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHU, VMULHI, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VMULHI, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHU, VSHL, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VSHL, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHU, VCMV_LEZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VCMV_LEZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHU, VCMV_NZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VCMV_NZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHU, VADD, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VADD, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHU, VMUL, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VMUL, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHU, VXOR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VXOR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHU, VMOV, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VMOV, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHHU, VCMV_Z, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHU, VCMV_Z, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHW, VABSDIFF, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHW, VABSDIFF, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHW, VOR, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHW, VOR, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHW, VROTR, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHW, VROTR, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHW, VCMV_GEZ, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHW, VCMV_GEZ, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWS, VSUBB, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHWS, VSUBB, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWS, VAND, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHWS, VAND, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWS, VROTL, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHWS, VROTL, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWS, VCMV_LTZ, v_word_out1, 8, v_half_in2 );
	vbxasm_acc( SVHWS, VCMV_LTZ, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWU, VADDC, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHWU, VADDC, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWU, VMULFXP, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHWU, VMULFXP, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWU, VSHR, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHWU, VSHR, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVHWU, VCMV_GTZ, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc( SVHWU, VCMV_GTZ, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWB, VSUB, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWB, VSUB, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWB, VMULHI, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWB, VMULHI, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWB, VSHL, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWB, VSHL, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWB, VCMV_LEZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWB, VCMV_LEZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWB, VCMV_NZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWB, VCMV_NZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBS, VADD, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWBS, VADD, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBS, VMUL, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWBS, VMUL, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBS, VXOR, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWBS, VXOR, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBS, VMOV, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWBS, VMOV, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBS, VCMV_Z, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc( SVWBS, VCMV_Z, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBU, VABSDIFF, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWBU, VABSDIFF, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBU, VOR, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWBU, VOR, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBU, VROTR, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWBU, VROTR, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWBU, VCMV_GEZ, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWBU, VCMV_GEZ, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWH, VSUBB, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWH, VSUBB, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWH, VAND, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWH, VAND, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWH, VROTL, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWH, VROTL, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWH, VCMV_LTZ, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWH, VCMV_LTZ, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHS, VADDC, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWHS, VADDC, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHS, VMULFXP, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWHS, VMULFXP, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHS, VSHR, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWHS, VSHR, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHS, VCMV_GTZ, v_half_out1, 8, v_word_in2 );
	vbxasm_acc( SVWHS, VCMV_GTZ, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHU, VSUB, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWHU, VSUB, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHU, VMULHI, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWHU, VMULHI, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHU, VSHL, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWHU, VSHL, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHU, VCMV_LEZ, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWHU, VCMV_LEZ, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWHU, VCMV_NZ, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWHU, VCMV_NZ, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVW, VADD, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VADD, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVW, VMUL, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VMUL, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVW, VXOR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VXOR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVW, VMOV, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VMOV, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVW, VCMV_Z, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VCMV_Z, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWW, VABSDIFF, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VABSDIFF, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWW, VOR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VOR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWW, VROTR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VROTR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWW, VCMV_GEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVW, VCMV_GEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWS, VSUBB, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VSUBB, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWS, VAND, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VAND, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWS, VROTL, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VROTL, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWS, VCMV_LTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VCMV_LTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWS, VADDC, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VADDC, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWS, VMULFXP, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VMULFXP, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWS, VSHR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VSHR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWS, VCMV_GTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc( SVWS, VCMV_GTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWU, VSUB, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VSUB, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWU, VMULHI, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VMULHI, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWU, VSHL, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VSHL, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWU, VCMV_LEZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VCMV_LEZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWU, VCMV_NZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VCMV_NZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWU, VADD, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VADD, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWU, VMUL, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VMUL, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWU, VXOR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VXOR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWU, VMOV, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VMOV, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SVWWU, VCMV_Z, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc( SVWU, VCMV_Z, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEB, VABSDIFF, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VABSDIFF, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEB, VOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEB, VROTR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VROTR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEB, VCMV_GEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VCMV_GEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBB, VSUBB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VSUBB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBB, VAND, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VAND, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBB, VROTL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VROTL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBB, VCMV_LTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEB, VCMV_LTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBS, VADDC, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VADDC, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBS, VMULFXP, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VMULFXP, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBS, VSHR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VSHR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBS, VCMV_GTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VCMV_GTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBS, VSUB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VSUB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBS, VMULHI, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VMULHI, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBS, VSHL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VSHL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBS, VCMV_LEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VCMV_LEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBS, VCMV_NZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc( VEBS, VCMV_NZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBU, VADD, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VADD, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBU, VMUL, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VMUL, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBU, VXOR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VXOR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBU, VMOV, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VMOV, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBU, VCMV_Z, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VCMV_Z, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBU, VABSDIFF, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VABSDIFF, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBU, VOR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VOR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBU, VROTR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VROTR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEBBU, VCMV_GEZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc( VEBU, VCMV_GEZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEH, VSUBB, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VSUBB, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEH, VAND, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VAND, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEH, VROTL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VROTL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEH, VCMV_LTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VCMV_LTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHH, VADDC, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VADDC, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHH, VMULFXP, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VMULFXP, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHH, VSHR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VSHR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHH, VCMV_GTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEH, VCMV_GTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHS, VSUB, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VSUB, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHS, VMULHI, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VMULHI, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHS, VSHL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VSHL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHS, VCMV_LEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VCMV_LEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHS, VCMV_NZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VCMV_NZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHS, VADD, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VADD, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHS, VMUL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VMUL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHS, VXOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VXOR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHS, VMOV, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VMOV, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHS, VCMV_Z, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc( VEHS, VCMV_Z, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHU, VABSDIFF, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VABSDIFF, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHU, VOR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VOR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHU, VROTR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VROTR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHU, VCMV_GEZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VCMV_GEZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHU, VSUBB, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VSUBB, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHU, VAND, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VAND, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHU, VROTL, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VROTL, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEHHU, VCMV_LTZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc( VEHU, VCMV_LTZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEW, VADDC, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VADDC, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEW, VMULFXP, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VMULFXP, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEW, VSHR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VSHR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEW, VCMV_GTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VCMV_GTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWW, VSUB, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VSUB, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWW, VMULHI, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VMULHI, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWW, VSHL, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VSHL, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWW, VCMV_LEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VCMV_LEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWW, VCMV_NZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEW, VCMV_NZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWS, VADD, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VADD, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWS, VMUL, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VMUL, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWS, VXOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VXOR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWS, VMOV, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VMOV, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWS, VCMV_Z, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VCMV_Z, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWS, VABSDIFF, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VABSDIFF, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWS, VOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VOR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWS, VROTR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VROTR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWS, VCMV_GEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc( VEWS, VCMV_GEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWU, VSUBB, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VSUBB, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWU, VAND, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VAND, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWU, VROTL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VROTL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWU, VCMV_LTZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VCMV_LTZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWU, VADDC, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VADDC, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWU, VMULFXP, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VMULFXP, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWU, VSHR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VSHR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( VEWWU, VCMV_GTZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc( VEWU, VCMV_GTZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEB, VSUB, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VSUB, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEB, VMULHI, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VMULHI, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEB, VSHL, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VSHL, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEB, VCMV_LEZ, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VCMV_LEZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEB, VCMV_NZ, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VCMV_NZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBB, VADD, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VADD, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBB, VMUL, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VMUL, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBB, VXOR, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VXOR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBB, VMOV, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VMOV, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBB, VCMV_Z, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEB, VCMV_Z, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBS, VABSDIFF, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VABSDIFF, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBS, VOR, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VOR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBS, VROTR, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VROTR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBS, VCMV_GEZ, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VCMV_GEZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBS, VSUBB, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VSUBB, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBS, VAND, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VAND, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBS, VROTL, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VROTL, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBS, VCMV_LTZ, v_byte_out1, 8, v_enum );
	vbxasm_acc( SEBS, VCMV_LTZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBU, VADDC, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VADDC, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBU, VMULFXP, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VMULFXP, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBU, VSHR, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VSHR, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBU, VCMV_GTZ, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VCMV_GTZ, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBU, VSUB, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VSUB, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBU, VMULHI, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VMULHI, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBU, VSHL, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VSHL, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBU, VCMV_LEZ, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VCMV_LEZ, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEBBU, VCMV_NZ, v_ubyte_out1, 8, v_enum );
	vbxasm_acc( SEBU, VCMV_NZ, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEH, VADD, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VADD, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEH, VMUL, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VMUL, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEH, VXOR, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VXOR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEH, VMOV, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VMOV, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEH, VCMV_Z, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VCMV_Z, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHH, VABSDIFF, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VABSDIFF, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHH, VOR, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VOR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHH, VROTR, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VROTR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHH, VCMV_GEZ, v_half_out1, 8, v_enum );
	vbxasm_acc( SEH, VCMV_GEZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHS, VSUBB, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VSUBB, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHS, VAND, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VAND, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHS, VROTL, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VROTL, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHS, VCMV_LTZ, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VCMV_LTZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHS, VADDC, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VADDC, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHS, VMULFXP, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VMULFXP, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHS, VSHR, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VSHR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHS, VCMV_GTZ, v_half_out1, 8, v_enum );
	vbxasm_acc( SEHS, VCMV_GTZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHU, VSUB, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VSUB, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHU, VMULHI, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VMULHI, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHU, VSHL, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VSHL, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHU, VCMV_LEZ, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VCMV_LEZ, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHU, VCMV_NZ, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VCMV_NZ, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHU, VADD, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VADD, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHU, VMUL, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VMUL, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHU, VXOR, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VXOR, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHU, VMOV, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VMOV, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEHHU, VCMV_Z, v_uhalf_out1, 8, v_enum );
	vbxasm_acc( SEHU, VCMV_Z, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEW, VABSDIFF, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VABSDIFF, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEW, VOR, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VOR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEW, VROTR, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VROTR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEW, VCMV_GEZ, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VCMV_GEZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWW, VSUBB, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VSUBB, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWW, VAND, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VAND, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWW, VROTL, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VROTL, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWW, VCMV_LTZ, v_word_out1, 8, v_enum );
	vbxasm_acc( SEW, VCMV_LTZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWS, VADDC, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VADDC, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWS, VMULFXP, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VMULFXP, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWS, VSHR, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VSHR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWS, VCMV_GTZ, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VCMV_GTZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWS, VSUB, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VSUB, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWS, VMULHI, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VMULHI, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWS, VSHL, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VSHL, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWS, VCMV_LEZ, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VCMV_LEZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWS, VCMV_NZ, v_word_out1, 8, v_enum );
	vbxasm_acc( SEWS, VCMV_NZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWU, VADD, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VADD, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWU, VMUL, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VMUL, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWU, VXOR, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VXOR, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWU, VMOV, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VMOV, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWU, VCMV_Z, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VCMV_Z, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWU, VABSDIFF, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VABSDIFF, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWU, VOR, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VOR, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWU, VROTR, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VROTR, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc( SEWWU, VCMV_GEZ, v_uword_out1, 8, v_enum );
	vbxasm_acc( SEWU, VCMV_GEZ, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVB, VSUBB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VSUBB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVB, VAND, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VAND, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVB, VROTL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VROTL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVB, VCMV_LTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VCMV_LTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBB, VADDC, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VADDC, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBB, VMULFXP, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VMULFXP, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBB, VSHR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VSHR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBB, VCMV_GTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVB, VCMV_GTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBS, VSUB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VSUB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBS, VMULHI, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VMULHI, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBS, VSHL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VSHL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBS, VCMV_LEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VCMV_LEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBS, VCMV_NZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VCMV_NZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBS, VADD, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VADD, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBS, VMUL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VMUL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBS, VXOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VXOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBS, VMOV, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VMOV, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBS, VCMV_Z, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBS, VCMV_Z, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBU, VABSDIFF, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VABSDIFF, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBU, VOR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VOR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBU, VROTR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VROTR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBU, VCMV_GEZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VCMV_GEZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBU, VSUBB, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VSUBB, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBU, VAND, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VAND, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBU, VROTL, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VROTL, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBBU, VCMV_LTZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBU, VCMV_LTZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBH, VADDC, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBH, VADDC, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBH, VMULFXP, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBH, VMULFXP, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBH, VSHR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBH, VSHR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBH, VCMV_GTZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBH, VCMV_GTZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHS, VSUB, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBHS, VSUB, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHS, VMULHI, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBHS, VMULHI, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHS, VSHL, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBHS, VSHL, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHS, VCMV_LEZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBHS, VCMV_LEZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHS, VCMV_NZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBHS, VCMV_NZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHU, VADD, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBHU, VADD, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHU, VMUL, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBHU, VMUL, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHU, VXOR, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBHU, VXOR, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHU, VMOV, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBHU, VMOV, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBHU, VCMV_Z, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBHU, VCMV_Z, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBW, VABSDIFF, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBW, VABSDIFF, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBW, VOR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBW, VOR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBW, VROTR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBW, VROTR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBW, VCMV_GEZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBW, VCMV_GEZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWS, VSUBB, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBWS, VSUBB, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWS, VAND, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBWS, VAND, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWS, VROTL, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBWS, VROTL, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWS, VCMV_LTZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_2D( VVBWS, VCMV_LTZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWU, VADDC, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBWU, VADDC, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWU, VMULFXP, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBWU, VMULFXP, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWU, VSHR, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBWU, VSHR, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVBWU, VCMV_GTZ, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_2D( VVBWU, VCMV_GTZ, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHB, VSUB, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHB, VSUB, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHB, VMULHI, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHB, VMULHI, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHB, VSHL, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHB, VSHL, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHB, VCMV_LEZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHB, VCMV_LEZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHB, VCMV_NZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHB, VCMV_NZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBS, VADD, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHBS, VADD, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBS, VMUL, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHBS, VMUL, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBS, VXOR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHBS, VXOR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBS, VMOV, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHBS, VMOV, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBS, VCMV_Z, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHBS, VCMV_Z, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBU, VABSDIFF, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHBU, VABSDIFF, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBU, VOR, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHBU, VOR, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBU, VROTR, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHBU, VROTR, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHBU, VCMV_GEZ, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHBU, VCMV_GEZ, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVH, VSUBB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VSUBB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVH, VAND, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VAND, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVH, VROTL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VROTL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVH, VCMV_LTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VCMV_LTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHH, VADDC, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VADDC, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHH, VMULFXP, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VMULFXP, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHH, VSHR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VSHR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHH, VCMV_GTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVH, VCMV_GTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHS, VSUB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VSUB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHS, VMULHI, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VMULHI, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHS, VSHL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VSHL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHS, VCMV_LEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VCMV_LEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHS, VCMV_NZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VCMV_NZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHS, VADD, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VADD, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHS, VMUL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VMUL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHS, VXOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VXOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHS, VMOV, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VMOV, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHS, VCMV_Z, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHS, VCMV_Z, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHU, VABSDIFF, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VABSDIFF, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHU, VOR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VOR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHU, VROTR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VROTR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHU, VCMV_GEZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VCMV_GEZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHU, VSUBB, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VSUBB, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHU, VAND, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VAND, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHU, VROTL, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VROTL, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHHU, VCMV_LTZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHU, VCMV_LTZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHW, VADDC, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHW, VADDC, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHW, VMULFXP, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHW, VMULFXP, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHW, VSHR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHW, VSHR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHW, VCMV_GTZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHW, VCMV_GTZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWS, VSUB, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHWS, VSUB, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWS, VMULHI, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHWS, VMULHI, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWS, VSHL, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHWS, VSHL, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWS, VCMV_LEZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHWS, VCMV_LEZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWS, VCMV_NZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_2D( VVHWS, VCMV_NZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWU, VADD, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHWU, VADD, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWU, VMUL, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHWU, VMUL, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWU, VXOR, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHWU, VXOR, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWU, VMOV, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHWU, VMOV, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVHWU, VCMV_Z, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_2D( VVHWU, VCMV_Z, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWB, VABSDIFF, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWB, VABSDIFF, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWB, VOR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWB, VOR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWB, VROTR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWB, VROTR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWB, VCMV_GEZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWB, VCMV_GEZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBS, VSUBB, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWBS, VSUBB, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBS, VAND, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWBS, VAND, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBS, VROTL, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWBS, VROTL, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBS, VCMV_LTZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWBS, VCMV_LTZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBU, VADDC, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWBU, VADDC, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBU, VMULFXP, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWBU, VMULFXP, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBU, VSHR, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWBU, VSHR, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWBU, VCMV_GTZ, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWBU, VCMV_GTZ, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWH, VSUB, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWH, VSUB, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWH, VMULHI, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWH, VMULHI, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWH, VSHL, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWH, VSHL, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWH, VCMV_LEZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWH, VCMV_LEZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWH, VCMV_NZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWH, VCMV_NZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHS, VADD, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWHS, VADD, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHS, VMUL, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWHS, VMUL, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHS, VXOR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWHS, VXOR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHS, VMOV, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWHS, VMOV, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHS, VCMV_Z, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWHS, VCMV_Z, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHU, VABSDIFF, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWHU, VABSDIFF, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHU, VOR, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWHU, VOR, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHU, VROTR, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWHU, VROTR, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWHU, VCMV_GEZ, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWHU, VCMV_GEZ, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVW, VSUBB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VSUBB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVW, VAND, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VAND, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVW, VROTL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VROTL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVW, VCMV_LTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VCMV_LTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWW, VADDC, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VADDC, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWW, VMULFXP, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VMULFXP, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWW, VSHR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VSHR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWW, VCMV_GTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVW, VCMV_GTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWS, VSUB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VSUB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWS, VMULHI, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VMULHI, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWS, VSHL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VSHL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWS, VCMV_LEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VCMV_LEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWS, VCMV_NZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VCMV_NZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWS, VADD, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VADD, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWS, VMUL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VMUL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWS, VXOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VXOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWS, VMOV, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VMOV, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWS, VCMV_Z, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_2D( VVWS, VCMV_Z, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWU, VABSDIFF, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VABSDIFF, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWU, VOR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VOR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWU, VROTR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VROTR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWU, VCMV_GEZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VCMV_GEZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWU, VSUBB, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VSUBB, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWU, VAND, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VAND, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWU, VROTL, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VROTL, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VVWWU, VCMV_LTZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_2D( VVWU, VCMV_LTZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVB, VADDC, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VADDC, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVB, VMULFXP, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VMULFXP, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVB, VSHR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VSHR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVB, VCMV_GTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VCMV_GTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBB, VSUB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VSUB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBB, VMULHI, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VMULHI, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBB, VSHL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VSHL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBB, VCMV_LEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VCMV_LEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBB, VCMV_NZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVB, VCMV_NZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBS, VADD, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VADD, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBS, VMUL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VMUL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBS, VXOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VXOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBS, VMOV, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VMOV, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBS, VCMV_Z, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VCMV_Z, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBS, VABSDIFF, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VABSDIFF, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBS, VOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBS, VROTR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VROTR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBS, VCMV_GEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBS, VCMV_GEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBU, VSUBB, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VSUBB, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBU, VAND, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VAND, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBU, VROTL, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VROTL, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBU, VCMV_LTZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VCMV_LTZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBU, VADDC, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VADDC, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBU, VMULFXP, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VMULFXP, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBU, VSHR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VSHR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBBU, VCMV_GTZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBU, VCMV_GTZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBH, VSUB, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBH, VSUB, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBH, VMULHI, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBH, VMULHI, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBH, VSHL, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBH, VSHL, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBH, VCMV_LEZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBH, VCMV_LEZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBH, VCMV_NZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBH, VCMV_NZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHS, VADD, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBHS, VADD, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHS, VMUL, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBHS, VMUL, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHS, VXOR, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBHS, VXOR, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHS, VMOV, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBHS, VMOV, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHS, VCMV_Z, v_half_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBHS, VCMV_Z, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHU, VABSDIFF, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBHU, VABSDIFF, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHU, VOR, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBHU, VOR, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHU, VROTR, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBHU, VROTR, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBHU, VCMV_GEZ, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBHU, VCMV_GEZ, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBW, VSUBB, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBW, VSUBB, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBW, VAND, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBW, VAND, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBW, VROTL, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBW, VROTL, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBW, VCMV_LTZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBW, VCMV_LTZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWS, VADDC, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBWS, VADDC, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWS, VMULFXP, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBWS, VMULFXP, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWS, VSHR, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBWS, VSHR, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWS, VCMV_GTZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_2D( SVBWS, VCMV_GTZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWU, VSUB, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBWU, VSUB, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWU, VMULHI, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBWU, VMULHI, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWU, VSHL, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBWU, VSHL, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWU, VCMV_LEZ, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBWU, VCMV_LEZ, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVBWU, VCMV_NZ, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_2D( SVBWU, VCMV_NZ, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHB, VADD, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHB, VADD, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHB, VMUL, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHB, VMUL, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHB, VXOR, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHB, VXOR, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHB, VMOV, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHB, VMOV, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHB, VCMV_Z, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHB, VCMV_Z, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBS, VABSDIFF, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHBS, VABSDIFF, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBS, VOR, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHBS, VOR, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBS, VROTR, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHBS, VROTR, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBS, VCMV_GEZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_2D( SVHBS, VCMV_GEZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBU, VSUBB, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHBU, VSUBB, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBU, VAND, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHBU, VAND, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBU, VROTL, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHBU, VROTL, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHBU, VCMV_LTZ, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHBU, VCMV_LTZ, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVH, VADDC, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VADDC, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVH, VMULFXP, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VMULFXP, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVH, VSHR, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VSHR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVH, VCMV_GTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VCMV_GTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHH, VSUB, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VSUB, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHH, VMULHI, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VMULHI, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHH, VSHL, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VSHL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHH, VCMV_LEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VCMV_LEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHH, VCMV_NZ, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVH, VCMV_NZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHS, VADD, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VADD, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHS, VMUL, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VMUL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHS, VXOR, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VXOR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHS, VMOV, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VMOV, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHS, VCMV_Z, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VCMV_Z, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHS, VABSDIFF, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VABSDIFF, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHS, VOR, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VOR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHS, VROTR, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VROTR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHS, VCMV_GEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_2D( SVHS, VCMV_GEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHU, VSUBB, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VSUBB, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHU, VAND, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VAND, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHU, VROTL, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VROTL, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHU, VCMV_LTZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VCMV_LTZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHU, VADDC, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VADDC, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHU, VMULFXP, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VMULFXP, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHU, VSHR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VSHR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHHU, VCMV_GTZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHU, VCMV_GTZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHW, VSUB, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHW, VSUB, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHW, VMULHI, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHW, VMULHI, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHW, VSHL, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHW, VSHL, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHW, VCMV_LEZ, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHW, VCMV_LEZ, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHW, VCMV_NZ, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHW, VCMV_NZ, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWS, VADD, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHWS, VADD, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWS, VMUL, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHWS, VMUL, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWS, VXOR, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHWS, VXOR, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWS, VMOV, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHWS, VMOV, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWS, VCMV_Z, v_word_out1, 8, v_half_in2 );
	vbxasm_2D( SVHWS, VCMV_Z, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWU, VABSDIFF, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHWU, VABSDIFF, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWU, VOR, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHWU, VOR, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWU, VROTR, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHWU, VROTR, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVHWU, VCMV_GEZ, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_2D( SVHWU, VCMV_GEZ, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWB, VSUBB, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWB, VSUBB, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWB, VAND, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWB, VAND, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWB, VROTL, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWB, VROTL, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWB, VCMV_LTZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWB, VCMV_LTZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBS, VADDC, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWBS, VADDC, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBS, VMULFXP, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWBS, VMULFXP, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBS, VSHR, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWBS, VSHR, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBS, VCMV_GTZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_2D( SVWBS, VCMV_GTZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBU, VSUB, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWBU, VSUB, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBU, VMULHI, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWBU, VMULHI, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBU, VSHL, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWBU, VSHL, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBU, VCMV_LEZ, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWBU, VCMV_LEZ, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWBU, VCMV_NZ, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWBU, VCMV_NZ, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWH, VADD, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWH, VADD, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWH, VMUL, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWH, VMUL, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWH, VXOR, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWH, VXOR, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWH, VMOV, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWH, VMOV, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWH, VCMV_Z, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWH, VCMV_Z, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHS, VABSDIFF, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWHS, VABSDIFF, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHS, VOR, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWHS, VOR, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHS, VROTR, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWHS, VROTR, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHS, VCMV_GEZ, v_half_out1, 8, v_word_in2 );
	vbxasm_2D( SVWHS, VCMV_GEZ, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHU, VSUBB, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWHU, VSUBB, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHU, VAND, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWHU, VAND, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHU, VROTL, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWHU, VROTL, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWHU, VCMV_LTZ, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWHU, VCMV_LTZ, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVW, VADDC, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VADDC, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVW, VMULFXP, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VMULFXP, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVW, VSHR, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VSHR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVW, VCMV_GTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VCMV_GTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWW, VSUB, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VSUB, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWW, VMULHI, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VMULHI, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWW, VSHL, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VSHL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWW, VCMV_LEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VCMV_LEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWW, VCMV_NZ, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVW, VCMV_NZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWS, VADD, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VADD, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWS, VMUL, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VMUL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWS, VXOR, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VXOR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWS, VMOV, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VMOV, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWS, VCMV_Z, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VCMV_Z, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWS, VABSDIFF, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VABSDIFF, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWS, VOR, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VOR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWS, VROTR, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VROTR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWS, VCMV_GEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_2D( SVWS, VCMV_GEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWU, VSUBB, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VSUBB, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWU, VAND, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VAND, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWU, VROTL, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VROTL, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWU, VCMV_LTZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VCMV_LTZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWU, VADDC, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VADDC, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWU, VMULFXP, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VMULFXP, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWU, VSHR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VSHR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SVWWU, VCMV_GTZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_2D( SVWU, VCMV_GTZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEB, VSUB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VSUB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEB, VMULHI, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VMULHI, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEB, VSHL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VSHL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEB, VCMV_LEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VCMV_LEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEB, VCMV_NZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VCMV_NZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBB, VADD, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VADD, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBB, VMUL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VMUL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBB, VXOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VXOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBB, VMOV, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VMOV, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBB, VCMV_Z, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEB, VCMV_Z, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBS, VABSDIFF, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VABSDIFF, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBS, VOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBS, VROTR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VROTR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBS, VCMV_GEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VCMV_GEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBS, VSUBB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VSUBB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBS, VAND, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VAND, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBS, VROTL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VROTL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBS, VCMV_LTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_2D( VEBS, VCMV_LTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBU, VADDC, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VADDC, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBU, VMULFXP, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VMULFXP, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBU, VSHR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VSHR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBU, VCMV_GTZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VCMV_GTZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBU, VSUB, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VSUB, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBU, VMULHI, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VMULHI, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBU, VSHL, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VSHL, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBU, VCMV_LEZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VCMV_LEZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEBBU, VCMV_NZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_2D( VEBU, VCMV_NZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEH, VADD, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VADD, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEH, VMUL, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VMUL, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEH, VXOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VXOR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEH, VMOV, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VMOV, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEH, VCMV_Z, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VCMV_Z, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHH, VABSDIFF, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VABSDIFF, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHH, VOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VOR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHH, VROTR, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VROTR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHH, VCMV_GEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEH, VCMV_GEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHS, VSUBB, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VSUBB, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHS, VAND, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VAND, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHS, VROTL, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VROTL, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHS, VCMV_LTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VCMV_LTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHS, VADDC, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VADDC, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHS, VMULFXP, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VMULFXP, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHS, VSHR, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VSHR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHS, VCMV_GTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_2D( VEHS, VCMV_GTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHU, VSUB, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VSUB, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHU, VMULHI, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VMULHI, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHU, VSHL, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VSHL, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHU, VCMV_LEZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VCMV_LEZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHU, VCMV_NZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VCMV_NZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHU, VADD, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VADD, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHU, VMUL, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VMUL, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHU, VXOR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VXOR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHU, VMOV, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VMOV, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEHHU, VCMV_Z, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_2D( VEHU, VCMV_Z, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEW, VABSDIFF, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VABSDIFF, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEW, VOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VOR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEW, VROTR, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VROTR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEW, VCMV_GEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VCMV_GEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWW, VSUBB, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VSUBB, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWW, VAND, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VAND, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWW, VROTL, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VROTL, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWW, VCMV_LTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEW, VCMV_LTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWS, VADDC, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VADDC, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWS, VMULFXP, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VMULFXP, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWS, VSHR, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VSHR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWS, VCMV_GTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VCMV_GTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWS, VSUB, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VSUB, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWS, VMULHI, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VMULHI, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWS, VSHL, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VSHL, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWS, VCMV_LEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VCMV_LEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWS, VCMV_NZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_2D( VEWS, VCMV_NZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWU, VADD, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VADD, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWU, VMUL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VMUL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWU, VXOR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VXOR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWU, VMOV, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VMOV, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWU, VCMV_Z, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VCMV_Z, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWU, VABSDIFF, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VABSDIFF, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWU, VOR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VOR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWU, VROTR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VROTR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( VEWWU, VCMV_GEZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_2D( VEWU, VCMV_GEZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEB, VSUBB, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VSUBB, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEB, VAND, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VAND, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEB, VROTL, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VROTL, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEB, VCMV_LTZ, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VCMV_LTZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBB, VADDC, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VADDC, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBB, VMULFXP, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VMULFXP, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBB, VSHR, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VSHR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBB, VCMV_GTZ, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEB, VCMV_GTZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBS, VSUB, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VSUB, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBS, VMULHI, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VMULHI, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBS, VSHL, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VSHL, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBS, VCMV_LEZ, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VCMV_LEZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBS, VCMV_NZ, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VCMV_NZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBS, VADD, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VADD, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBS, VMUL, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VMUL, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBS, VXOR, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VXOR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBS, VMOV, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VMOV, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBS, VCMV_Z, v_byte_out1, 8, v_enum );
	vbxasm_2D( SEBS, VCMV_Z, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBU, VABSDIFF, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VABSDIFF, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBU, VOR, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VOR, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBU, VROTR, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VROTR, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBU, VCMV_GEZ, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VCMV_GEZ, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBU, VSUBB, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VSUBB, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBU, VAND, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VAND, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBU, VROTL, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VROTL, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEBBU, VCMV_LTZ, v_ubyte_out1, 8, v_enum );
	vbxasm_2D( SEBU, VCMV_LTZ, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEH, VADDC, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VADDC, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEH, VMULFXP, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VMULFXP, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEH, VSHR, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VSHR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEH, VCMV_GTZ, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VCMV_GTZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHH, VSUB, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VSUB, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHH, VMULHI, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VMULHI, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHH, VSHL, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VSHL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHH, VCMV_LEZ, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VCMV_LEZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHH, VCMV_NZ, v_half_out1, 8, v_enum );
	vbxasm_2D( SEH, VCMV_NZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHS, VADD, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VADD, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHS, VMUL, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VMUL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHS, VXOR, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VXOR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHS, VMOV, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VMOV, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHS, VCMV_Z, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VCMV_Z, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHS, VABSDIFF, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VABSDIFF, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHS, VOR, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VOR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHS, VROTR, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VROTR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHS, VCMV_GEZ, v_half_out1, 8, v_enum );
	vbxasm_2D( SEHS, VCMV_GEZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHU, VSUBB, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VSUBB, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHU, VAND, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VAND, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHU, VROTL, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VROTL, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHU, VCMV_LTZ, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VCMV_LTZ, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHU, VADDC, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VADDC, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHU, VMULFXP, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VMULFXP, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHU, VSHR, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VSHR, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEHHU, VCMV_GTZ, v_uhalf_out1, 8, v_enum );
	vbxasm_2D( SEHU, VCMV_GTZ, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEW, VSUB, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VSUB, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEW, VMULHI, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VMULHI, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEW, VSHL, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VSHL, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEW, VCMV_LEZ, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VCMV_LEZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEW, VCMV_NZ, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VCMV_NZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWW, VADD, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VADD, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWW, VMUL, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VMUL, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWW, VXOR, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VXOR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWW, VMOV, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VMOV, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWW, VCMV_Z, v_word_out1, 8, v_enum );
	vbxasm_2D( SEW, VCMV_Z, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWS, VABSDIFF, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VABSDIFF, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWS, VOR, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VOR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWS, VROTR, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VROTR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWS, VCMV_GEZ, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VCMV_GEZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWS, VSUBB, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VSUBB, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWS, VAND, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VAND, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWS, VROTL, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VROTL, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWS, VCMV_LTZ, v_word_out1, 8, v_enum );
	vbxasm_2D( SEWS, VCMV_LTZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWU, VADDC, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VADDC, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWU, VMULFXP, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VMULFXP, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWU, VSHR, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VSHR, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWU, VCMV_GTZ, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VCMV_GTZ, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWU, VSUB, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VSUB, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWU, VMULHI, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VMULHI, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWU, VSHL, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VSHL, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWU, VCMV_LEZ, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VCMV_LEZ, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_2D( SEWWU, VCMV_NZ, v_uword_out1, 8, v_enum );
	vbxasm_2D( SEWU, VCMV_NZ, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVB, VADD, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VADD, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVB, VMUL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VMUL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVB, VXOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VXOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVB, VMOV, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VMOV, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVB, VCMV_Z, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VCMV_Z, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBB, VABSDIFF, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VABSDIFF, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBB, VOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBB, VROTR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VROTR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBB, VCMV_GEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVB, VCMV_GEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBS, VSUBB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VSUBB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBS, VAND, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VAND, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBS, VROTL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VROTL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBS, VCMV_LTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VCMV_LTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBS, VADDC, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VADDC, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBS, VMULFXP, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VMULFXP, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBS, VSHR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VSHR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBS, VCMV_GTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBS, VCMV_GTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBU, VSUB, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VSUB, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBU, VMULHI, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VMULHI, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBU, VSHL, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VSHL, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBU, VCMV_LEZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VCMV_LEZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBU, VCMV_NZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VCMV_NZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBU, VADD, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VADD, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBU, VMUL, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VMUL, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBU, VXOR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VXOR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBU, VMOV, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VMOV, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBBU, VCMV_Z, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBU, VCMV_Z, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBH, VABSDIFF, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBH, VABSDIFF, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBH, VOR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBH, VOR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBH, VROTR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBH, VROTR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBH, VCMV_GEZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBH, VCMV_GEZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHS, VSUBB, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBHS, VSUBB, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHS, VAND, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBHS, VAND, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHS, VROTL, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBHS, VROTL, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHS, VCMV_LTZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBHS, VCMV_LTZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHU, VADDC, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBHU, VADDC, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHU, VMULFXP, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBHU, VMULFXP, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHU, VSHR, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBHU, VSHR, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBHU, VCMV_GTZ, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBHU, VCMV_GTZ, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBW, VSUB, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBW, VSUB, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBW, VMULHI, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBW, VMULHI, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBW, VSHL, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBW, VSHL, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBW, VCMV_LEZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBW, VCMV_LEZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBW, VCMV_NZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBW, VCMV_NZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWS, VADD, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBWS, VADD, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWS, VMUL, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBWS, VMUL, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWS, VXOR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBWS, VXOR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWS, VMOV, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBWS, VMOV, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWS, VCMV_Z, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_2D( VVBWS, VCMV_Z, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWU, VABSDIFF, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBWU, VABSDIFF, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWU, VOR, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBWU, VOR, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWU, VROTR, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBWU, VROTR, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVBWU, VCMV_GEZ, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_2D( VVBWU, VCMV_GEZ, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHB, VSUBB, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHB, VSUBB, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHB, VAND, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHB, VAND, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHB, VROTL, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHB, VROTL, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHB, VCMV_LTZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHB, VCMV_LTZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBS, VADDC, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHBS, VADDC, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBS, VMULFXP, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHBS, VMULFXP, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBS, VSHR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHBS, VSHR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBS, VCMV_GTZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHBS, VCMV_GTZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBU, VSUB, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHBU, VSUB, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBU, VMULHI, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHBU, VMULHI, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBU, VSHL, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHBU, VSHL, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBU, VCMV_LEZ, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHBU, VCMV_LEZ, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHBU, VCMV_NZ, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHBU, VCMV_NZ, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVH, VADD, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VADD, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVH, VMUL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VMUL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVH, VXOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VXOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVH, VMOV, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VMOV, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVH, VCMV_Z, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VCMV_Z, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHH, VABSDIFF, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VABSDIFF, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHH, VOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHH, VROTR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VROTR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHH, VCMV_GEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVH, VCMV_GEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHS, VSUBB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VSUBB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHS, VAND, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VAND, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHS, VROTL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VROTL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHS, VCMV_LTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VCMV_LTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHS, VADDC, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VADDC, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHS, VMULFXP, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VMULFXP, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHS, VSHR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VSHR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHS, VCMV_GTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHS, VCMV_GTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHU, VSUB, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VSUB, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHU, VMULHI, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VMULHI, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHU, VSHL, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VSHL, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHU, VCMV_LEZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VCMV_LEZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHU, VCMV_NZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VCMV_NZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHU, VADD, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VADD, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHU, VMUL, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VMUL, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHU, VXOR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VXOR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHU, VMOV, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VMOV, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHHU, VCMV_Z, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHU, VCMV_Z, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHW, VABSDIFF, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHW, VABSDIFF, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHW, VOR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHW, VOR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHW, VROTR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHW, VROTR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHW, VCMV_GEZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHW, VCMV_GEZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWS, VSUBB, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHWS, VSUBB, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWS, VAND, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHWS, VAND, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWS, VROTL, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHWS, VROTL, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWS, VCMV_LTZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_2D( VVHWS, VCMV_LTZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWU, VADDC, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHWU, VADDC, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWU, VMULFXP, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHWU, VMULFXP, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWU, VSHR, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHWU, VSHR, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVHWU, VCMV_GTZ, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_2D( VVHWU, VCMV_GTZ, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWB, VSUB, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWB, VSUB, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWB, VMULHI, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWB, VMULHI, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWB, VSHL, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWB, VSHL, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWB, VCMV_LEZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWB, VCMV_LEZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWB, VCMV_NZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWB, VCMV_NZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBS, VADD, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWBS, VADD, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBS, VMUL, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWBS, VMUL, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBS, VXOR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWBS, VXOR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBS, VMOV, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWBS, VMOV, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBS, VCMV_Z, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWBS, VCMV_Z, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBU, VABSDIFF, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWBU, VABSDIFF, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBU, VOR, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWBU, VOR, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBU, VROTR, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWBU, VROTR, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWBU, VCMV_GEZ, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWBU, VCMV_GEZ, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWH, VSUBB, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWH, VSUBB, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWH, VAND, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWH, VAND, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWH, VROTL, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWH, VROTL, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWH, VCMV_LTZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWH, VCMV_LTZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHS, VADDC, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWHS, VADDC, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHS, VMULFXP, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWHS, VMULFXP, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHS, VSHR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWHS, VSHR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHS, VCMV_GTZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWHS, VCMV_GTZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHU, VSUB, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWHU, VSUB, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHU, VMULHI, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWHU, VMULHI, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHU, VSHL, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWHU, VSHL, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHU, VCMV_LEZ, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWHU, VCMV_LEZ, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWHU, VCMV_NZ, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWHU, VCMV_NZ, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVW, VADD, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VADD, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVW, VMUL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VMUL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVW, VXOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VXOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVW, VMOV, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VMOV, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVW, VCMV_Z, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VCMV_Z, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWW, VABSDIFF, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VABSDIFF, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWW, VOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWW, VROTR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VROTR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWW, VCMV_GEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVW, VCMV_GEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWS, VSUBB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VSUBB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWS, VAND, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VAND, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWS, VROTL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VROTL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWS, VCMV_LTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VCMV_LTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWS, VADDC, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VADDC, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWS, VMULFXP, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VMULFXP, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWS, VSHR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VSHR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWS, VCMV_GTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_2D( VVWS, VCMV_GTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWU, VSUB, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VSUB, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWU, VMULHI, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VMULHI, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWU, VSHL, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VSHL, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWU, VCMV_LEZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VCMV_LEZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWU, VCMV_NZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VCMV_NZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWU, VADD, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VADD, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWU, VMUL, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VMUL, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWU, VXOR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VXOR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWU, VMOV, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VMOV, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VVWWU, VCMV_Z, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_2D( VVWU, VCMV_Z, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVB, VABSDIFF, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VABSDIFF, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVB, VOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVB, VROTR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VROTR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVB, VCMV_GEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VCMV_GEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBB, VSUBB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VSUBB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBB, VAND, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VAND, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBB, VROTL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VROTL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBB, VCMV_LTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVB, VCMV_LTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBS, VADDC, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VADDC, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBS, VMULFXP, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VMULFXP, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBS, VSHR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VSHR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBS, VCMV_GTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VCMV_GTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBS, VSUB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VSUB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBS, VMULHI, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VMULHI, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBS, VSHL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VSHL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBS, VCMV_LEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VCMV_LEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBS, VCMV_NZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBS, VCMV_NZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBU, VADD, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VADD, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBU, VMUL, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VMUL, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBU, VXOR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VXOR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBU, VMOV, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VMOV, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBU, VCMV_Z, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VCMV_Z, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBU, VABSDIFF, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VABSDIFF, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBU, VOR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VOR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBU, VROTR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VROTR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBBU, VCMV_GEZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBU, VCMV_GEZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBH, VSUBB, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBH, VSUBB, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBH, VAND, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBH, VAND, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBH, VROTL, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBH, VROTL, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBH, VCMV_LTZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBH, VCMV_LTZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHS, VADDC, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBHS, VADDC, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHS, VMULFXP, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBHS, VMULFXP, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHS, VSHR, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBHS, VSHR, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHS, VCMV_GTZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBHS, VCMV_GTZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHU, VSUB, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBHU, VSUB, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHU, VMULHI, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBHU, VMULHI, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHU, VSHL, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBHU, VSHL, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHU, VCMV_LEZ, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBHU, VCMV_LEZ, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBHU, VCMV_NZ, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBHU, VCMV_NZ, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBW, VADD, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBW, VADD, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBW, VMUL, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBW, VMUL, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBW, VXOR, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBW, VXOR, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBW, VMOV, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBW, VMOV, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBW, VCMV_Z, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBW, VCMV_Z, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWS, VABSDIFF, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBWS, VABSDIFF, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWS, VOR, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBWS, VOR, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWS, VROTR, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBWS, VROTR, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWS, VCMV_GEZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_2D( SVBWS, VCMV_GEZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWU, VSUBB, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBWU, VSUBB, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWU, VAND, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBWU, VAND, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWU, VROTL, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBWU, VROTL, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVBWU, VCMV_LTZ, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_2D( SVBWU, VCMV_LTZ, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHB, VADDC, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHB, VADDC, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHB, VMULFXP, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHB, VMULFXP, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHB, VSHR, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHB, VSHR, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHB, VCMV_GTZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHB, VCMV_GTZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBS, VSUB, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHBS, VSUB, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBS, VMULHI, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHBS, VMULHI, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBS, VSHL, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHBS, VSHL, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBS, VCMV_LEZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHBS, VCMV_LEZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBS, VCMV_NZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHBS, VCMV_NZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBU, VADD, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHBU, VADD, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBU, VMUL, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHBU, VMUL, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBU, VXOR, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHBU, VXOR, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBU, VMOV, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHBU, VMOV, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHBU, VCMV_Z, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHBU, VCMV_Z, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVH, VABSDIFF, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VABSDIFF, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVH, VOR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VOR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVH, VROTR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VROTR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVH, VCMV_GEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VCMV_GEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHH, VSUBB, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VSUBB, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHH, VAND, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VAND, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHH, VROTL, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VROTL, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHH, VCMV_LTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVH, VCMV_LTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHS, VADDC, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VADDC, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHS, VMULFXP, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VMULFXP, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHS, VSHR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VSHR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHS, VCMV_GTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VCMV_GTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHS, VSUB, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VSUB, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHS, VMULHI, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VMULHI, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHS, VSHL, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VSHL, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHS, VCMV_LEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VCMV_LEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHS, VCMV_NZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHS, VCMV_NZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHU, VADD, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VADD, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHU, VMUL, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VMUL, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHU, VXOR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VXOR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHU, VMOV, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VMOV, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHU, VCMV_Z, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VCMV_Z, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHU, VABSDIFF, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VABSDIFF, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHU, VOR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VOR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHU, VROTR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VROTR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHHU, VCMV_GEZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHU, VCMV_GEZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHW, VSUBB, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHW, VSUBB, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHW, VAND, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHW, VAND, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHW, VROTL, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHW, VROTL, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHW, VCMV_LTZ, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHW, VCMV_LTZ, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWS, VADDC, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHWS, VADDC, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWS, VMULFXP, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHWS, VMULFXP, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWS, VSHR, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHWS, VSHR, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWS, VCMV_GTZ, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_2D( SVHWS, VCMV_GTZ, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWU, VSUB, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHWU, VSUB, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWU, VMULHI, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHWU, VMULHI, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWU, VSHL, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHWU, VSHL, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWU, VCMV_LEZ, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHWU, VCMV_LEZ, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVHWU, VCMV_NZ, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_2D( SVHWU, VCMV_NZ, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWB, VADD, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWB, VADD, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWB, VMUL, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWB, VMUL, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWB, VXOR, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWB, VXOR, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWB, VMOV, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWB, VMOV, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWB, VCMV_Z, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWB, VCMV_Z, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBS, VABSDIFF, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWBS, VABSDIFF, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBS, VOR, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWBS, VOR, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBS, VROTR, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWBS, VROTR, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBS, VCMV_GEZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWBS, VCMV_GEZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBU, VSUBB, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWBU, VSUBB, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBU, VAND, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWBU, VAND, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBU, VROTL, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWBU, VROTL, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWBU, VCMV_LTZ, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWBU, VCMV_LTZ, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWH, VADDC, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWH, VADDC, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWH, VMULFXP, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWH, VMULFXP, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWH, VSHR, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWH, VSHR, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWH, VCMV_GTZ, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWH, VCMV_GTZ, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHS, VSUB, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWHS, VSUB, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHS, VMULHI, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWHS, VMULHI, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHS, VSHL, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWHS, VSHL, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHS, VCMV_LEZ, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWHS, VCMV_LEZ, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHS, VCMV_NZ, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWHS, VCMV_NZ, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHU, VADD, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWHU, VADD, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHU, VMUL, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWHU, VMUL, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHU, VXOR, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWHU, VXOR, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHU, VMOV, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWHU, VMOV, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWHU, VCMV_Z, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWHU, VCMV_Z, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVW, VABSDIFF, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VABSDIFF, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVW, VOR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VOR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVW, VROTR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VROTR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVW, VCMV_GEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VCMV_GEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWW, VSUBB, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VSUBB, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWW, VAND, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VAND, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWW, VROTL, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VROTL, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWW, VCMV_LTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVW, VCMV_LTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWS, VADDC, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VADDC, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWS, VMULFXP, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VMULFXP, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWS, VSHR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VSHR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWS, VCMV_GTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VCMV_GTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWS, VSUB, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VSUB, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWS, VMULHI, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VMULHI, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWS, VSHL, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VSHL, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWS, VCMV_LEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VCMV_LEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWS, VCMV_NZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_2D( SVWS, VCMV_NZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWU, VADD, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VADD, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWU, VMUL, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VMUL, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWU, VXOR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VXOR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWU, VMOV, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VMOV, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWU, VCMV_Z, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VCMV_Z, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWU, VABSDIFF, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VABSDIFF, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWU, VOR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VOR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWU, VROTR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VROTR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SVWWU, VCMV_GEZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_2D( SVWU, VCMV_GEZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEB, VSUBB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VSUBB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEB, VAND, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VAND, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEB, VROTL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VROTL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEB, VCMV_LTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VCMV_LTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBB, VADDC, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VADDC, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBB, VMULFXP, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VMULFXP, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBB, VSHR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VSHR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBB, VCMV_GTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEB, VCMV_GTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBS, VSUB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VSUB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBS, VMULHI, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VMULHI, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBS, VSHL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VSHL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBS, VCMV_LEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VCMV_LEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBS, VCMV_NZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VCMV_NZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBS, VADD, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VADD, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBS, VMUL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VMUL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBS, VXOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VXOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBS, VMOV, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VMOV, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBS, VCMV_Z, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_2D( VEBS, VCMV_Z, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBU, VABSDIFF, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VABSDIFF, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBU, VOR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VOR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBU, VROTR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VROTR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBU, VCMV_GEZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VCMV_GEZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBU, VSUBB, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VSUBB, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBU, VAND, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VAND, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBU, VROTL, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VROTL, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEBBU, VCMV_LTZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_2D( VEBU, VCMV_LTZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEH, VADDC, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VADDC, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEH, VMULFXP, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VMULFXP, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEH, VSHR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VSHR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEH, VCMV_GTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VCMV_GTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHH, VSUB, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VSUB, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHH, VMULHI, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VMULHI, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHH, VSHL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VSHL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHH, VCMV_LEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VCMV_LEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHH, VCMV_NZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEH, VCMV_NZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHS, VADD, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VADD, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHS, VMUL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VMUL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHS, VXOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VXOR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHS, VMOV, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VMOV, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHS, VCMV_Z, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VCMV_Z, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHS, VABSDIFF, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VABSDIFF, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHS, VOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VOR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHS, VROTR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VROTR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHS, VCMV_GEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_2D( VEHS, VCMV_GEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHU, VSUBB, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VSUBB, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHU, VAND, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VAND, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHU, VROTL, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VROTL, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHU, VCMV_LTZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VCMV_LTZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHU, VADDC, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VADDC, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHU, VMULFXP, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VMULFXP, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHU, VSHR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VSHR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEHHU, VCMV_GTZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_2D( VEHU, VCMV_GTZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEW, VSUB, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VSUB, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEW, VMULHI, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VMULHI, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEW, VSHL, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VSHL, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEW, VCMV_LEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VCMV_LEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEW, VCMV_NZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VCMV_NZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWW, VADD, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VADD, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWW, VMUL, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VMUL, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWW, VXOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VXOR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWW, VMOV, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VMOV, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWW, VCMV_Z, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEW, VCMV_Z, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWS, VABSDIFF, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VABSDIFF, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWS, VOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VOR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWS, VROTR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VROTR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWS, VCMV_GEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VCMV_GEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWS, VSUBB, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VSUBB, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWS, VAND, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VAND, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWS, VROTL, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VROTL, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWS, VCMV_LTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_2D( VEWS, VCMV_LTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWU, VADDC, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VADDC, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWU, VMULFXP, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VMULFXP, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWU, VSHR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VSHR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWU, VCMV_GTZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VCMV_GTZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWU, VSUB, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VSUB, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWU, VMULHI, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VMULHI, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWU, VSHL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VSHL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWU, VCMV_LEZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VCMV_LEZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( VEWWU, VCMV_NZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_2D( VEWU, VCMV_NZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEB, VADD, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VADD, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEB, VMUL, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VMUL, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEB, VXOR, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VXOR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEB, VMOV, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VMOV, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEB, VCMV_Z, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VCMV_Z, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBB, VABSDIFF, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VABSDIFF, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBB, VOR, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VOR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBB, VROTR, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VROTR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBB, VCMV_GEZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEB, VCMV_GEZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBS, VSUBB, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VSUBB, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBS, VAND, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VAND, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBS, VROTL, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VROTL, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBS, VCMV_LTZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VCMV_LTZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBS, VADDC, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VADDC, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBS, VMULFXP, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VMULFXP, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBS, VSHR, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VSHR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBS, VCMV_GTZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBS, VCMV_GTZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBU, VSUB, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VSUB, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBU, VMULHI, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VMULHI, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBU, VSHL, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VSHL, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBU, VCMV_LEZ, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VCMV_LEZ, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBU, VCMV_NZ, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VCMV_NZ, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBU, VADD, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VADD, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBU, VMUL, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VMUL, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBU, VXOR, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VXOR, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBU, VMOV, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VMOV, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEBBU, VCMV_Z, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_2D( SEBU, VCMV_Z, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEH, VABSDIFF, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VABSDIFF, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEH, VOR, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VOR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEH, VROTR, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VROTR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEH, VCMV_GEZ, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VCMV_GEZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHH, VSUBB, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VSUBB, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHH, VAND, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VAND, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHH, VROTL, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VROTL, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHH, VCMV_LTZ, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEH, VCMV_LTZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHS, VADDC, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VADDC, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHS, VMULFXP, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VMULFXP, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHS, VSHR, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VSHR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHS, VCMV_GTZ, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VCMV_GTZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHS, VSUB, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VSUB, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHS, VMULHI, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VMULHI, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHS, VSHL, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VSHL, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHS, VCMV_LEZ, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VCMV_LEZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHS, VCMV_NZ, v_half_out1, 8, v_enum );
	vbxasm_acc_2D( SEHS, VCMV_NZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHU, VADD, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VADD, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHU, VMUL, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VMUL, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHU, VXOR, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VXOR, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHU, VMOV, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VMOV, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHU, VCMV_Z, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VCMV_Z, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHU, VABSDIFF, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VABSDIFF, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHU, VOR, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VOR, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHU, VROTR, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VROTR, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEHHU, VCMV_GEZ, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_2D( SEHU, VCMV_GEZ, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEW, VSUBB, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VSUBB, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEW, VAND, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VAND, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEW, VROTL, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VROTL, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEW, VCMV_LTZ, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VCMV_LTZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWW, VADDC, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VADDC, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWW, VMULFXP, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VMULFXP, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWW, VSHR, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VSHR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWW, VCMV_GTZ, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEW, VCMV_GTZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWS, VSUB, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VSUB, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWS, VMULHI, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VMULHI, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWS, VSHL, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VSHL, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWS, VCMV_LEZ, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VCMV_LEZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWS, VCMV_NZ, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VCMV_NZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWS, VADD, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VADD, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWS, VMUL, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VMUL, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWS, VXOR, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VXOR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWS, VMOV, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VMOV, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWS, VCMV_Z, v_word_out1, 8, v_enum );
	vbxasm_acc_2D( SEWS, VCMV_Z, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWU, VABSDIFF, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VABSDIFF, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWU, VOR, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VOR, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWU, VROTR, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VROTR, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWU, VCMV_GEZ, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VCMV_GEZ, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWU, VSUBB, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VSUBB, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWU, VAND, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VAND, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWU, VROTL, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VROTL, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_2D( SEWWU, VCMV_LTZ, v_uword_out1, 8, v_enum );
	vbxasm_acc_2D( SEWU, VCMV_LTZ, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVB, VADDC, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VADDC, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVB, VMULFXP, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VMULFXP, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVB, VSHR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VSHR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVB, VCMV_GTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VCMV_GTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBB, VSUB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VSUB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBB, VMULHI, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VMULHI, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBB, VSHL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VSHL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBB, VCMV_LEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VCMV_LEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBB, VCMV_NZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVB, VCMV_NZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBS, VADD, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VADD, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBS, VMUL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VMUL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBS, VXOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VXOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBS, VMOV, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VMOV, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBS, VCMV_Z, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VCMV_Z, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBS, VABSDIFF, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VABSDIFF, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBS, VOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBS, VROTR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VROTR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBS, VCMV_GEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBS, VCMV_GEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBU, VSUBB, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VSUBB, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBU, VAND, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VAND, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBU, VROTL, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VROTL, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBU, VCMV_LTZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VCMV_LTZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBU, VADDC, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VADDC, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBU, VMULFXP, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VMULFXP, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBU, VSHR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VSHR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBBU, VCMV_GTZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBU, VCMV_GTZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBH, VSUB, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBH, VSUB, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBH, VMULHI, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBH, VMULHI, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBH, VSHL, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBH, VSHL, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBH, VCMV_LEZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBH, VCMV_LEZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBH, VCMV_NZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBH, VCMV_NZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHS, VADD, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBHS, VADD, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHS, VMUL, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBHS, VMUL, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHS, VXOR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBHS, VXOR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHS, VMOV, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBHS, VMOV, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHS, VCMV_Z, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBHS, VCMV_Z, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHU, VABSDIFF, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBHU, VABSDIFF, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHU, VOR, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBHU, VOR, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHU, VROTR, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBHU, VROTR, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBHU, VCMV_GEZ, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBHU, VCMV_GEZ, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBW, VSUBB, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBW, VSUBB, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBW, VAND, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBW, VAND, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBW, VROTL, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBW, VROTL, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBW, VCMV_LTZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBW, VCMV_LTZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWS, VADDC, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBWS, VADDC, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWS, VMULFXP, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBWS, VMULFXP, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWS, VSHR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBWS, VSHR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWS, VCMV_GTZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_3D( VVBWS, VCMV_GTZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWU, VSUB, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBWU, VSUB, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWU, VMULHI, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBWU, VMULHI, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWU, VSHL, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBWU, VSHL, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWU, VCMV_LEZ, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBWU, VCMV_LEZ, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVBWU, VCMV_NZ, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_3D( VVBWU, VCMV_NZ, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHB, VADD, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHB, VADD, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHB, VMUL, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHB, VMUL, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHB, VXOR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHB, VXOR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHB, VMOV, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHB, VMOV, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHB, VCMV_Z, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHB, VCMV_Z, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBS, VABSDIFF, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHBS, VABSDIFF, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBS, VOR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHBS, VOR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBS, VROTR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHBS, VROTR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBS, VCMV_GEZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHBS, VCMV_GEZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBU, VSUBB, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHBU, VSUBB, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBU, VAND, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHBU, VAND, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBU, VROTL, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHBU, VROTL, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHBU, VCMV_LTZ, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHBU, VCMV_LTZ, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVH, VADDC, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VADDC, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVH, VMULFXP, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VMULFXP, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVH, VSHR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VSHR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVH, VCMV_GTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VCMV_GTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHH, VSUB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VSUB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHH, VMULHI, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VMULHI, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHH, VSHL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VSHL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHH, VCMV_LEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VCMV_LEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHH, VCMV_NZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVH, VCMV_NZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHS, VADD, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VADD, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHS, VMUL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VMUL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHS, VXOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VXOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHS, VMOV, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VMOV, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHS, VCMV_Z, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VCMV_Z, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHS, VABSDIFF, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VABSDIFF, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHS, VOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHS, VROTR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VROTR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHS, VCMV_GEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHS, VCMV_GEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHU, VSUBB, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VSUBB, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHU, VAND, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VAND, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHU, VROTL, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VROTL, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHU, VCMV_LTZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VCMV_LTZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHU, VADDC, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VADDC, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHU, VMULFXP, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VMULFXP, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHU, VSHR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VSHR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHHU, VCMV_GTZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHU, VCMV_GTZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHW, VSUB, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHW, VSUB, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHW, VMULHI, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHW, VMULHI, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHW, VSHL, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHW, VSHL, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHW, VCMV_LEZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHW, VCMV_LEZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHW, VCMV_NZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHW, VCMV_NZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWS, VADD, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHWS, VADD, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWS, VMUL, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHWS, VMUL, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWS, VXOR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHWS, VXOR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWS, VMOV, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHWS, VMOV, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWS, VCMV_Z, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_3D( VVHWS, VCMV_Z, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWU, VABSDIFF, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHWU, VABSDIFF, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWU, VOR, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHWU, VOR, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWU, VROTR, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHWU, VROTR, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVHWU, VCMV_GEZ, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_3D( VVHWU, VCMV_GEZ, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWB, VSUBB, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWB, VSUBB, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWB, VAND, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWB, VAND, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWB, VROTL, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWB, VROTL, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWB, VCMV_LTZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWB, VCMV_LTZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBS, VADDC, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWBS, VADDC, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBS, VMULFXP, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWBS, VMULFXP, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBS, VSHR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWBS, VSHR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBS, VCMV_GTZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWBS, VCMV_GTZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBU, VSUB, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWBU, VSUB, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBU, VMULHI, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWBU, VMULHI, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBU, VSHL, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWBU, VSHL, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBU, VCMV_LEZ, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWBU, VCMV_LEZ, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWBU, VCMV_NZ, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWBU, VCMV_NZ, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWH, VADD, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWH, VADD, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWH, VMUL, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWH, VMUL, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWH, VXOR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWH, VXOR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWH, VMOV, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWH, VMOV, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWH, VCMV_Z, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWH, VCMV_Z, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHS, VABSDIFF, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWHS, VABSDIFF, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHS, VOR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWHS, VOR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHS, VROTR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWHS, VROTR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHS, VCMV_GEZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWHS, VCMV_GEZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHU, VSUBB, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWHU, VSUBB, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHU, VAND, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWHU, VAND, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHU, VROTL, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWHU, VROTL, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWHU, VCMV_LTZ, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWHU, VCMV_LTZ, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVW, VADDC, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VADDC, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVW, VMULFXP, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VMULFXP, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVW, VSHR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VSHR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVW, VCMV_GTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VCMV_GTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWW, VSUB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VSUB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWW, VMULHI, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VMULHI, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWW, VSHL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VSHL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWW, VCMV_LEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VCMV_LEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWW, VCMV_NZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVW, VCMV_NZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWS, VADD, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VADD, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWS, VMUL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VMUL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWS, VXOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VXOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWS, VMOV, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VMOV, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWS, VCMV_Z, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VCMV_Z, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWS, VABSDIFF, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VABSDIFF, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWS, VOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWS, VROTR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VROTR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWS, VCMV_GEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_3D( VVWS, VCMV_GEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWU, VSUBB, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VSUBB, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWU, VAND, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VAND, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWU, VROTL, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VROTL, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWU, VCMV_LTZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VCMV_LTZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWU, VADDC, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VADDC, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWU, VMULFXP, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VMULFXP, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWU, VSHR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VSHR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VVWWU, VCMV_GTZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_3D( VVWU, VCMV_GTZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVB, VSUB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VSUB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVB, VMULHI, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VMULHI, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVB, VSHL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VSHL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVB, VCMV_LEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VCMV_LEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVB, VCMV_NZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VCMV_NZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBB, VADD, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VADD, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBB, VMUL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VMUL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBB, VXOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VXOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBB, VMOV, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VMOV, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBB, VCMV_Z, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVB, VCMV_Z, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBS, VABSDIFF, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VABSDIFF, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBS, VOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBS, VROTR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VROTR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBS, VCMV_GEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VCMV_GEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBS, VSUBB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VSUBB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBS, VAND, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VAND, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBS, VROTL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VROTL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBS, VCMV_LTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBS, VCMV_LTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBU, VADDC, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VADDC, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBU, VMULFXP, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VMULFXP, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBU, VSHR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VSHR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBU, VCMV_GTZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VCMV_GTZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBU, VSUB, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VSUB, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBU, VMULHI, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VMULHI, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBU, VSHL, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VSHL, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBU, VCMV_LEZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VCMV_LEZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBBU, VCMV_NZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBU, VCMV_NZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBH, VADD, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBH, VADD, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBH, VMUL, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBH, VMUL, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBH, VXOR, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBH, VXOR, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBH, VMOV, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBH, VMOV, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBH, VCMV_Z, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBH, VCMV_Z, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHS, VABSDIFF, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBHS, VABSDIFF, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHS, VOR, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBHS, VOR, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHS, VROTR, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBHS, VROTR, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHS, VCMV_GEZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBHS, VCMV_GEZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHU, VSUBB, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBHU, VSUBB, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHU, VAND, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBHU, VAND, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHU, VROTL, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBHU, VROTL, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBHU, VCMV_LTZ, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBHU, VCMV_LTZ, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBW, VADDC, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBW, VADDC, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBW, VMULFXP, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBW, VMULFXP, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBW, VSHR, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBW, VSHR, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBW, VCMV_GTZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBW, VCMV_GTZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWS, VSUB, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBWS, VSUB, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWS, VMULHI, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBWS, VMULHI, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWS, VSHL, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBWS, VSHL, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWS, VCMV_LEZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBWS, VCMV_LEZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWS, VCMV_NZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_3D( SVBWS, VCMV_NZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWU, VADD, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBWU, VADD, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWU, VMUL, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBWU, VMUL, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWU, VXOR, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBWU, VXOR, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWU, VMOV, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBWU, VMOV, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVBWU, VCMV_Z, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_3D( SVBWU, VCMV_Z, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHB, VABSDIFF, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHB, VABSDIFF, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHB, VOR, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHB, VOR, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHB, VROTR, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHB, VROTR, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHB, VCMV_GEZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHB, VCMV_GEZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBS, VSUBB, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHBS, VSUBB, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBS, VAND, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHBS, VAND, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBS, VROTL, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHBS, VROTL, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBS, VCMV_LTZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_3D( SVHBS, VCMV_LTZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBU, VADDC, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHBU, VADDC, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBU, VMULFXP, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHBU, VMULFXP, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBU, VSHR, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHBU, VSHR, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHBU, VCMV_GTZ, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHBU, VCMV_GTZ, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVH, VSUB, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VSUB, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVH, VMULHI, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VMULHI, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVH, VSHL, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VSHL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVH, VCMV_LEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VCMV_LEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVH, VCMV_NZ, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VCMV_NZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHH, VADD, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VADD, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHH, VMUL, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VMUL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHH, VXOR, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VXOR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHH, VMOV, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VMOV, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHH, VCMV_Z, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVH, VCMV_Z, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHS, VABSDIFF, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VABSDIFF, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHS, VOR, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VOR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHS, VROTR, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VROTR, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHS, VCMV_GEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VCMV_GEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHS, VSUBB, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VSUBB, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHS, VAND, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VAND, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHS, VROTL, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VROTL, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHS, VCMV_LTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_3D( SVHS, VCMV_LTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHU, VADDC, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VADDC, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHU, VMULFXP, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VMULFXP, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHU, VSHR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VSHR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHU, VCMV_GTZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VCMV_GTZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHU, VSUB, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VSUB, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHU, VMULHI, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VMULHI, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHU, VSHL, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VSHL, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHU, VCMV_LEZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VCMV_LEZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHHU, VCMV_NZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHU, VCMV_NZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHW, VADD, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHW, VADD, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHW, VMUL, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHW, VMUL, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHW, VXOR, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHW, VXOR, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHW, VMOV, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHW, VMOV, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHW, VCMV_Z, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHW, VCMV_Z, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWS, VABSDIFF, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHWS, VABSDIFF, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWS, VOR, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHWS, VOR, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWS, VROTR, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHWS, VROTR, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWS, VCMV_GEZ, v_word_out1, 8, v_half_in2 );
	vbxasm_3D( SVHWS, VCMV_GEZ, v_word_out2, 8, v_half_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWU, VSUBB, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHWU, VSUBB, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWU, VAND, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHWU, VAND, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWU, VROTL, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHWU, VROTL, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVHWU, VCMV_LTZ, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_3D( SVHWU, VCMV_LTZ, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWB, VADDC, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWB, VADDC, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWB, VMULFXP, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWB, VMULFXP, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWB, VSHR, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWB, VSHR, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWB, VCMV_GTZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWB, VCMV_GTZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBS, VSUB, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWBS, VSUB, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBS, VMULHI, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWBS, VMULHI, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBS, VSHL, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWBS, VSHL, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBS, VCMV_LEZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWBS, VCMV_LEZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBS, VCMV_NZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_3D( SVWBS, VCMV_NZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBU, VADD, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWBU, VADD, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBU, VMUL, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWBU, VMUL, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBU, VXOR, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWBU, VXOR, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBU, VMOV, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWBU, VMOV, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWBU, VCMV_Z, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWBU, VCMV_Z, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWH, VABSDIFF, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWH, VABSDIFF, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWH, VOR, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWH, VOR, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWH, VROTR, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWH, VROTR, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWH, VCMV_GEZ, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWH, VCMV_GEZ, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHS, VSUBB, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWHS, VSUBB, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHS, VAND, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWHS, VAND, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHS, VROTL, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWHS, VROTL, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHS, VCMV_LTZ, v_half_out1, 8, v_word_in2 );
	vbxasm_3D( SVWHS, VCMV_LTZ, v_half_out2, 8, v_word_in2 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHU, VADDC, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWHU, VADDC, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHU, VMULFXP, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWHU, VMULFXP, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHU, VSHR, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWHU, VSHR, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWHU, VCMV_GTZ, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWHU, VCMV_GTZ, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVW, VSUB, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VSUB, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVW, VMULHI, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VMULHI, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVW, VSHL, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VSHL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVW, VCMV_LEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VCMV_LEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVW, VCMV_NZ, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VCMV_NZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWW, VADD, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VADD, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWW, VMUL, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VMUL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWW, VXOR, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VXOR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWW, VMOV, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VMOV, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWW, VCMV_Z, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVW, VCMV_Z, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWS, VABSDIFF, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VABSDIFF, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWS, VOR, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VOR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWS, VROTR, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VROTR, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWS, VCMV_GEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VCMV_GEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWS, VSUBB, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VSUBB, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWS, VAND, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VAND, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWS, VROTL, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VROTL, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWS, VCMV_LTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_3D( SVWS, VCMV_LTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWU, VADDC, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VADDC, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWU, VMULFXP, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VMULFXP, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWU, VSHR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VSHR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWU, VCMV_GTZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VCMV_GTZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWU, VSUB, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VSUB, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWU, VMULHI, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VMULHI, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWU, VSHL, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VSHL, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWU, VCMV_LEZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VCMV_LEZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SVWWU, VCMV_NZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_3D( SVWU, VCMV_NZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEB, VADD, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VADD, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEB, VMUL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VMUL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEB, VXOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VXOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEB, VMOV, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VMOV, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEB, VCMV_Z, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VCMV_Z, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBB, VABSDIFF, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VABSDIFF, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBB, VOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBB, VROTR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VROTR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBB, VCMV_GEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEB, VCMV_GEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBS, VSUBB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VSUBB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBS, VAND, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VAND, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBS, VROTL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VROTL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBS, VCMV_LTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VCMV_LTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBS, VADDC, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VADDC, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBS, VMULFXP, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VMULFXP, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBS, VSHR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VSHR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBS, VCMV_GTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_3D( VEBS, VCMV_GTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBU, VSUB, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VSUB, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBU, VMULHI, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VMULHI, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBU, VSHL, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VSHL, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBU, VCMV_LEZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VCMV_LEZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBU, VCMV_NZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VCMV_NZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBU, VADD, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VADD, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBU, VMUL, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VMUL, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBU, VXOR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VXOR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBU, VMOV, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VMOV, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEBBU, VCMV_Z, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_3D( VEBU, VCMV_Z, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEH, VABSDIFF, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VABSDIFF, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEH, VOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VOR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEH, VROTR, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VROTR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEH, VCMV_GEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VCMV_GEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHH, VSUBB, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VSUBB, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHH, VAND, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VAND, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHH, VROTL, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VROTL, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHH, VCMV_LTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEH, VCMV_LTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHS, VADDC, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VADDC, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHS, VMULFXP, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VMULFXP, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHS, VSHR, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VSHR, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHS, VCMV_GTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VCMV_GTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHS, VSUB, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VSUB, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHS, VMULHI, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VMULHI, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHS, VSHL, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VSHL, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHS, VCMV_LEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VCMV_LEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHS, VCMV_NZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_3D( VEHS, VCMV_NZ, v_half_out2, v_half_in1, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHU, VADD, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VADD, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHU, VMUL, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VMUL, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHU, VXOR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VXOR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHU, VMOV, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VMOV, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHU, VCMV_Z, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VCMV_Z, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHU, VABSDIFF, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VABSDIFF, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHU, VOR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VOR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHU, VROTR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VROTR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEHHU, VCMV_GEZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_3D( VEHU, VCMV_GEZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEW, VSUBB, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VSUBB, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEW, VAND, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VAND, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEW, VROTL, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VROTL, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEW, VCMV_LTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VCMV_LTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWW, VADDC, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VADDC, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWW, VMULFXP, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VMULFXP, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWW, VSHR, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VSHR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWW, VCMV_GTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEW, VCMV_GTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWS, VSUB, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VSUB, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWS, VMULHI, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VMULHI, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWS, VSHL, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VSHL, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWS, VCMV_LEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VCMV_LEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWS, VCMV_NZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VCMV_NZ, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWS, VADD, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VADD, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWS, VMUL, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VMUL, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWS, VXOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VXOR, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWS, VMOV, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VMOV, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWS, VCMV_Z, v_word_out1, v_word_in1, v_enum );
	vbxasm_3D( VEWS, VCMV_Z, v_word_out2, v_word_in1, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWU, VABSDIFF, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VABSDIFF, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWU, VOR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VOR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWU, VROTR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VROTR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWU, VCMV_GEZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VCMV_GEZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWU, VSUBB, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VSUBB, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWU, VAND, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VAND, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWU, VROTL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VROTL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( VEWWU, VCMV_LTZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_3D( VEWU, VCMV_LTZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEB, VADDC, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VADDC, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEB, VMULFXP, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VMULFXP, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEB, VSHR, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VSHR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEB, VCMV_GTZ, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VCMV_GTZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBB, VSUB, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VSUB, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBB, VMULHI, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VMULHI, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBB, VSHL, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VSHL, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBB, VCMV_LEZ, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VCMV_LEZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBB, VCMV_NZ, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEB, VCMV_NZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBS, VADD, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VADD, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBS, VMUL, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VMUL, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBS, VXOR, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VXOR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBS, VMOV, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VMOV, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBS, VCMV_Z, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VCMV_Z, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBS, VABSDIFF, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VABSDIFF, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBS, VOR, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VOR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBS, VROTR, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VROTR, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBS, VCMV_GEZ, v_byte_out1, 8, v_enum );
	vbxasm_3D( SEBS, VCMV_GEZ, v_byte_out2, 8, 0 );
	errors += compare_results_byte(v_byte_acc , v_byte_out1 , v_byte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBU, VSUBB, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VSUBB, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBU, VAND, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VAND, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBU, VROTL, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VROTL, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBU, VCMV_LTZ, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VCMV_LTZ, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBU, VADDC, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VADDC, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBU, VMULFXP, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VMULFXP, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBU, VSHR, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VSHR, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEBBU, VCMV_GTZ, v_ubyte_out1, 8, v_enum );
	vbxasm_3D( SEBU, VCMV_GTZ, v_ubyte_out2, 8, 0 );
	errors += compare_results_ubyte(v_ubyte_acc , v_ubyte_out1 , v_ubyte_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEH, VSUB, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VSUB, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEH, VMULHI, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VMULHI, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEH, VSHL, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VSHL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEH, VCMV_LEZ, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VCMV_LEZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEH, VCMV_NZ, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VCMV_NZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHH, VADD, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VADD, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHH, VMUL, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VMUL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHH, VXOR, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VXOR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHH, VMOV, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VMOV, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHH, VCMV_Z, v_half_out1, 8, v_enum );
	vbxasm_3D( SEH, VCMV_Z, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHS, VABSDIFF, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VABSDIFF, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHS, VOR, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VOR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHS, VROTR, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VROTR, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHS, VCMV_GEZ, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VCMV_GEZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHS, VSUBB, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VSUBB, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHS, VAND, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VAND, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHS, VROTL, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VROTL, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHS, VCMV_LTZ, v_half_out1, 8, v_enum );
	vbxasm_3D( SEHS, VCMV_LTZ, v_half_out2, 8, 0 );
	errors += compare_results_half(v_half_acc , v_half_out1 , v_half_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHU, VADDC, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VADDC, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHU, VMULFXP, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VMULFXP, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHU, VSHR, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VSHR, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHU, VCMV_GTZ, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VCMV_GTZ, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHU, VSUB, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VSUB, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHU, VMULHI, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VMULHI, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHU, VSHL, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VSHL, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHU, VCMV_LEZ, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VCMV_LEZ, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEHHU, VCMV_NZ, v_uhalf_out1, 8, v_enum );
	vbxasm_3D( SEHU, VCMV_NZ, v_uhalf_out2, 8, 0 );
	errors += compare_results_uhalf(v_uhalf_acc , v_uhalf_out1 , v_uhalf_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEW, VADD, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VADD, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEW, VMUL, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VMUL, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEW, VXOR, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VXOR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEW, VMOV, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VMOV, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEW, VCMV_Z, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VCMV_Z, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWW, VABSDIFF, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VABSDIFF, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWW, VOR, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VOR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWW, VROTR, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VROTR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWW, VCMV_GEZ, v_word_out1, 8, v_enum );
	vbxasm_3D( SEW, VCMV_GEZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWS, VSUBB, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VSUBB, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWS, VAND, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VAND, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWS, VROTL, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VROTL, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWS, VCMV_LTZ, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VCMV_LTZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWS, VADDC, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VADDC, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWS, VMULFXP, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VMULFXP, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWS, VSHR, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VSHR, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWS, VCMV_GTZ, v_word_out1, 8, v_enum );
	vbxasm_3D( SEWS, VCMV_GTZ, v_word_out2, 8, 0 );
	errors += compare_results_word(v_word_acc , v_word_out1 , v_word_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWU, VSUB, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VSUB, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWU, VMULHI, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VMULHI, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWU, VSHL, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VSHL, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWU, VCMV_LEZ, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VCMV_LEZ, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWU, VCMV_NZ, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VCMV_NZ, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWU, VADD, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VADD, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWU, VMUL, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VMUL, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWU, VXOR, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VXOR, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWU, VMOV, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VMOV, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_3D( SEWWU, VCMV_Z, v_uword_out1, 8, v_enum );
	vbxasm_3D( SEWU, VCMV_Z, v_uword_out2, 8, 0 );
	errors += compare_results_uword(v_uword_acc , v_uword_out1 , v_uword_out2  );

	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVB, VABSDIFF, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VABSDIFF, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVB, VOR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VOR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVB, VROTR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VROTR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVB, VCMV_GEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VCMV_GEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBB, VSUBB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VSUBB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBB, VAND, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VAND, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBB, VROTL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VROTL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBB, VCMV_LTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVB, VCMV_LTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBS, VADDC, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VADDC, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBS, VMULFXP, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VMULFXP, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBS, VSHR, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VSHR, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBS, VCMV_GTZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VCMV_GTZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBS, VSUB, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VSUB, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBS, VMULHI, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VMULHI, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBS, VSHL, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VSHL, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBS, VCMV_LEZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VCMV_LEZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBS, VCMV_NZ, v_byte_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBS, VCMV_NZ, v_byte_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBU, VADD, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VADD, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBU, VMUL, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VMUL, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBU, VXOR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VXOR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBU, VMOV, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VMOV, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBU, VCMV_Z, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VCMV_Z, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBU, VABSDIFF, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VABSDIFF, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBU, VOR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VOR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBU, VROTR, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VROTR, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBBU, VCMV_GEZ, v_ubyte_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBU, VCMV_GEZ, v_ubyte_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBH, VSUBB, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBH, VSUBB, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBH, VAND, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBH, VAND, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBH, VROTL, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBH, VROTL, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBH, VCMV_LTZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBH, VCMV_LTZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHS, VADDC, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBHS, VADDC, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHS, VMULFXP, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBHS, VMULFXP, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHS, VSHR, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBHS, VSHR, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHS, VCMV_GTZ, v_half_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBHS, VCMV_GTZ, v_half_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHU, VSUB, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBHU, VSUB, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHU, VMULHI, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBHU, VMULHI, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHU, VSHL, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBHU, VSHL, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHU, VCMV_LEZ, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBHU, VCMV_LEZ, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBHU, VCMV_NZ, v_uhalf_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBHU, VCMV_NZ, v_uhalf_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBW, VADD, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBW, VADD, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBW, VMUL, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBW, VMUL, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBW, VXOR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBW, VXOR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBW, VMOV, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBW, VMOV, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBW, VCMV_Z, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBW, VCMV_Z, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWS, VABSDIFF, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBWS, VABSDIFF, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWS, VOR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBWS, VOR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWS, VROTR, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBWS, VROTR, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWS, VCMV_GEZ, v_word_out1, v_byte_in1, v_byte_in2 );
	vbxasm_acc_3D( VVBWS, VCMV_GEZ, v_word_out2, v_byte_in1, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWU, VSUBB, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBWU, VSUBB, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWU, VAND, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBWU, VAND, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWU, VROTL, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBWU, VROTL, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVBWU, VCMV_LTZ, v_uword_out1, v_ubyte_in1, v_ubyte_in2 );
	vbxasm_acc_3D( VVBWU, VCMV_LTZ, v_uword_out2, v_ubyte_in1, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHB, VADDC, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHB, VADDC, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHB, VMULFXP, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHB, VMULFXP, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHB, VSHR, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHB, VSHR, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHB, VCMV_GTZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHB, VCMV_GTZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBS, VSUB, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHBS, VSUB, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBS, VMULHI, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHBS, VMULHI, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBS, VSHL, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHBS, VSHL, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBS, VCMV_LEZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHBS, VCMV_LEZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBS, VCMV_NZ, v_byte_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHBS, VCMV_NZ, v_byte_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBU, VADD, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHBU, VADD, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBU, VMUL, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHBU, VMUL, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBU, VXOR, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHBU, VXOR, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBU, VMOV, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHBU, VMOV, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHBU, VCMV_Z, v_ubyte_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHBU, VCMV_Z, v_ubyte_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVH, VABSDIFF, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VABSDIFF, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVH, VOR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VOR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVH, VROTR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VROTR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVH, VCMV_GEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VCMV_GEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHH, VSUBB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VSUBB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHH, VAND, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VAND, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHH, VROTL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VROTL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHH, VCMV_LTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVH, VCMV_LTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHS, VADDC, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VADDC, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHS, VMULFXP, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VMULFXP, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHS, VSHR, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VSHR, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHS, VCMV_GTZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VCMV_GTZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHS, VSUB, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VSUB, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHS, VMULHI, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VMULHI, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHS, VSHL, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VSHL, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHS, VCMV_LEZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VCMV_LEZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHS, VCMV_NZ, v_half_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHS, VCMV_NZ, v_half_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHU, VADD, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VADD, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHU, VMUL, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VMUL, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHU, VXOR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VXOR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHU, VMOV, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VMOV, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHU, VCMV_Z, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VCMV_Z, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHU, VABSDIFF, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VABSDIFF, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHU, VOR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VOR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHU, VROTR, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VROTR, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHHU, VCMV_GEZ, v_uhalf_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHU, VCMV_GEZ, v_uhalf_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHW, VSUBB, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHW, VSUBB, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHW, VAND, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHW, VAND, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHW, VROTL, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHW, VROTL, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHW, VCMV_LTZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHW, VCMV_LTZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWS, VADDC, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHWS, VADDC, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWS, VMULFXP, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHWS, VMULFXP, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWS, VSHR, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHWS, VSHR, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWS, VCMV_GTZ, v_word_out1, v_half_in1, v_half_in2 );
	vbxasm_acc_3D( VVHWS, VCMV_GTZ, v_word_out2, v_half_in1, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWU, VSUB, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHWU, VSUB, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWU, VMULHI, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHWU, VMULHI, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWU, VSHL, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHWU, VSHL, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWU, VCMV_LEZ, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHWU, VCMV_LEZ, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVHWU, VCMV_NZ, v_uword_out1, v_uhalf_in1, v_uhalf_in2 );
	vbxasm_acc_3D( VVHWU, VCMV_NZ, v_uword_out2, v_uhalf_in1, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWB, VADD, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWB, VADD, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWB, VMUL, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWB, VMUL, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWB, VXOR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWB, VXOR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWB, VMOV, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWB, VMOV, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWB, VCMV_Z, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWB, VCMV_Z, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBS, VABSDIFF, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWBS, VABSDIFF, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBS, VOR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWBS, VOR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBS, VROTR, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWBS, VROTR, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBS, VCMV_GEZ, v_byte_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWBS, VCMV_GEZ, v_byte_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBU, VSUBB, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWBU, VSUBB, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBU, VAND, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWBU, VAND, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBU, VROTL, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWBU, VROTL, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWBU, VCMV_LTZ, v_ubyte_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWBU, VCMV_LTZ, v_ubyte_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWH, VADDC, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWH, VADDC, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWH, VMULFXP, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWH, VMULFXP, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWH, VSHR, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWH, VSHR, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWH, VCMV_GTZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWH, VCMV_GTZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHS, VSUB, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWHS, VSUB, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHS, VMULHI, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWHS, VMULHI, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHS, VSHL, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWHS, VSHL, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHS, VCMV_LEZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWHS, VCMV_LEZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHS, VCMV_NZ, v_half_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWHS, VCMV_NZ, v_half_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHU, VADD, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWHU, VADD, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHU, VMUL, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWHU, VMUL, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHU, VXOR, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWHU, VXOR, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHU, VMOV, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWHU, VMOV, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWHU, VCMV_Z, v_uhalf_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWHU, VCMV_Z, v_uhalf_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVW, VABSDIFF, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VABSDIFF, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVW, VOR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VOR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVW, VROTR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VROTR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVW, VCMV_GEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VCMV_GEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWW, VSUBB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VSUBB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWW, VAND, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VAND, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWW, VROTL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VROTL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWW, VCMV_LTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVW, VCMV_LTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWS, VADDC, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VADDC, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWS, VMULFXP, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VMULFXP, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWS, VSHR, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VSHR, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWS, VCMV_GTZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VCMV_GTZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWS, VSUB, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VSUB, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWS, VMULHI, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VMULHI, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWS, VSHL, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VSHL, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWS, VCMV_LEZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VCMV_LEZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWS, VCMV_NZ, v_word_out1, v_word_in1, v_word_in2 );
	vbxasm_acc_3D( VVWS, VCMV_NZ, v_word_out2, v_word_in1, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWU, VADD, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VADD, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWU, VMUL, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VMUL, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWU, VXOR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VXOR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWU, VMOV, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VMOV, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWU, VCMV_Z, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VCMV_Z, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWU, VABSDIFF, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VABSDIFF, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWU, VOR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VOR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWU, VROTR, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VROTR, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VVWWU, VCMV_GEZ, v_uword_out1, v_uword_in1, v_uword_in2 );
	vbxasm_acc_3D( VVWU, VCMV_GEZ, v_uword_out2, v_uword_in1, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVB, VSUBB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VSUBB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVB, VAND, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VAND, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVB, VROTL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VROTL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVB, VCMV_LTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VCMV_LTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBB, VADDC, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VADDC, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBB, VMULFXP, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VMULFXP, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBB, VSHR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VSHR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBB, VCMV_GTZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVB, VCMV_GTZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBS, VSUB, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VSUB, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBS, VMULHI, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VMULHI, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBS, VSHL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VSHL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBS, VCMV_LEZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VCMV_LEZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBS, VCMV_NZ, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VCMV_NZ, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBS, VADD, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VADD, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBS, VMUL, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VMUL, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBS, VXOR, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VXOR, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBS, VMOV, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VMOV, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBS, VCMV_Z, v_byte_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBS, VCMV_Z, v_byte_out2, 8, v_byte_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBU, VABSDIFF, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VABSDIFF, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBU, VOR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VOR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBU, VROTR, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VROTR, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBU, VCMV_GEZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VCMV_GEZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBU, VSUBB, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VSUBB, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBU, VAND, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VAND, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBU, VROTL, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VROTL, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBBU, VCMV_LTZ, v_ubyte_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBU, VCMV_LTZ, v_ubyte_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBH, VADDC, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBH, VADDC, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBH, VMULFXP, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBH, VMULFXP, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBH, VSHR, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBH, VSHR, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBH, VCMV_GTZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBH, VCMV_GTZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHS, VSUB, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBHS, VSUB, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHS, VMULHI, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBHS, VMULHI, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHS, VSHL, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBHS, VSHL, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHS, VCMV_LEZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBHS, VCMV_LEZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHS, VCMV_NZ, v_half_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBHS, VCMV_NZ, v_half_out2, 8, v_byte_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHU, VADD, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBHU, VADD, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHU, VMUL, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBHU, VMUL, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHU, VXOR, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBHU, VXOR, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHU, VMOV, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBHU, VMOV, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBHU, VCMV_Z, v_uhalf_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBHU, VCMV_Z, v_uhalf_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBW, VABSDIFF, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBW, VABSDIFF, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBW, VOR, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBW, VOR, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBW, VROTR, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBW, VROTR, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBW, VCMV_GEZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBW, VCMV_GEZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWS, VSUBB, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBWS, VSUBB, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWS, VAND, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBWS, VAND, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWS, VROTL, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBWS, VROTL, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWS, VCMV_LTZ, v_word_out1, 8, v_byte_in2 );
	vbxasm_acc_3D( SVBWS, VCMV_LTZ, v_word_out2, 8, v_byte_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWU, VADDC, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBWU, VADDC, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWU, VMULFXP, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBWU, VMULFXP, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWU, VSHR, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBWU, VSHR, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVBWU, VCMV_GTZ, v_uword_out1, 8, v_ubyte_in2 );
	vbxasm_acc_3D( SVBWU, VCMV_GTZ, v_uword_out2, 8, v_ubyte_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHB, VSUB, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHB, VSUB, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHB, VMULHI, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHB, VMULHI, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHB, VSHL, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHB, VSHL, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHB, VCMV_LEZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHB, VCMV_LEZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHB, VCMV_NZ, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHB, VCMV_NZ, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBS, VADD, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHBS, VADD, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBS, VMUL, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHBS, VMUL, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBS, VXOR, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHBS, VXOR, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBS, VMOV, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHBS, VMOV, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBS, VCMV_Z, v_byte_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHBS, VCMV_Z, v_byte_out2, 8, v_half_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBU, VABSDIFF, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHBU, VABSDIFF, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBU, VOR, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHBU, VOR, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBU, VROTR, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHBU, VROTR, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHBU, VCMV_GEZ, v_ubyte_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHBU, VCMV_GEZ, v_ubyte_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVH, VSUBB, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VSUBB, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVH, VAND, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VAND, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVH, VROTL, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VROTL, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVH, VCMV_LTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VCMV_LTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHH, VADDC, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VADDC, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHH, VMULFXP, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VMULFXP, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHH, VSHR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VSHR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHH, VCMV_GTZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVH, VCMV_GTZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHS, VSUB, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VSUB, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHS, VMULHI, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VMULHI, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHS, VSHL, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VSHL, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHS, VCMV_LEZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VCMV_LEZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHS, VCMV_NZ, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VCMV_NZ, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHS, VADD, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VADD, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHS, VMUL, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VMUL, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHS, VXOR, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VXOR, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHS, VMOV, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VMOV, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHS, VCMV_Z, v_half_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHS, VCMV_Z, v_half_out2, 8, v_half_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHU, VABSDIFF, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VABSDIFF, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHU, VOR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VOR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHU, VROTR, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VROTR, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHU, VCMV_GEZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VCMV_GEZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHU, VSUBB, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VSUBB, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHU, VAND, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VAND, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHU, VROTL, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VROTL, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHHU, VCMV_LTZ, v_uhalf_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHU, VCMV_LTZ, v_uhalf_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHW, VADDC, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHW, VADDC, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHW, VMULFXP, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHW, VMULFXP, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHW, VSHR, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHW, VSHR, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHW, VCMV_GTZ, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHW, VCMV_GTZ, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWS, VSUB, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHWS, VSUB, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWS, VMULHI, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHWS, VMULHI, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWS, VSHL, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHWS, VSHL, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWS, VCMV_LEZ, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHWS, VCMV_LEZ, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWS, VCMV_NZ, v_word_out1, 8, v_half_in2 );
	vbxasm_acc_3D( SVHWS, VCMV_NZ, v_word_out2, 8, v_half_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWU, VADD, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHWU, VADD, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWU, VMUL, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHWU, VMUL, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWU, VXOR, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHWU, VXOR, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWU, VMOV, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHWU, VMOV, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVHWU, VCMV_Z, v_uword_out1, 8, v_uhalf_in2 );
	vbxasm_acc_3D( SVHWU, VCMV_Z, v_uword_out2, 8, v_uhalf_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWB, VABSDIFF, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWB, VABSDIFF, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWB, VOR, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWB, VOR, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWB, VROTR, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWB, VROTR, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWB, VCMV_GEZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWB, VCMV_GEZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBS, VSUBB, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWBS, VSUBB, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBS, VAND, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWBS, VAND, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBS, VROTL, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWBS, VROTL, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBS, VCMV_LTZ, v_byte_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWBS, VCMV_LTZ, v_byte_out2, 8, v_word_in2 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBU, VADDC, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWBU, VADDC, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBU, VMULFXP, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWBU, VMULFXP, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBU, VSHR, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWBU, VSHR, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWBU, VCMV_GTZ, v_ubyte_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWBU, VCMV_GTZ, v_ubyte_out2, 8, v_uword_in2 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWH, VSUB, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWH, VSUB, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWH, VMULHI, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWH, VMULHI, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWH, VSHL, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWH, VSHL, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWH, VCMV_LEZ, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWH, VCMV_LEZ, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWH, VCMV_NZ, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWH, VCMV_NZ, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHS, VADD, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWHS, VADD, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHS, VMUL, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWHS, VMUL, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHS, VXOR, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWHS, VXOR, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHS, VMOV, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWHS, VMOV, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHS, VCMV_Z, v_half_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWHS, VCMV_Z, v_half_out2, 8, v_word_in2 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHU, VABSDIFF, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWHU, VABSDIFF, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHU, VOR, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWHU, VOR, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHU, VROTR, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWHU, VROTR, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWHU, VCMV_GEZ, v_uhalf_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWHU, VCMV_GEZ, v_uhalf_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVW, VSUBB, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VSUBB, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVW, VAND, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VAND, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVW, VROTL, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VROTL, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVW, VCMV_LTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VCMV_LTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWW, VADDC, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VADDC, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWW, VMULFXP, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VMULFXP, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWW, VSHR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VSHR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWW, VCMV_GTZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVW, VCMV_GTZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWS, VSUB, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VSUB, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWS, VMULHI, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VMULHI, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWS, VSHL, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VSHL, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWS, VCMV_LEZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VCMV_LEZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWS, VCMV_NZ, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VCMV_NZ, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWS, VADD, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VADD, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWS, VMUL, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VMUL, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWS, VXOR, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VXOR, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWS, VMOV, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VMOV, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWS, VCMV_Z, v_word_out1, 8, v_word_in2 );
	vbxasm_acc_3D( SVWS, VCMV_Z, v_word_out2, 8, v_word_in2 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWU, VABSDIFF, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VABSDIFF, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWU, VOR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VOR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWU, VROTR, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VROTR, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWU, VCMV_GEZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VCMV_GEZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWU, VSUBB, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VSUBB, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWU, VAND, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VAND, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWU, VROTL, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VROTL, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SVWWU, VCMV_LTZ, v_uword_out1, 8, v_uword_in2 );
	vbxasm_acc_3D( SVWU, VCMV_LTZ, v_uword_out2, 8, v_uword_in2 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEB, VADDC, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VADDC, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEB, VMULFXP, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VMULFXP, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEB, VSHR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VSHR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEB, VCMV_GTZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VCMV_GTZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBB, VSUB, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VSUB, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBB, VMULHI, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VMULHI, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBB, VSHL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VSHL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBB, VCMV_LEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VCMV_LEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBB, VCMV_NZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEB, VCMV_NZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBS, VADD, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VADD, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBS, VMUL, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VMUL, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBS, VXOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VXOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBS, VMOV, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VMOV, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBS, VCMV_Z, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VCMV_Z, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBS, VABSDIFF, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VABSDIFF, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBS, VOR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VOR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBS, VROTR, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VROTR, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBS, VCMV_GEZ, v_byte_out1, v_byte_in1, v_enum );
	vbxasm_acc_3D( VEBS, VCMV_GEZ, v_byte_out2, v_byte_in1, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBU, VSUBB, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VSUBB, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBU, VAND, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VAND, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBU, VROTL, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VROTL, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBU, VCMV_LTZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VCMV_LTZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBU, VADDC, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VADDC, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBU, VMULFXP, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VMULFXP, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBU, VSHR, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VSHR, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEBBU, VCMV_GTZ, v_ubyte_out1, v_ubyte_in1, v_enum );
	vbxasm_acc_3D( VEBU, VCMV_GTZ, v_ubyte_out2, v_ubyte_in1, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEH, VSUB, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VSUB, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEH, VMULHI, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VMULHI, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEH, VSHL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VSHL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEH, VCMV_LEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VCMV_LEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEH, VCMV_NZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VCMV_NZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHH, VADD, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VADD, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHH, VMUL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VMUL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHH, VXOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VXOR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHH, VMOV, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VMOV, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHH, VCMV_Z, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEH, VCMV_Z, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHS, VABSDIFF, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VABSDIFF, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHS, VOR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VOR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHS, VROTR, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VROTR, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHS, VCMV_GEZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VCMV_GEZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHS, VSUBB, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VSUBB, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHS, VAND, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VAND, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHS, VROTL, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VROTL, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHS, VCMV_LTZ, v_half_out1, v_half_in1, v_enum );
	vbxasm_acc_3D( VEHS, VCMV_LTZ, v_half_out2, v_half_in1, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHU, VADDC, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VADDC, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHU, VMULFXP, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VMULFXP, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHU, VSHR, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VSHR, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHU, VCMV_GTZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VCMV_GTZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHU, VSUB, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VSUB, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHU, VMULHI, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VMULHI, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHU, VSHL, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VSHL, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHU, VCMV_LEZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VCMV_LEZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEHHU, VCMV_NZ, v_uhalf_out1, v_uhalf_in1, v_enum );
	vbxasm_acc_3D( VEHU, VCMV_NZ, v_uhalf_out2, v_uhalf_in1, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEW, VADD, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VADD, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEW, VMUL, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VMUL, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEW, VXOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VXOR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEW, VMOV, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VMOV, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEW, VCMV_Z, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VCMV_Z, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWW, VABSDIFF, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VABSDIFF, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWW, VOR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VOR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWW, VROTR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VROTR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWW, VCMV_GEZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEW, VCMV_GEZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWS, VSUBB, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VSUBB, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWS, VAND, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VAND, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWS, VROTL, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VROTL, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWS, VCMV_LTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VCMV_LTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWS, VADDC, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VADDC, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWS, VMULFXP, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VMULFXP, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWS, VSHR, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VSHR, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWS, VCMV_GTZ, v_word_out1, v_word_in1, v_enum );
	vbxasm_acc_3D( VEWS, VCMV_GTZ, v_word_out2, v_word_in1, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWU, VSUB, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VSUB, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWU, VMULHI, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VMULHI, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWU, VSHL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VSHL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWU, VCMV_LEZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VCMV_LEZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWU, VCMV_NZ, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VCMV_NZ, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWU, VADD, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VADD, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWU, VMUL, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VMUL, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWU, VXOR, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VXOR, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWU, VMOV, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VMOV, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( VEWWU, VCMV_Z, v_uword_out1, v_uword_in1, v_enum );
	vbxasm_acc_3D( VEWU, VCMV_Z, v_uword_out2, v_uword_in1, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEB, VABSDIFF, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VABSDIFF, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEB, VOR, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VOR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEB, VROTR, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VROTR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEB, VCMV_GEZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VCMV_GEZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBB, VSUBB, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VSUBB, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBB, VAND, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VAND, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBB, VROTL, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VROTL, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBB, VCMV_LTZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEB, VCMV_LTZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBS, VADDC, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VADDC, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBS, VMULFXP, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VMULFXP, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBS, VSHR, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VSHR, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBS, VCMV_GTZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VCMV_GTZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBS, VSUB, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VSUB, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBS, VMULHI, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VMULHI, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBS, VSHL, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VSHL, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBS, VCMV_LEZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VCMV_LEZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBS, VCMV_NZ, v_byte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBS, VCMV_NZ, v_byte_out2, 8, 0 );
	errors += compare_accumulated_byte(v_byte_out1 , v_byte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBU, VADD, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VADD, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBU, VMUL, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VMUL, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBU, VXOR, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VXOR, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBU, VMOV, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VMOV, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBU, VCMV_Z, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VCMV_Z, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBU, VABSDIFF, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VABSDIFF, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBU, VOR, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VOR, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBU, VROTR, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VROTR, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEBBU, VCMV_GEZ, v_ubyte_out1, 8, v_enum );
	vbxasm_acc_3D( SEBU, VCMV_GEZ, v_ubyte_out2, 8, 0 );
	errors += compare_accumulated_ubyte(v_ubyte_out1 , v_ubyte_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEH, VSUBB, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VSUBB, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEH, VAND, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VAND, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEH, VROTL, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VROTL, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEH, VCMV_LTZ, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VCMV_LTZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHH, VADDC, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VADDC, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHH, VMULFXP, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VMULFXP, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHH, VSHR, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VSHR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHH, VCMV_GTZ, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEH, VCMV_GTZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHS, VSUB, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VSUB, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHS, VMULHI, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VMULHI, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHS, VSHL, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VSHL, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHS, VCMV_LEZ, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VCMV_LEZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHS, VCMV_NZ, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VCMV_NZ, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHS, VADD, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VADD, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHS, VMUL, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VMUL, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHS, VXOR, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VXOR, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHS, VMOV, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VMOV, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHS, VCMV_Z, v_half_out1, 8, v_enum );
	vbxasm_acc_3D( SEHS, VCMV_Z, v_half_out2, 8, 0 );
	errors += compare_accumulated_half(v_half_out1 , v_half_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHU, VABSDIFF, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VABSDIFF, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHU, VOR, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VOR, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHU, VROTR, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VROTR, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHU, VCMV_GEZ, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VCMV_GEZ, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHU, VSUBB, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VSUBB, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHU, VAND, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VAND, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHU, VROTL, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VROTL, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEHHU, VCMV_LTZ, v_uhalf_out1, 8, v_enum );
	vbxasm_acc_3D( SEHU, VCMV_LTZ, v_uhalf_out2, 8, 0 );
	errors += compare_accumulated_uhalf(v_uhalf_out1 , v_uhalf_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEW, VADDC, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VADDC, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEW, VMULFXP, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VMULFXP, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEW, VSHR, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VSHR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEW, VCMV_GTZ, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VCMV_GTZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWW, VSUB, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VSUB, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWW, VMULHI, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VMULHI, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWW, VSHL, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VSHL, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWW, VCMV_LEZ, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VCMV_LEZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWW, VCMV_NZ, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEW, VCMV_NZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWS, VADD, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VADD, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWS, VMUL, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VMUL, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWS, VXOR, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VXOR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWS, VMOV, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VMOV, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWS, VCMV_Z, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VCMV_Z, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWS, VABSDIFF, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VABSDIFF, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWS, VOR, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VOR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWS, VROTR, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VROTR, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWS, VCMV_GEZ, v_word_out1, 8, v_enum );
	vbxasm_acc_3D( SEWS, VCMV_GEZ, v_word_out2, 8, 0 );
	errors += compare_accumulated_word(v_word_out1 , v_word_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWU, VSUBB, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VSUBB, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWU, VAND, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VAND, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWU, VROTL, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VROTL, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWU, VCMV_LTZ, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VCMV_LTZ, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWU, VADDC, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VADDC, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWU, VMULFXP, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VMULFXP, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWU, VSHR, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VSHR, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}

	vbx_acc_3D( SEWWU, VCMV_GTZ, v_uword_out1, 8, v_enum );
	vbxasm_acc_3D( SEWU, VCMV_GTZ, v_uword_out2, 8, 0 );
	errors += compare_accumulated_uword(v_uword_out1 , v_uword_out2  );
	if(errors){
		printf("Failed @ line %d", __LINE__);
	}


#endif //enable tests
  //-------------------------------------------------

	return errors;
}

int main()
{
	int errors = 0;

	vbx_test_init();

	errors += test_vec_function();

	VBX_TEST_END(errors);
	return 0;
}
