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
VBXCOPYRIGHT( touchscreen )

#include "touchscreen.h"

touchscreen_t *touchscreen_init(int image_width, int image_height)
{
	static touchscreen_t touchscreen;    // use malloc if more than 1 touchscreen!

#ifdef ALT_MODULE_CLASS_touch_panel_spi
	// This is our touch panel
	static alt_touchscreen single_touch; // use malloc if more than 1 touchscreen!

	// Initialize the touch panel
	alt_touchscreen_init(
		&single_touch,
		TOUCH_PANEL_SPI_BASE,
		TOUCH_PANEL_SPI_IRQ,
		TOUCH_PANEL_PEN_IRQ_N_BASE,
		60, // 60 samples/sec
		ALT_TOUCHSCREEN_SWAP_XY);

	// Calibrate the touch panel
	alt_touchscreen_calibrate_upper_right(
		&single_touch,
		3946,          3849, // ADC readings
		image_width-1, 0);   // pixel coords
	alt_touchscreen_calibrate_lower_left(
		&single_touch,
		132, 148,             // ADC readings
		0,   image_height-1); // pixel coords

	printf("Touchscreen Initialized\n");
	touchscreen.pDevice = &single_touch;
#else // not ALT_MODULE_CLASS_touch_panel_spi
	touchscreen.pDevice = MTC_Init(MULTI_TOUCH_BASE, MULTI_TOUCH_IRQ);
	if (!touchscreen.pDevice) {
		printf("Failed to Initialize Multi-Touch\n");
	} else {
		printf("Multi-Touch Initialized\n");
	}    
#endif //ALT_MODULE_CLASS_touch_panel_spi

	return &touchscreen;
}


int touchscreen_get_pen(touchscreen_t *pTouch)
{
#ifdef ALT_MODULE_CLASS_touch_panel_spi
	alt_touchscreen_get_pen(pTouch->pDevice, &pTouch->touch_down, &pTouch->touch_x, &pTouch->touch_y);
	return pTouch->touch_down;
#else
	pTouch->touch_down = MTC_GetStatus(pTouch->pDevice,
									  &pTouch->event,    &pTouch->touch_num,
									  &pTouch->touch_x,  &pTouch->touch_y,
									  &pTouch->touch_x2, &pTouch->touch_y2);
	return pTouch->touch_down;
#endif
}
