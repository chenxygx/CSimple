#pragma once
#include<fstream>
#include "StudentManage.h"
#include"Score.h"

class ScoreManage : public StudentManage
{
public:
	ScoreManage();
	void Add();          //ʵ�ָ����¼����ӣ�
	void Show();         //ʵ�ָ������м�¼����ʾ�� 
	void Search();       //ʵ�ָ����¼�Ĳ�ѯ��
	void Edit();         //ʵ�ָ����¼���޸ģ�
	void Delete();       //ʵ�ָ����¼��ɾ����
	void Total();        //ʵ�ָ����¼��ͳ�ƣ�
	void Save();         //�������¼���浽�ļ���
	void Read();         //�ɴ��ļ��н���¼��ȡ������������У�
private:
	Score *pScore;
	int count;
};