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


#ifndef __TOUCHSCREEN_H
#define __TOUCHSCREEN_H

#include <sys/alt_irq.h>
#include "alt_video_display.h"
#include "simple_graphics.h"
#include "vip_wrapper_for_c_func.h"
#include "alt_touchscreen.h"
#ifndef ALT_MODULE_CLASS_touch_panel_spi
#include "multi_touch.h"
#endif

typedef struct {
#ifdef ALT_MODULE_CLASS_touch_panel_spi
	alt_touchscreen *pDevice;
#else
	MTC_INFO *pDevice;
#endif

	int touch_down, touch_x, touch_y;
#ifndef ALT_MODULE_CLASS_touch_panel_spi
	int touch_x2, touch_y2;
	alt_u8 event, touch_num;
#endif
} touchscreen_t;

touchscreen_t *touchscreen_init(int image_width, int image_height);
int touchscreen_get_pen(touchscreen_t *pTouch);

#endif //n__TOUCHSCREEN_H
