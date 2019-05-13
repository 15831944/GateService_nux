#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "Socket.h"
#include "ComThread.h"
using std::string;


#ifndef UNICODE
#define UNICODE
#endif

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x0600
#endif

#ifndef WIN32_LEAN_AND_MEAN
#define WIN32_LEAN_AND_MEAN
#endif

enum WEBMSG
{
	WEBMSG_FIND=72,//�豸״̬��ѯ
	WEBMSG_CONTROL=55,//�豸��������
	WEBMSG_MODIFY=60,//��ɾ���豸��Ϣ
	WEBMSG_MODIFY_FY=79,//�޸ķ�ӳ��Ϣ
	WEBMSG_MAX
};

void* WebAcceptThread(void* lpParam);
//��httpserver��������
string SendToHttpServer(const char* url,bool bPost=false,string strData="");
bool SendToWebClient(BASE_SOCKET sock,const char* data,int statuscode=200);
