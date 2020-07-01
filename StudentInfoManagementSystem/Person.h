/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	人员实体
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
	/*设置人员姓名*/
	void setName(string name) {
		this->name = name;
	}
	/*获取人员姓名*/
	string getName() {
		return this->name;
	}
	/*设置年龄*/
	void setAge(int age) {
		this->age = age;
	}
	/*获取年龄*/
	int getAge() {
		return this->age;
	}
	/*设置性别*/
	void setSex(SexEnum sex) {
		this->sex = (int)sex;
	}
	/*设置性别*/
	void setSex(int sex) {
		this->sex = sex;
	}
	/*获取性别*/
	int getSex() {
		return this->sex;
	}
	/*获取性别标题*/
	string getSexTitle() {
		return SEX_TITLE[this->sex];
	}
protected:
	/*姓名*/
	string name;
	/*年龄*/
	int age;
	/*性别*/
	int sex;

	void InputPersion();
	void UpdatePersion();
	void OutputPersion();
};

