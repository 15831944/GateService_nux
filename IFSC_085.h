#pragma once
class CIFSC_085
{
public:
	char msgType[2];
	char deviceID[11];
	char EnterOutFlag;//����բ��־λ��'0'��բ��'1'��բ
	short CodeLen;
	unsigned char TDCodeLength[2];//��ά�볤��
	char* TD_Code;//��ά��
	short faceLen;
	unsigned char FacePicLength[2];//��Ƭ����
	unsigned char* FacePicData;//��������

public:
	CIFSC_085(void);
	~CIFSC_085(void);
	bool ParseData(unsigned char* data);
};

