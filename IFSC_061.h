#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>

using std::string;

//��բ��֤���
class CIFSC_061
{
public:
	char msgType[2];
	char deviceID[10];
	char result[3];//��բ��֤���
	char number[17];//��բ��ˮ��
	uint8_t AlermGulp;//�Ƿ�����Ʊ
	uint8_t MessageLen;//բ��UI��ʾ��Ϣ����
	char* Message;//բ��UI��ʾ��Ϣ,����ΪMessageLen
	uint8_t ClientCount;//��բ����
	uint8_t PrintCount;//��Ҫ��ӡ��СƱ������0Ϊû��
	uint16_t PrintLen;//��ӡ�ֽڳ���
public:
	CIFSC_061(char* _deviceID);
	~CIFSC_061(void);

	bool ParseData(const char* data);
	char* CombineData(int& datalen);
};

