#pragma once
//������բ��֤���
class CIFSC_086
{
public:
	char msgType[2];
	char deviceID[11];
	char ValidationResults[3];//"00"�����󶨳ɹ���"01"ӰƱ��֤��ͨ��,�澯��"03"δ�ҵ�������Ϣ,��04��δ������ʱ��,��05����Ʊ�Ѵ�������(��ʱ�ն���Ҫ��֤�˽ӿڷ�������������ʵʱ�����Ա�)

	string strMsg;
	string faceid;//05������Ѿ��󶨵���������
public:
	CIFSC_086(const char* _deviceID);
	~CIFSC_086(void);

	bool ParseData(string strData);
	char* CombineData(int& datalen);
};

