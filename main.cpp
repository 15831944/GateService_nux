#include <iostream>
#include <sstream>
#include <string.h>
#include <time.h>
#include <fstream>
#include "GateClient.h"
#include "WebClient.h"
#include "globle.h"
#include "IFSC_079.h"
#include "ComThread.h"
using namespace std;
int main(int argc, char *argv[])
{
	do 
	{
		g_globle=new GlobleAll();
		if(!g_globle->InitGloble())
		{
			break;
		}
		if (!g_globle->ReadConf())
		{	
			break;
		}

		/*if (argc<=1)
		{
		Log("��Ч����");
		break;
		}
		else
		{
		g_globle->m_configPath=argv[1];
		Log("����argv[1]:%s",g_globle->m_configPath.c_str());
		if (!g_globle->ReadConf())
		{	
		break;
		}
		}*/

		//��ȡբ���б�
		string strUrl = "http://"+g_globle->m_WebSerIP+g_globle->m_GateListUrl;
		Log("���ڻ�ȡբ���б�...");

		string strGateList=SendToHttpServer(strUrl.c_str());
		if(strGateList.empty())
		{		
			//break;
		}
		else if (!g_globle->m_gateClient->AddGateList(strGateList.c_str()))
		{
			//break;
		}

		//��ȡ��ӳ��Ϣ
		strUrl = "http://"+g_globle->m_WebSerIP+g_globle->m_79Url;
		Log("���ڻ�ȡ��ӳ��Ϣ...");
		string strFilmList=SendToHttpServer(strUrl.c_str());
		if (strFilmList!="\"Bad Request\"" && g_globle->m_gateClient->m_fsc_079->PraseData(strFilmList))
		{
			//break;
		}

		sThreadParm WebAcceptPar;
		ComCreateThread(WebAcceptThread,&WebAcceptPar);

		sThreadParm GateAcceptPar;
		ComCreateThread(GateAcceptThread,&GateAcceptPar);

		msleep(1000);
		while(GateAcceptPar.run && WebAcceptPar.run)
		{
			msleep(1000);
		}
		WebAcceptPar.run=false;
		GateAcceptPar.run=false;
	} while (0);
	
	Log("GateService end!");
	if (g_globle)
	{
		if (g_globle->m_gateClient)
		{
			g_globle->m_gateClient->ReleaseMemory();
		}
		delete g_globle;
	}
	return 0;
}