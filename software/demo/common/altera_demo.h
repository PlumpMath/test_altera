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


#ifndef __ALTERA_DEMO_H
#define __ALTERA_DEMO_H

#include <unistd.h>
#include <io.h>
#include "system.h"

#include "demo.h"
#include "touchscreen.h"

#define FRAME_READER_PB0_BASE 4

//Stream writer registers; could be made into a HAL include
#define STREAM_WRITER_NEXT_STATUS_LENGTH   0
#define STREAM_WRITER_NEXT_ADDRESS         1
#define STREAM_WRITER_RETURN_STATUS_LENGTH 2
#define STREAM_WRITER_RETURN_ADDRESS       3
#define STREAM_WRITER_BUFFER_LIST_STATUS   4

#define STREAM_WRITER_BUFFER_LIST_FULL_MASK 0x80000000

//Length is the lower 24 bits of status/length register
#define STREAM_WRITER_LENGTH_MASK        0x00FFFFFF

//Status bits
#define STREAM_WRITER_STARTOFPACKET_MASK 0x80000000
#define STREAM_WRITER_ENDOFPACKET_MASK   0x40000000
#define STREAM_WRITER_BACKPRESSURE_MASK  0x20000000
#define STREAM_WRITER_INTERRUPT_MASK     0x01000000

//If using stream writer, for now just pretend it's frame writer
#ifdef STREAM_WRITER_0_BASE
#define FRAME_WRITER_0_BASE STREAM_WRITER_0_BASE
#define FRAME_WRITER_0_IRQ  STREAM_WRITER_0_IRQ
#define FRAME_WRITER_LAST   STREAM_WRITER_RETURN_ADDRESS
#define FRAME_WRITER_NEXT   STREAM_WRITER_NEXT_ADDRESS
#else
//Frame writer registers; could be made into a HAL include
#define FRAME_WRITER_CONTROL 0
#define FRAME_WRITER_LAST    1
#define FRAME_WRITER_CURRENT 2
#define FRAME_WRITER_NEXT    3
#endif

#define PERIODIC_STATS_ENABLE 1
#if PERIODIC_STATS_ENABLE
void print_periodic_stats();
alt_u32 stats_alarm_callback(void *context);
#ifdef VIP_MPFE_0_BASE
alt_u32 mpfe_stats_callback(void *context);
#endif // defined(VIP_MPFE_0_BASE
#endif // PERIODIC_STATS_ENABLE

#ifdef __ALT_VIP_ITC
#define OFFS_ITC_MODE_CTRL         5
#define OFFS_ITC_SAMPLE_COUNT      6
#define OFFS_ITC_F0_LINE_COUNT     7
#define OFFS_ITC_F1_LINE_COUNT     8
#define OFFS_ITC_H_FP              9
#define OFFS_ITC_H_SYNC           10
#define OFFS_ITC_H_BLANK          11
#define OFFS_ITC_V_FP             12
#define OFFS_ITC_V_SYNC           13
#define OFFS_ITC_V_BLANK          14
#define OFFS_ITC_F0_V_FP          15
#define OFFS_ITC_F0_V_SYNC        16
#define OFFS_ITC_F0_V_BLANK       17
#define OFFS_ITC_ACTIVE_PICT_LINE 18
#define OFFS_ITC_F0_V_RISING_LINE 19
#define OFFS_ITC_F_RISING_LINE    20
#define OFFS_ITC_F_FALLING_LINE   21
#define OFFS_ITC_VID_STD          22
#define OFFS_ITC_SOF_SAMPLE       23
#define OFFS_ITC_SOF_LINE         24
#define OFFS_ITC_VCOCLK_CYCLES    25
#define OFFS_ITC_ANC_LINE         26
#define OFFS_ITC_F0_ANC_LINE      27
#define OFFS_ITC_MODE_VALID       28

void alt_vip_itc_init();
#endif

#ifdef __STREAM_WRITER
#if HANDLE_CTI_CTRL_PKTS
// stream_writer init with support for control data packets from alt_vip_cti.
// INCOMPLETE.
void stream_writer_init_cti(demo_t *pDemo);

#else // !HANDLE_CTI_CTRL_PKTS
void stream_writer_init(demo_t *pDemo);
#endif
#endif // defined(__STREAM_WRITER)

#ifdef __FRAME_WRITER
void frame_writer_init(demo_t *pDemo);
#endif

#if defined(__FRAME_WRITER) || defined(__STREAM_WRITER)
void frame_writer_isr(void *isr_context);
#endif

#if defined(__STREAM_WRITER) && HANDLE_CTI_CTRL_PKTS
///////////////////////////////////////////////////////////////////////////
// stream_writer ISR with support for control data packets from alt_vip_cti
void stream_writer_isr_cti(void *isr_context);
#endif // defined(__STREAM_WRITER) && HANDLE_CTI_CTRL_PKTS

vbx_timestamp_t switch_buffers(demo_t* pdemo );
vbx_timestamp_t frame_buffer_update(demo_t* pdemo,  int uses_video_in);
void display_init(alt_video_display *display, pixel **buffer);
void frame_reader_init(pixel **buffer);

void writer_init(demo_t *pDemo);
void init_platform();
void cleanup_platform();
void cleanup_demo();
int init_demo(demo_t *pDemo);

#endif //n__ALTERA_DEMO_H
