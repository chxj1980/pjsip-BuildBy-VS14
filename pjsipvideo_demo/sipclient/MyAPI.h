// MyAPI.h: interface for the CMyAPI class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYAPI_H__878C56E9_6604_4E01_9A1F_F649A0C76BCD__INCLUDED_)
#define AFX_MYAPI_H__878C56E9_6604_4E01_9A1F_F649A0C76BCD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "FramedStreamBufQueue.hh"

//#include "RTSPClient.h"
//#include "MPEG4VideoStreamServerMediaSubsession.hh"

typedef struct StreamFormat
{
	  
    int type;	// 1 means this is the audio stream buffer queue, 2 means video stream buffer queue
	//��Ƶ���
	unsigned short videoWidth;
	unsigned short videoHeight;
	unsigned videoFPS;

	//��Ƶ���

}STREAMFORMAT;

class CMyAPI  
{
public:
	CMyAPI();
	virtual ~CMyAPI();

public:
	static int BufQueueInput(StreamBufQueue_t *pBufQue,unsigned char* buf,UINT len);
	static int BufQueueOutput(StreamBufQueue_t *pBufQue,unsigned char* buf,UINT len);
	
	static int BufQueueInit(StreamBufQueue_t *pBufQue,int streamType = VIDEO_STREAM_BUFQUE);//1,��Ƶ��2��Ƶ	
	
	static int BufQueueFree(StreamBufQueue_t *pBufQue);//
	static int GetBufQueueSize(StreamBufQueue_t *pBufQue);//

	
	static int SetBufQueueSize(StreamBufQueue_t *pBufQue,UINT uSize);//���õ�ǰbuffer�Ĵ�С��tail-head=������


	static int GetStreamFormat(StreamBufQueue_t *pBufQue,STREAMFORMAT *pStreamFormat);//��ȡ����ʽ
	
	
	static void GetExeDir(char* pstr);
	static int ChangeFileName(CString & strOldName);
	
};

#endif // !defined(AFX_MYAPI_H__878C56E9_6604_4E01_9A1F_F649A0C76BCD__INCLUDED_)
