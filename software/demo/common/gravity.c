/* VECTORBLOX MXP SOFTWARE DEVELOPMENT KIT
 * 
 * Copyright (C) 2012-2013 VectorBlox Computing Inc., Vancouver, British Columbia, Canada.
 * All rights reserved.
 * 
 * THIS BETA VERSION SOFTWARE IS PROVIDED ONLY TO PARTIES BOUND UNDER A SIGNED
 * NON-DISCLOSURE AGREEMENT. THIS SOFTWARE IS FOR THE PURPOSES OF EVALUATION ONLY.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, OF THIS BETA VERSION SOFTWARE IS STRICTLY PROHIBITED.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL VECTORBLOX COMPUTING INC. BE LIABLE FOR ANY
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
VBXCOPYRIGHT( gravity )

#include <math.h>
#include "repulse.h"
#define PI 3.14159265

void lissajous( int *gravity_x, int *gravity_y, int cycles )
{
  double div_factor = 32;//4096.0;
  double freq_factor = 120.0/FPS;
  double g_x = sin( 5*PI/180*freq_factor*(cycles/512.0)+PI/2)/div_factor;
	double g_y = sin( 4*PI/180*freq_factor*(cycles/512.0)     )/div_factor;
  *gravity_x = (int)(65536*g_x);
  *gravity_y = (int)(65536*g_y);
}

