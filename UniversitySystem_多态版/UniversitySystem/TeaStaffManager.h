/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*/

#pragma once

#include <fstream>
#include "PersonManager.h"
#include "Tea_Staff.h"

class TeaStaffManager:public PersonManager
{
public:
	TeaStaffManager();
	~TeaStaffManager();
	void Add();          //ʵ�ָ����¼����ӣ�
	void Show();         //ʵ�ָ������м�¼����ʾ�� 
	void Search();       //ʵ�ָ����¼�Ĳ�ѯ��
	void Edit();         //ʵ�ָ����¼���޸ģ�
	void Delete();       //ʵ�ָ����¼��ɾ����
	void Total();        //ʵ�ָ����¼��ͳ�ƣ�
	void Save();         //�������¼���浽�ļ���
	void Read();         //�ɴ��ļ��н���¼��ȡ������������У�
private:
	Tea_Staff *pTeaStaff;
	int count;
};
