#pragma once
#include <string>
#include <vector>
#include "globle.h"
#include "ComThread.h"
#include "IFAL_074.h"

using std::vector;
using std::string;


//web���ƶ��·���բ���б�
typedef struct GATEMSG
{
	string strGateID;//բ�����
	string strGateIP;//բ��IP
};

//բ���յ��豸���Ʊ��ĺ󣬷��񽫴��������ظ����ƶ�
typedef struct GATECONTROL_BACK
{
	unsigned char MsgNumber;//��ˮ��
	string strGateID;//բ�����
	BASE_SOCKET clientSock;
};

typedef struct _NODE_ 
{
	BASE_SOCKET s;
	sockaddr_in Addr;
	sThreadParm par;//�߳���Ϣ
	string strGateID;//բ�����
	CIFAL_074* fal_074;//�豸ȫ״̬
	unsigned char DownMsgNumber;//KS�·���Ϣ��ˮ��(129~255)
	vector<GATECONTROL_BACK> vGateBack;
	_NODE_* pNext;

	_NODE_()
	{
		s=INVALID_BASE_SOCKET;
		fal_074=NULL;
		DownMsgNumber=0x81;
		pNext=NULL;
	}

	~_NODE_()
	{
		par.run=false;
		RELEASE_NEW(fal_074);
		RELEASE_SOCKET(s);
	}
}Node,*pNode;

class CIFSC_079;
class CGateClient
{
public:
	CGateClient();
	~CGateClient();

public:
	vector<GATEMSG> vGate;
	vector<Node*> vNode;
	CIFSC_079* m_fsc_079;//�����ӳ��Ϣ

	BASE_SOCKET m_SerSocket;

#ifdef WIN32
	HANDLE Device_mutex;
	HANDLE FyMsg_mutex;
#elif linux
	pthread_mutex_t Device_mutex;
	pthread_mutex_t FyMsg_mutex;
#endif

public:
	//����բ���б�
	bool AddGateList(const char* pContent);
	//ɾ��ָ��բ��
	void DeleteGate(Node* pnode);
	//���բ���߳�
	bool AddClientList(BASE_SOCKET s,sockaddr_in addr);
	//���ͱ��ģ�sbuf:���� len:���ĳ���
	void SendToGateClient(BASE_SOCKET sClient,char* sbuf,int len);
	//��ϱ���packType:��Ϣ������ MsgNumber����ˮ�� dataLen�����ݳ��ȣ�data:����,len:�������ݳ���
	char* CombinetPacket(char packType,unsigned char MsgNumber,short dataLen,char* data,int& len); 
	//�ͷ������ڴ�
	void ReleaseMemory();
};

void* GateAcceptThread(void* lpParam);
//բ���߳�
void* GateClientThread(void* lpParam);