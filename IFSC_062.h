#pragma once

class CIFSC_062
{
public:
	 char   DeviceID[11];
	 char   EnOutFlag[2];//����բ��־ 0��1��
	 short  TDCodeLen;
	 unsigned char*   TDCode;
public:
	CIFSC_062();
	~CIFSC_062();

	 bool ParseData(unsigned char* data);
};