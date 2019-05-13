#pragma once

//ɢ�͹�բ��¼
class CIFSC_066
{
public:
	char msgType[3];
	char deviceID[11];
	char number[18];//��բ��ˮ��
	char result;//0�ɹ���1ʧ��
	char ErrorDescription[17];//��բʧ��ԭ��˵��
	char direction[2];//0����1��
	short CodeLen;
	unsigned char codeLength[3];//��ά�볤��
	unsigned char* code;//��ά��
	char OccurredTOD[15];//��բʱ��(BCD��)

public:
	CIFSC_066(void);
	~CIFSC_066(void);
	bool ParseData(unsigned char* data);
};

