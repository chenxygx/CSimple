#pragma once
#include "Student.h"
#include<fstream>

class StudentManage
{
public:
	StudentManage() { cout << "StudentManage()" << endl; };

	virtual void Add() = 0;            //ʵ�ָ����¼����ӣ�
	virtual void Show() = 0;          //ʵ�ָ������м�¼����ʾ�� 
	virtual void Search() = 0;        //ʵ�ָ����¼�Ĳ�ѯ��
	virtual void Edit() = 0;             //ʵ�ָ����¼���޸ģ�
	virtual void Delete() = 0;        //ʵ�ָ����¼��ɾ����
	virtual void Total() = 0;          //ʵ�ָ����¼��ͳ�ƣ�
	virtual void Save() = 0;           //�������¼���浽�ļ���
	virtual void Read() = 0;          //�ɴ��ļ��н���¼��ȡ������������У�
private:
	Student *pStudent;
	int count;
};