#pragma once
//��ӳ��Ϣ��ѯ
class CIFSC_080
{
public:
	char msgType[2];
	char deviceID[10];
public:
	CIFSC_080(void);
	~CIFSC_080(void);
	bool ParseData(unsigned char* data);
};

