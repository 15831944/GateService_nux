#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
class CIFSC_071
{
public:
	char DeviceID[10];

public:
	CIFSC_071(void);
	~CIFSC_071(void);

	bool ParseData(unsigned char* data);
	//��ȡ������Unixʱ���
	char* getUnixCurrtTime(int& dataLen);
};

