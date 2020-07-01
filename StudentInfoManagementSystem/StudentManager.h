/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	ѧ����������
*/
#pragma once
#include "Student.h"
#include "PersonManager.h"
class StudentManager : public PersonManager
{
public:
	StudentManager();
	~StudentManager();
	/*���*/
	void Add();
	/*չʾ*/
	void Show();
	/*����*/
	void Search();
	/*����*/
	void Update();
	/*ɾ��*/
	void Delete();
	/*���*/
	void Truncate();
	/*ͳ��*/
	void Total();
	/*�־û�*/
	void Save();
	/*��ȡ�ļ�����*/
	void Read();
	/*ƽ��������*/
	void Sort();
private:
	/*ѧ������*/
	Student* pStudent;
	/*ѧ����������*/
	int count;
};

