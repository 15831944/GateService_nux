#pragma once
class CIFSC_075
{
public:
	char DeviceID[10];
	char EnOutFlag[1];//����բ��־ 0��1��
	short  CardType;//����������
	short  PhysicalNOLength;//��Ա�������ų���
	char PhysicalNO[1024];//������

public:
	CIFSC_075(void);
	~CIFSC_075(void);

	bool ParseData(unsigned char* data);
};

