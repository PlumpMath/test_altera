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
VBXCOPYRIGHT( board_veek )

#include "board.h"

touchscreen_t *pTouch = NULL;

void board_init()
{
	pTouch = touchscreen_init(IMAGE_WIDTH, IMAGE_HEIGHT);
}

int application_mode(demo_t *pDemo, int local_mode)
{
	int mode = local_mode;
	do{
		if (pTouch->touch_down) {
			if(pTouch->touch_x < IMAGE_WIDTH/3){
				if(pTouch->touch_y < IMAGE_HEIGHT/2){
					if (local_mode%2){
						mode = local_mode - 1; //if vector, go to scalar version
					} else {
						mode = local_mode + 1; //if scalar, go to vector version
					}

				} else {
					mode = MODE_VECTOR_MOTEST;
				}
			} else if(pTouch->touch_x < 2*IMAGE_WIDTH/3) {
				if(pTouch->touch_y < IMAGE_HEIGHT/2){
					mode = MODE_VECTOR_EDGE_DETECT;
				} else {
					mode = MODE_VECTOR_MANDEL;
				}
			} else {
				if(pTouch->touch_y < IMAGE_HEIGHT/2){
					mode = MODE_VECTOR_FACE_DETECT;
				} else {
					mode = MODE_VECTOR_REPULSION;
				}
			}
		}
	}while(touchscreen_get_pen(pTouch));

	return mode;
}

int escape_application(demo_t *pDemo, int local_mode)
{
    if(touchscreen_get_pen(pTouch)){
			if(pTouch->touch_x < 2*IMAGE_WIDTH/3 && 
                pTouch->touch_x > IMAGE_WIDTH/3 &&
                pTouch->touch_y > IMAGE_HEIGHT/2 ){
                if(local_mode == MODE_VECTOR_MANDEL)
                    return 0;
            }

        return 1;
    }

    return 0;
}
