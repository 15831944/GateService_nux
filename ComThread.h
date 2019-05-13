#pragma once
#ifdef WIN32
#include "windows.h"
#endif

#ifdef WIN32
#define THREAD HANDLE
#endif

#ifdef linux
#define THREAD pthread_t
#include <pthread.h>
#endif

struct sThreadParm
{
	void* arg;//�̲߳���
	volatile bool run;//��־ ���false�Ļ� �߳���Ҫ�˳�
	THREAD handle;//��Ҫ������ֵ
};
typedef void* (*pCallBack_ThreadFun)(void* arg);
bool ComCreateThread(pCallBack_ThreadFun callback,sThreadParm* parm);
bool ComStopThread(sThreadParm* parm);
