/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*/

#include<string>
using namespace std;
#pragma once

// ÿ����Ա���������
const int MAX_ = 50;

// �Ա�
const string SEX_[] = { "Ů","��" };

// ��ʦ������ϵ������
const string DEPT_[] = { "����ϵ",
						"��еϵ" ,
						"����ϵ" ,
						"����ϵ" ,
						"�����ϵ" ,
						"����ϵ" ,
						"�ƻ�ϵ" ,
						"����ϵ" ,
						"�ķ�ϵ",
						"����ϵ"};

// ������Ա������ò
const string POLITICS_[] = { "�й���Ա",
							"������Ա",
							"Ⱥ��" };

// ʵ��Ա��ְ��
const string DUTY_[] = { "ʵ��Ա","ʵ������" };

// �Ա�ö��
enum SEX
{
	FEMALE = 0, // Ů
	MALE = 1    // ��
};
