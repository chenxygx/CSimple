/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	��Աʵ��
*/
#pragma once
#include <iostream>
#include <iomanip>
#include "CommonConst.h"
using std::string;
using std::setw;
class Person
{
public:
	/*������Ա����*/
	void setName(string name) {
		this->name = name;
	}
	/*��ȡ��Ա����*/
	string getName() {
		return this->name;
	}
	/*��������*/
	void setAge(int age) {
		this->age = age;
	}
	/*��ȡ����*/
	int getAge() {
		return this->age;
	}
	/*�����Ա�*/
	void setSex(SexEnum sex) {
		this->sex = (int)sex;
	}
	/*�����Ա�*/
	void setSex(int sex) {
		this->sex = sex;
	}
	/*��ȡ�Ա�*/
	int getSex() {
		return this->sex;
	}
	/*��ȡ�Ա����*/
	string getSexTitle() {
		return SEX_TITLE[this->sex];
	}
protected:
	/*����*/
	string name;
	/*����*/
	int age;
	/*�Ա�*/
	int sex;

	void InputPersion();
	void UpdatePersion();
	void OutputPersion();
};

