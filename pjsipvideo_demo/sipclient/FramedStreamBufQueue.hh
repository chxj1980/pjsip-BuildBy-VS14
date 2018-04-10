/*****************************************************************************
*
*  Copyright WIS Technologies (c) (2003)
*  All Rights Reserved
*
*****************************************************************************
*
*  FILE: 
*    FramedStreamBufQueue.hh
*
*  DESCRIPTION:
*  This file define the buffer queue structure, which is used by Go-Server module and FramedStreamSource.
*
* AUTHOR:
*	Max song
*
*
****************************************************************************/

#ifndef  _FRAMED_STREAM_BufQueue_HH
#define _FRAMED_STREAM_BufQueue_HH

#include <windows.h>//#include "pthread.h"


#define MAX_LEN_BUFFER (1920*1080*3) //200000 //200 k 600000
#define MAX_LEN_BUFFER_AUDIO 10000 //10 k ��Ƶbuffer
#define MAX_NUM_BUFFER 8 //128��32,64
#define AUDIO_STREAM_BUFQUE	1
#define VIDEO_STREAM_BUFQUE	2

struct stream_buf_s
{
    char *p; //buffer pointer
    char *cur;	//Current position
    int len;  //the current string length
    struct timeval creationTime; // when the data was created
};

typedef struct StreamBufQueue_s
{
    struct stream_buf_s stream_buf[MAX_NUM_BUFFER];	//stream buffer queue
    int head;	//queue header, value is between 0 - MAX_NUM_BUFFER
    int tail;	//queue tail, value is between 0 - MAX_NUM_BUFFER    
    int type;	// 1 means this is the audio stream buffer queue, 2 means video stream buffer queue

//while type=2����video��ʱ�����¼���������Ч
	unsigned short videoWidth;
	unsigned short videoHeight;
	unsigned videoFPS;
	
//while type=1����audio��ʱ�����¼���������Ч
	unsigned short wFormatTag;	//��ʽ
	unsigned short wBitsPerSample;	//λ
	unsigned nChannels;	//������
	unsigned nSamplesPerSec;	//����Ƶ��

   CRITICAL_SECTION mutex;	// pthread_mutex_t mutex;		//pthread mutex
} StreamBufQueue_t; 

#endif /*_FRAMED_STREAM_BufQueue_HH*/

