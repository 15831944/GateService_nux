#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;


struct GATE_EVENT
{
	char EventID[3];
	char StatusID[4];//EventIDΪ99ʱ��Ч
	char StatusLevel;//EventIDΪ99ʱ��Ч
	char EventArgument[33];//������ϣ����ʾ����ԭ��
	char OccurredTOD[15];//��������ʱ��(ʱ���)

	GATE_EVENT()
	{
		memset(EventID,0,sizeof(EventID));
		memset(StatusID,0,sizeof(StatusID));
		memset(EventArgument,0,sizeof(EventArgument));
		memset(OccurredTOD,0,sizeof(OccurredTOD));
	}
};

//AGM�¼���Ϣ�ϴ�
class CIFAL_078
{
public:
	char msgType[2];
	char deviceID[11];
	unsigned char RepeatCount;
	vector<GATE_EVENT> vGateEvent;

public:
	CIFAL_078(void);
	~CIFAL_078(void);

	bool ParseData(unsigned char* data);
};

