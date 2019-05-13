#pragma once
/*
1.���캯����name��ʾ�����ļ�ȫ·������d:/demo.config
2.������ú������������ݿ���ͨ��GetValue����ȡ
3.SetValue��ʾ�޸� ����Ҫ���������ж�Ӧ��KEY���ݲ����޸�
4.AddValue��ʾ��� ����Ҫ��������û�ж�Ӧ��KEY���ݲ������
5.DelValue��ʾɾ�� ����Ҫ���������ж�Ӧ��KEY���ݲ���ɾ��
*/
class CBaseConfig
{
public:
	CBaseConfig(const char* name);//ȫ·��
	~CBaseConfig(void);

	const char* GetValue(const char* key);
	bool SetValue(const char* key,const char* value);
	bool AddValue(const char* key,const char* value);
	bool AddValue(const char* key);//���ע��
	bool DelValue(const char* key);
private:
	void* m_pData;
};
