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
VBXCOPYRIGHT( tpad_helper )

#include <system.h>

#ifdef ALT_VIP_VFR_0_BASE
#include "Frame_Reader.hpp"
#endif // ALT_VIP_VFR_0_BASE


#include "vip_wrapper_for_c_func.h"
#include "tpad_helpers.h"

#ifdef ALT_VIP_VFR_0_BASE
extern Frame_Reader *the_frame_reader;

void Frame_Reader_stop(int t)
{
  the_frame_reader->stop((bool)t);
}
#endif //ALT_VIP_VFR_0_BASE


#ifdef FRAME_WRITER_0_BASE
volatile alt_irq_context frame_writer_isr_context;
#endif


void disable_tpad()
{

#ifdef ALT_VIP_VFR_0_BASE
  // Remove LCD display DMA activity
  Frame_Reader_init();
  Frame_Reader_stop(1);
#endif

#ifdef FRAME_WRITER_0_BASE
  // Remove camera DMA activity
  alt_ic_irq_disable( 0, FRAME_WRITER_0_IRQ );

  //Clear frame writer registers
  IOWR(FRAME_WRITER_0_BASE, 0/*FRAME_WRITER_CONTROL*/, 0x0);
  while(IORD(FRAME_WRITER_0_BASE, 3/*FRAME_WRITER_NEXT*/));
  while(IORD(FRAME_WRITER_0_BASE, 2/*FRAME_WRITER_CURRENT*/));
  while(IORD(FRAME_WRITER_0_BASE, 1/*FRAME_WRITER_LAST*/));

  // NULL de-registers a pre-existing service routine and disables interrupt
  alt_ic_isr_register( 0, FRAME_WRITER_0_IRQ, NULL, (void *)(&frame_writer_isr_context), 0 );
#endif
}
