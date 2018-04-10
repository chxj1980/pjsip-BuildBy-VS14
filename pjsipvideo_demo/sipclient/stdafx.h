// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�

#pragma once

#ifndef _SECURE_ATL
#define _SECURE_ATL 1
#endif

#ifndef VC_EXTRALEAN
#define VC_EXTRALEAN            // �� Windows ͷ���ų�����ʹ�õ�����
#endif

#pragma warning( disable : 4996)

#include "targetver.h"

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS      // ĳЩ CString ���캯��������ʽ��

// �ر� MFC ��ĳЩ�����������ɷ��ĺ��Եľ�����Ϣ������
#define _AFX_ALL_WARNINGS

#include <afxwin.h>         // MFC ��������ͱ�׼���
#include <afxext.h>         // MFC ��չ


#include <afxdisp.h>        // MFC �Զ�����



#ifndef _AFX_NO_OLE_SUPPORT
#include <afxdtctl.h>           // MFC �� Internet Explorer 4 �����ؼ���֧��
#endif
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>                     // MFC �� Windows �����ؼ���֧��
#endif // _AFX_NO_AFXCMN_SUPPORT

#ifdef DEBUG
#pragma comment(lib, "libpjproject-i386-Win32-vc8-Debug.lib")
#else
#pragma comment(lib, "libpjproject-i386-Win32-vc8-Release.lib")
#endif

extern "C"
{
#include "libavutil/avstring.h"
//#include "libavutil/colorspace.h"
#include "libavutil/mathematics.h"
#include "libavutil/pixdesc.h"
#include "libavutil/imgutils.h"
#include "libavutil/dict.h"
#include "libavutil/parseutils.h"
#include "libavutil/samplefmt.h"
#include "libavutil/avassert.h"
#include "libavutil/time.h"
//#include "libavutil/colorspace.h"
#include "libavformat/avformat.h"
#include "libavdevice/avdevice.h"
#include "libswscale/swscale.h"
#include "libavutil/opt.h"
#include "libavcodec/avfft.h"
#include "libswresample/swresample.h"
}

#define INT64_MIN        (-9223372036854775807LL-1LL)
#define INT64_MAX        +9223372036854775807LL
#define _CRT_SECURE_NO_WARNINGS


//#pragma comment(lib, "SDL.lib")
//#pragma comment(lib, "SDLmain.lib")

#pragma comment(lib, "avcodec.lib")
#pragma comment(lib, "avformat.lib")
#pragma comment(lib, "avutil.lib")
//#pragma comment(lib, "avfilter.lib")
//#pragma comment(lib, "avdevice.lib")
//#pragma comment(lib, "postproc.lib")
#pragma comment(lib, "swresample.lib")
#pragma comment(lib, "swscale.lib")

//#include "curl/curl.h"
#include <vfw.h>
#pragma comment(lib, "vfw32.lib")


//#pragma comment(lib, "libcurl.lib")

#define SAFE_RELEASE(x) { if (x) x->Release(); x = NULL; }
#define SAFE_DELETE(p)       { if(p) { delete (p);     (p)=NULL; } }
#define CHECK_HR(hr,f){ if( FAILED(hr)){f; return hr; /*throw hr*/}}
#define SAFE_RETURN(x)	{HRESULT hr = (x); if(hr != S_OK) return hr;}







