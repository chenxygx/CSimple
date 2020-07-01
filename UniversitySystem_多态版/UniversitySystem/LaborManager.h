/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     ʵ��Ա������
*/

#pragma once

#include <fstream>
#include "PersonManager.h"
#include "Labor.h"

class LaborManager:public PersonManager
{
public :
	LaborManager();
	~LaborManager();
	void Add();            //ʵ�ָ����¼����ӣ�
	void Show();          //ʵ�ָ������м�¼����ʾ�� 
	void Search();        //ʵ�ָ����¼�Ĳ�ѯ��
	void Edit();             //ʵ�ָ����¼���޸ģ�
	void Delete();        //ʵ�ָ����¼��ɾ����
	void Total();          //ʵ�ָ����¼��ͳ�ƣ�
	void Save();           //�������¼���浽�ļ���
	void Read();          //�ɴ��ļ��н���¼��ȡ������������У�
private:
	Labor *pLabor;
	int count;
};