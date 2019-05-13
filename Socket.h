#ifndef BASE_SOCKET_SOURCE
#define BASE_SOCKET_SOURCE

#ifdef WIN32
#define BASE_SOCKET UINT_PTR
#define INVALID_BASE_SOCKET  (BASE_SOCKET)(~0)
#define DLLEXPORT _declspec(dllexport)
#define SOCKET_LEN_T int
#endif

#ifdef WIN32
#include <Winsock2.h>
#include <Ws2tcpip.h>
#pragma comment(lib,"Ws2_32.lib")
#endif

#ifdef linux
#define SOCKET_ERROR (-1)
#define BASE_SOCKET int
#define INVALID_BASE_SOCKET SOCKET_ERROR
#define DLLEXPORT
#define SOCKET_LEN_T socklen_t

#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include<sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#endif

/*
���������windows linux ��windows7��CentOS�±������ͨ��
����ֵ�ľ���������鿴��������ĵ�һ��

20120809 17:54
*/
BASE_SOCKET DLLEXPORT GetSocket(int isTCP=1);
int DLLEXPORT CloseSocket(BASE_SOCKET socket);
inline int DLLEXPORT IoCtl(BASE_SOCKET socket,int nIsBlock=1);
int DLLEXPORT Connect(BASE_SOCKET socket,char* host,int port,int timeOut=0);//���ظ�����ʾ���� timeOut=0��ʾ����ģʽ ��λ���� 
int DLLEXPORT Send(BASE_SOCKET socket,char* buf,int size,int timeOut=0);//���ظ�����ʾ���� timeOut=0��ʾ����ģʽ ��λ����
int DLLEXPORT SendTo(BASE_SOCKET socket,char* host,int port,char* buf,int size);//���ظ�����ʾ���� timeOut=0��ʾ����ģʽ ��λ����
int DLLEXPORT Recv(BASE_SOCKET socket,char* buf,int size,int timeOut=0);//���ظ�����ʾ���� timeOut=0��ʾ����ģʽ ��λ����
int DLLEXPORT Bind(BASE_SOCKET socket,char* host,int port);
int DLLEXPORT CanReadSocket(BASE_SOCKET socket,int timeOut=0);//���ظ�����ʾ���� 0��ʾ��ʱ  ������ʾ�׽���׼������
int DLLEXPORT CanWriteSocket(BASE_SOCKET socket,int timeOut=0);//���ظ�����ʾ���� 0��ʾ��ʱ  ������ʾ�׽���׼������
int DLLEXPORT GetIp(BASE_SOCKET socket,char* ip,int size);
int DLLEXPORT GetPort(BASE_SOCKET socket,unsigned short& port);

BASE_SOCKET DLLEXPORT Accept(BASE_SOCKET socket,struct sockaddr* addr,SOCKET_LEN_T* addrlen,int timeOut=0);
#endif
