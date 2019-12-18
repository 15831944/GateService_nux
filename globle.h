#pragma once
#include <stdint.h>
#include <string>
#include <json/json.h>
#include <json/config.h>
#include <vector>
#include "Socket.h"
#include "Base64.h"

using std::string;
using std::vector;
#ifdef WIN32
#define msleep(X) Sleep(X)
#else
#include <iconv.h>
#define msleep(X) usleep((X)*1000)
#endif
#ifdef _DEBUG
#pragma comment(lib,"json_vc71_libmtd.lib")
#else
#pragma comment(lib,"json_vc71_libmt.lib")
#endif

#define IP_UNIQUE_IDENTIFY 0 //բ��IP�Ƿ�����ΪΨһ��ʶ ��������У��

#define MAX_BUFFER   1024*10

//#define  MSG_BEGN  0xEB//��Ϣͷ
//#define  MSG_END   0x03//��Ϣβ

#define ZZ_SWAP_2BYTE(L) ((((L) & 0x00FF) << 8) | (((L) & 0xFF00) >> 8))
#define ZZ_SWAP_4BYTE(L) ((ZZ_SWAP_2BYTE ((L) & 0xFFFF) << 16) | ZZ_SWAP_2BYTE(((L) >> 16) & 0xFFFF))
#define ZZ_SWAP_8BYTE(L) ((ZZ_SWAP_4BYTE (((uint64_t)(L)) & 0xFFFFFFFF) << 32) | ZZ_SWAP_4BYTE((((uint64_t)(L)) >> 32) & 0xFFFFFFFF))

#define RELEASE_NEW(x)  {if(x != NULL ){delete x;x=NULL;}}
#define RELEASE_HANDLE(x)  {if(x != NULL && x!=INVALID_HANDLE_VALUE){ CloseHandle(x);x = NULL;}}
#define RELEASE_SOCKET(x)  {if(x !=INVALID_BASE_SOCKET) { CloseSocket(x);x=INVALID_BASE_SOCKET;}}

#ifdef WIN32 
#define LOCK_MUTEX(X)	WaitForSingleObject(X, INFINITE); 
#elif  linux
#define LOCK_MUTEX(X)   pthread_mutex_lock(&X);
#endif

#ifdef WIN32 
#define UNLOCK_MUTEX(X)	ReleaseMutex(X); 
#elif  linux 
#define UNLOCK_MUTEX(X) pthread_mutex_unlock(&X);
#endif

enum TYPE_MSG
{
	TYPE_BEGIN,//��Ϣͷ
	TYPE_DATA ,
	TYPE_ACK ,
	TYPE_NAK ,
	TYPE_REQUEST ,
	TYPE_RESPONCE,
	TYPE_END,//��Ϣβ
	TYPE_MAX
};
extern unsigned char msgType[TYPE_MAX];

//���ݱ�������
enum DATA_TYPE
{
	IFSC_061=61,//��բ��֤���
	IFSC_062=62,//ɢ�͹�բ��֤
	IFSC_066=66,//ɢ�͹�բ��¼
	IFSC_067=67,//��Ա����բ��¼
	IFSC_071=71,//��ȡ������ʱ��
	IFAL_072=72,//�豸״̬��ѯ
	IFAL_074=9,//�豸ȫ״̬/״̬�仯
	IFSC_075=75,//��Ա����բ��֤
	IFAL_011=11,//�豸�¼���Ϣ�ϴ�
	IFMC_055=55,//�豸��������
	IFSC_080=80,//��ӳ��Ϣ��ѯ
	IFSC_085=85,//������բ��֤
	IFSC_086=86//������բ��֤���
};

void Log(char* fmt, ...);

class CGateClient;
class GlobleAll
{
public:
	GlobleAll();
	~GlobleAll();

public:
	string m_LogPath;//��־·��ȫ��
	string m_WebSerIP;//ǰ��http������IP
	string m_LocalIP;//����IP
	string m_configPath;
	int    m_HeardTime;//��������ʱ��
	int    m_HttpPort;//����http����˿�
	int    m_TcpPort;//����TCP/IP����˿�
	int    m_GateNum;//�������������ϵ����բ����

	string m_GateListUrl;//��ȡբ���б��ַ
	string m_61Url;//ɢ�͹�բ��֤��ַ
	string m_66Url;//��֤�����ַ
	string m_86Url;//������֤��ַ
	string m_79Url;//��ȡ��ӳ��Ϣ��ַ

	CGateClient* m_gateClient;
public:
	//��ʼ�����ñ���
	bool InitGloble();
	bool ReadConf();
	string GetLogFileName();
	bool get_local_ip();

#ifdef WIN32
	//gb2312תutf8
	string G2U(const char* gb2312,int nLen=0);
	//UTF-8תGB2312
	string U2G(const char* utf8,int nLen=0);
#elif linux
	int utf8togb2312( char *sourcebuf,size_t sourcelen,char *destbuf,size_t destlen);
	int gb2312toutf8( char *sourcebuf,size_t sourcelen,char *destbuf,size_t destlen);
#endif

	//�жϻ����Ǵ�˻���С�ˣ�return true:��ˣ�false:С��
	bool EndianJudge();
	//���16���Ʊ�����Ϣ
	string CharStr2HexStr( char *pucCharStr, int iSize);
};

extern GlobleAll* g_globle;