#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

struct FY_MSG
{
	char checkTime;
	char delayTime;
	char filmName[64];//��Ӱ����
	char CinemaTitle[64];//Ӱ������
	char fileType;//ӰƬ����
	char showTime[15];//��ӳʱ��(BCD��)��������ʱ����
	char endTime[15];//����ʱ��(BCD��) ������ʱ����

	FY_MSG()
	{
		memset(filmName,0x00,sizeof(filmName));
		memset(CinemaTitle,0x00,sizeof(CinemaTitle));
		memset(showTime,0x00,sizeof(showTime));
		memset(endTime,0x00,sizeof(endTime));
	}
};

//��ӳ��Ϣ����
class CIFSC_079
{
public:
	char msgType[2];
	unsigned char count;
	vector<FY_MSG> vFY;
public:
	CIFSC_079(void);
	~CIFSC_079(void);

	bool PraseData(string data);
	char* CombineData(int& datalen);
	//void Send(Node* pNode,char* sData,int nDatalen);
};

