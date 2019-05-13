#pragma once
#include <vector>
#include <string>

using std::vector;
using std::string;

struct GATESTATUS
{
	char StatusID[4];
	char StatusLevel[2];
	char Argument[33];

	GATESTATUS()
	{
		memset(StatusID,0,sizeof(StatusID));
		memset(Argument,0,sizeof(Argument));
		memset(StatusLevel,0,sizeof(StatusLevel));
	}
};

//�豸ȫ״̬/״̬�仯
class CIFAL_074
{
public:
	char DeviceID[11];
	unsigned char Repeatcount;
	vector<GATESTATUS> vGateStatus;//�������״̬��
	
public:
	CIFAL_074(void);
	~CIFAL_074(void);

	bool ParseData(unsigned char* data);
	Json::Value MakeJson();
};

