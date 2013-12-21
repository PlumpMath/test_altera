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
VBXCOPYRIGHT( altera_demo )

#include "altera_demo.h"

#if PERIODIC_STATS_ENABLE
	alt_u32 writer_isr_calls = 0;
	alt_u32 writer_drops = 0;
	alt_u32 buf_switches = 0;
	vbx_timestamp_t buf_switch_wait = 0;
	alt_alarm stats_alarm;
 
void print_periodic_stats()
{
	printf("Ticks per second = %lu\n", alt_ticks_per_second());
	alt_alarm_start(&stats_alarm,
			alt_ticks_per_second(),
			stats_alarm_callback,
			NULL);
#ifdef VIP_MPFE_0_BASE
	// Reset MPFE counters.
	IOWR(VIP_MPFE_0_BASE, 0, 1);
#endif
}

alt_u32 stats_alarm_callback(void *context)
{
	printf("writer_isr_calls = %lu, writer_drops = %lu, "
			"buf_switches = %lu, wait_ms = %f\n",
			writer_isr_calls, writer_drops, buf_switches, time_to_ms(buf_switch_wait));
	writer_isr_calls = 0;
	writer_drops = 0;
	buf_switches = 0;
	buf_switch_wait = 0;
	// one second until next alarm callback
	return alt_ticks_per_second();
}

#ifdef VIP_MPFE_0_BASE
alt_u32 mpfe_stats_callback(void *context)
{
	int i, j;

	printf("===================================================\n");
	for (i = 0; i < 4; i++) {
		printf("MPFE Master  %d: %10d\n", i, IORD(VIP_MPFE_0_BASE, i));
	}
	// for each slave port
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 5; j++) {
			printf("MPFE Slave %d.%d: %10d\n", i, j,
					IORD(VIP_MPFE_0_BASE, 0x10 + 0x8*i + j));
		}
	}
	return alt_ticks_per_second();
}
#endif // defined(VIP_MPFE_0_BASE
#endif // PERIODIC_STATS_ENABLE

void init_platform()
{
}

void cleanup_demo()
{
}

void cleanup_platform()
{
}

#ifdef __ALT_VIP_ITC
void alt_vip_itc_init()
{
	// Clocked Video Output with Control Port.
	// Note: the Mode configuration registers are write-only!!

	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_MODE_CTRL,          0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_SAMPLE_COUNT,  IMAGE_WIDTH);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F0_LINE_COUNT, IMAGE_HEIGHT);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F1_LINE_COUNT,      0);
#if (IMAGE_WIDTH == 1920) && (IMAGE_HEIGHT == 1080)
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_H_FP,              88);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_H_SYNC,            44);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_H_BLANK,          280);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_V_FP,        	      4);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_V_SYNC,      	      5);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_V_BLANK,     	     45);
#elif (IMAGE_WIDTH == 1280) && (IMAGE_HEIGHT == 720)
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_H_FP,             110);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_H_SYNC,            40);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_H_BLANK,          370);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_V_FP,        	      5);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_V_SYNC,      	      5);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_V_BLANK,     	     30);
#endif
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F0_V_FP,     	      0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F0_V_SYNC,   	      0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F0_V_BLANK,  	      0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_ACTIVE_PICT_LINE,   0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F0_V_RISING_LINE,   0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F_RISING_LINE,      0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F_FALLING_LINE,     0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_VID_STD,            0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_SOF_SAMPLE,         0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_SOF_LINE,           0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_VCOCLK_CYCLES,      0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_ANC_LINE,	          0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_F0_ANC_LINE,        0);
	IOWR(ALT_VIP_ITC_0_BASE, OFFS_ITC_MODE_VALID,         1);

	IOWR(ALT_VIP_ITC_0_BASE, 0, 1); // go
}
#endif // defined(ALT_VIP_ITC)

#ifdef __STREAM_WRITER
#if HANDLE_CTI_CTRL_PKTS
// stream_writer init with support for control data packets from alt_vip_cti.
// INCOMPLETE.
void stream_writer_init_cti(demo_t *pDemo)
{
	alt_u32 frame_buffer_desc;
	alt_u32 ctrl_pkt_buffer_desc;

	//Clear return buffer in case it wasn't reset
	while(IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_ADDRESS));

	//Setup interrupts
	//alt_ic_isr_register(0, STREAM_WRITER_0_IRQ, stream_writer_isr_cti, (void *)(frame_writer_isr_context), 0);
	alt_ic_isr_register(0, STREAM_WRITER_0_IRQ, stream_writer_isr_cti, (void *)(pDemo), 0);

	// No interrupt on control packet
	ctrl_pkt_buffer_desc = STREAM_WRITER_BURST_SIZE_BYTES | STREAM_WRITER_STARTOFPACKET_MASK;
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_STATUS_LENGTH, ctrl_pkt_buffer_desc);
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(ctrl_pkt_buffer[0]));

	//Set length to image size, wait for start of packet, interrupt after buffer sent
	frame_buffer_desc = (IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(pixel)) |
		STREAM_WRITER_STARTOFPACKET_MASK | STREAM_WRITER_INTERRUPT_MASK;
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_STATUS_LENGTH, frame_buffer_desc);
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(pDemo->buffer[BUFFER_TRANSFERRING]));

	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_STATUS_LENGTH, ctrl_pkt_buffer_desc);
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(ctrl_pkt_buffer[1]));

	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_STATUS_LENGTH, frame_buffer_desc);
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(pDemo->buffer[BUFFER_NEXT_TRANSFER]));
}

#else // !HANDLE_CTI_CTRL_PKTS
void stream_writer_init(demo_t *pDemo)
{
	//Set length to image size, wait for start of packet, interrupt after buffer sent
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_STATUS_LENGTH,
			(IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(pixel)) |
			STREAM_WRITER_STARTOFPACKET_MASK |
			STREAM_WRITER_INTERRUPT_MASK);

	//Clear frame writer registers in case it wasn't reset
	while(IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_ADDRESS));

	//Setup interrupts
	//alt_ic_isr_register(0, STREAM_WRITER_0_IRQ, frame_writer_isr, (void *)(frame_writer_isr_context), 0);
	alt_ic_isr_register(0, STREAM_WRITER_0_IRQ, frame_writer_isr, (void *)(pDemo), 0);

	//Start transferring the first frame
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(pDemo->buffer[BUFFER_TRANSFERRING]));
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(pDemo->buffer[BUFFER_NEXT_TRANSFER]));
}
#endif
#endif // defined(__STREAM_WRITER)

#ifdef __FRAME_WRITER
void frame_writer_init(demo_t *pDemo)
{
	//Clear frame writer registers
	IOWR(FRAME_WRITER_0_BASE, FRAME_WRITER_CONTROL, 0x0);
	while(IORD(FRAME_WRITER_0_BASE, FRAME_WRITER_NEXT));
	while(IORD(FRAME_WRITER_0_BASE, FRAME_WRITER_CURRENT));
	while(IORD(FRAME_WRITER_0_BASE, FRAME_WRITER_LAST));

	//Setup interrupts
	IOWR(FRAME_WRITER_0_BASE, FRAME_WRITER_CONTROL, 0x1);
	//alt_ic_isr_register(0, FRAME_WRITER_0_IRQ, frame_writer_isr, (void *)(frame_writer_isr_context), 0);
	alt_ic_isr_register(0, FRAME_WRITER_0_IRQ, frame_writer_isr, (void *)(pDemo), 0);
	//Start transferring the first frame
	IOWR(FRAME_WRITER_0_BASE, FRAME_WRITER_NEXT, (int)(pDemo->buffer[BUFFER_TRANSFERRING]));
	while(IORD(FRAME_WRITER_0_BASE, FRAME_WRITER_NEXT));
	IOWR(FRAME_WRITER_0_BASE, FRAME_WRITER_NEXT, (int)(pDemo->buffer[BUFFER_NEXT_TRANSFER]));
}
#endif

void frame_writer_isr(void *isr_context)
{
	demo_t *pDemo = (demo_t *)isr_context;
	pixel *temp;
	pixel *returned;

	alt_ic_irq_disable(0, FRAME_WRITER_0_IRQ);

#ifdef STREAM_WRITER_0_BASE
	IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_STATUS_LENGTH);
#endif
	returned = (pixel *)IORD(FRAME_WRITER_0_BASE, FRAME_WRITER_LAST);

	temp = (pixel *)pDemo->buffer[BUFFER_READY];
	pDemo->buffer[BUFFER_READY]         = pDemo->buffer[BUFFER_TRANSFERRING];
	pDemo->buffer[BUFFER_TRANSFERRING]  = pDemo->buffer[BUFFER_NEXT_TRANSFER];
	pDemo->buffer[BUFFER_NEXT_TRANSFER] = temp;

	//If we dropped frames, put multiple in the queue
#ifdef STREAM_WRITER_0_BASE
	if(IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_STATUS_LENGTH)){
		IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(pDemo->buffer[BUFFER_TRANSFERRING]));
	}
#else
	if(!IORD(FRAME_WRITER_0_BASE, FRAME_WRITER_CURRENT)){
		IOWR(FRAME_WRITER_0_BASE, FRAME_WRITER_NEXT, (int)(pDemo->buffer[BUFFER_TRANSFERRING]));
	}
#endif
	//Write next frame to transfer,
	IOWR(FRAME_WRITER_0_BASE, FRAME_WRITER_NEXT, (int)(pDemo->buffer[BUFFER_NEXT_TRANSFER]));
	pDemo->frame_ready = 1;

#if PERIODIC_STATS_ENABLE
	writer_isr_calls++;
#endif
	alt_ic_irq_enable(0, FRAME_WRITER_0_IRQ);
}

#if defined(__STREAM_WRITER) && HANDLE_CTI_CTRL_PKTS
///////////////////////////////////////////////////////////////////////////
// stream_writer ISR with support for control data packets from alt_vip_cti
void stream_writer_isr_cti(void *isr_context)
{
	demo_t *pDemo = (demo_t *)isr_context;
	pixel *temp;
	pixel *returned;
	alt_u32 r;

	alt_ic_irq_disable(0, STREAM_WRITER_0_IRQ);

#define ISR_ITER 0

#if ISR_ITER
	if (writer_isr_calls < ISR_ITER) {
		printf("=======================\n");
		r = IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_BUFFER_LIST_STATUS);
		printf("buf_list_status = %08lx\n", r);
	}
#endif

	r = IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_STATUS_LENGTH);
	returned = (pixel *)IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_ADDRESS);
#if ISR_ITER
	if (writer_isr_calls < ISR_ITER) {
		printf("status = %08lx, addr = %08lx\n", r, (alt_u32) returned);
		printf("  sop=%lu eop=%lu bp=%lu intr=%lu len=%lu\n",
				(r >> 31) & 0x1,
				(r >> 30) & 0x1,
				(r >> 29) & 0x1,
				(r >> 24) & 0x1,
				r & 0xffffff);
		printf("xferring=%08lx\n", (alt_u32) pDemo->buffer[BUFFER_TRANSFERRING]);
		printf("nextxfer=%08lx\n", (alt_u32) pDemo->buffer[BUFFER_NEXT_TRANSFER]);
		printf("ready   =%08lx\n", (alt_u32) pDemo->buffer[BUFFER_READY]);
		printf("reading =%08lx\n", (alt_u32) pDemo->buffer[BUFFER_READING]);
		printf("process =%08lx\n", (alt_u32) pDemo->buffer[BUFFER_PROCESSING]);
	}
#endif

	temp = (pixel *)pDemo->buffer[BUFFER_READY];
	pDemo->buffer[BUFFER_READY]         = pDemo->buffer[BUFFER_TRANSFERRING];
	pDemo->buffer[BUFFER_TRANSFERRING]  = pDemo->buffer[BUFFER_NEXT_TRANSFER];
	pDemo->buffer[BUFFER_NEXT_TRANSFER] = temp;

	//If we dropped frames, put multiple in the queue
	if((r = IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_STATUS_LENGTH))){
#if ISR_ITER
		if (writer_isr_calls < ISR_ITER) {
			alt_u32 t = (alt_u32) IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_RETURN_ADDRESS);
			printf("status = %08lx, addr = %08lx\n", r, t);
			printf("  sop=%lu eop=%lu bp=%lu intr=%lu len=%lu\n",
					(r >> 31) & 0x1,
					(r >> 30) & 0x1,
					(r >> 29) & 0x1,
					(r >> 24) & 0x1,
					r & 0xffffff);
#if 0
			int i;
			for (i = 0; i < 9; i++) {
				printf("%d: %08lx\n", i, (alt_u32) IORD(t, i));
			}
#endif
		}
#endif
		// usleep(620);
		IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(pDemo->buffer[BUFFER_TRANSFERRING]));
#if PERIODIC_STATS_ENABLE
		writer_drops++;
#endif
	}
	//Write next frame to transfer,
	IOWR(STREAM_WRITER_0_BASE, STREAM_WRITER_NEXT_ADDRESS, (int)(pDemo->buffer[BUFFER_NEXT_TRANSFER]));

#if ISR_ITER
	if (writer_isr_calls < ISR_ITER) {
		r = IORD(STREAM_WRITER_0_BASE, STREAM_WRITER_BUFFER_LIST_STATUS);
		printf("buf_list_status = %08lx\n", r);
	}
#endif

	pDemo->frame_ready = 1;

#if PERIODIC_STATS_ENABLE
	writer_isr_calls++;
#endif

	alt_ic_irq_enable(0, STREAM_WRITER_0_IRQ);
}

#endif // defined(__STREAM_WRITER) && HANDLE_CTI_CTRL_PKTS

vbx_timestamp_t switch_buffers(demo_t* pDemo)
{
	alt_video_display *pDisplay = pDemo->pDisplay;
	pixel *temp;
	vbx_timestamp_t time_start, time_stop, wait_time;

	//Update frame reader to output last processed
	IOWR(ALT_VIP_VFR_0_BASE, FRAME_READER_PB0_BASE, (int)(pDemo->buffer[BUFFER_PROCESSING]));

	//Record how many cycles were spend waiting for the last frame from the video input to finish transferring
	if(pDemo->frame_ready){
		wait_time = 0;
	}
	else {
		time_start = vbx_timestamp();
		while(!(pDemo->frame_ready)){
			usleep(100);//Don't hog bus
		}
		time_stop = vbx_timestamp();
		wait_time = time_stop - time_start;
	}

	//Move buffer pointers
	alt_ic_irq_disable(0, FRAME_WRITER_0_IRQ);
	temp = pDemo->buffer[BUFFER_READING];
	pDemo->buffer[BUFFER_READING] = pDemo->buffer[BUFFER_PROCESSING];
	pDemo->buffer[BUFFER_PROCESSING] = pDemo->buffer[BUFFER_READY];
	pDemo->buffer[BUFFER_READY] = temp;
#if !SYSTEM_DE2_115
	pDemo->frame_ready = 0;
#endif
	alt_ic_irq_enable(0, FRAME_WRITER_0_IRQ);

	//Update pointer to processing display
	pDisplay->buffer_ptrs[0]->buffer = pDemo->buffer[BUFFER_PROCESSING];

#if PERIODIC_STATS_ENABLE
	buf_switches++;
	buf_switch_wait += wait_time;
#endif

	return wait_time;
}

vbx_timestamp_t frame_buffer_update(demo_t *pDemo, int uses_video_in)
{
	vbx_timestamp_t wait_time;
	//Update buffers; will delay if not ready
#if DISABLE_WRITER == 0
	if (uses_video_in) {
		wait_time = switch_buffers(pDemo);
	} else {
		wait_time = 0;
	}
#else
	wait_time = 0;
#endif

	return wait_time;
}

void display_init(alt_video_display *pDisplay, pixel **buffer)
{
	//Initialize display.  Using this for altera video processing functions only,
	//custom buffer swapping routines used
	pDisplay->buffer_ptrs[0]            = (alt_video_frame*)malloc(sizeof(alt_video_frame));
	pDisplay->buffer_ptrs[0]->desc_base = NULL;
	pDisplay->buffer_ptrs[0]->buffer    = (void *)buffer[BUFFER_READING];
	pDisplay->width                     = IMAGE_WIDTH;
	pDisplay->height                    = IMAGE_HEIGHT;
	pDisplay->color_depth               = IMAGE_COLOR_DEPTH;
	pDisplay->num_frame_buffers         = 1;
	pDisplay->bytes_per_frame           = IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(pixel);
	pDisplay->bytes_per_pixel           = sizeof(pixel);
	pDisplay->buffer_being_displayed    = 0;
	pDisplay->buffer_being_written      = 0;
	pDisplay->descriptors_per_frame     = 1;
}

void frame_reader_init(pixel **buffer)
{
	//Initialize frame reader and start reading
	Frame_Reader_init();
	Frame_Reader_set_frame_0_properties((int)(buffer[BUFFER_READING]),
			IMAGE_WIDTH*IMAGE_HEIGHT/VFR_PIXELS_PER_WORD,
			IMAGE_WIDTH*IMAGE_HEIGHT,
			IMAGE_WIDTH,
			IMAGE_HEIGHT,
			3);
	Frame_Reader_switch_to_pb0();
	Frame_Reader_start();
	printf("Frame Reader Initialized\n");
}

void writer_init(demo_t *pDemo)
{
#ifdef __STREAM_WRITER
#if HANDLE_CTI_CTL_PKTS
	stream_writer_init_cti(pDemo);
#else
	stream_writer_init(pDemo);
#endif
#else // !defined(__STREAM_WRITER)
	frame_writer_init(pDemo);
#endif

#ifdef __ALT_VIP_CTI
	// Clocked Video Input with Control Port
	IOWR(ALT_VIP_CTI_0_BASE, 0, 1); // go
#endif
}

int frame_buffer_init(demo_t *pDemo)
{
	//allocate array of buffer pointers
	pDemo->buffer = (pixel **)vbx_shared_malloc(6*sizeof(pixel *));
	pDemo->buffer = (pixel **)vbx_remap_cached(pDemo->buffer, 6*sizeof(pixel *));

	int i;
	for(i = 0; i < VIDEO_BUFFERS; i++){
		pDemo->buffer[i] = (pixel *)vbx_shared_malloc(IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(pixel));
		pDemo->buffer[i] = (pixel *)vbx_remap_cached(pDemo->buffer[i], IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(pixel));
		if(pDemo->buffer[i] == NULL){
			printf("Video buffer malloc failed!\n");
			return -1;
		}
	}
	pDemo->short_buffer = (unsigned short *)vbx_shared_malloc(IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(unsigned short));
	pDemo->short_buffer = (unsigned short *)vbx_remap_cached(pDemo->short_buffer, IMAGE_WIDTH*IMAGE_HEIGHT*sizeof(unsigned short));
	if(pDemo->short_buffer == NULL){
		printf("Video buffer malloc failed!\n");
		return -1;
	}

	pDemo->frame_ready = 1;

	return 0;
}

int init_demo(demo_t *pDemo)
{
	pDemo->pDisplay = (alt_video_display *)malloc(sizeof(alt_video_display));

	// allocate frame buffers and short buffer 
	if (frame_buffer_init(pDemo) < 0){
		return -1;
	}


#if 0
#if HANDLE_CTI_CTRL_PKTS
	pixel *ctrl_pkt_buffer[NUM_CTRL_PKT_BUFFERS];
	// allocate buffers for control packets from alt_vip_cti .
	int i;
	for (i = 0; i < NUM_CTRL_PKT_BUFFERS; i++) {
		ctrl_pkt_buffer[i] = (pixel *) vbx_shared_malloc(STREAM_WRITER_BURST_SIZE_BYTES);
	}
#endif

#ifdef __ALT_VIP_ITC
	alt_vip_itc_init();
#endif
#endif

	// initialize display...
	display_init(pDemo->pDisplay, pDemo->buffer);

	// initialize frame reader...
	frame_reader_init(pDemo->buffer);

	// initialize any board specific features (eg. touchscreen, mirror-mode, ...)
	board_init();

#if !SYSTEM_DE2_115
	writer_init(pDemo);
#endif

#if DEBUG
	print_periodic_stats();
#endif

	return 0;

}

