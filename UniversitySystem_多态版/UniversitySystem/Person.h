/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:基类Person
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     基类
*/

#pragma once

#include <iostream>
#include <iomanip>
#include "Const.h"

// 虚基类
class Person
{
public:
	Person(int pnumber = 0, string pname = "", SEX psex = SEX::FEMALE, int page = 0);

	int GetNumber() { return number; }
	string GetName() { return name; }
	SEX GetSex() { return sex; }
	int GetAge() { return age; }
	void SetNumber(int pnumber) { number = pnumber; }
	void SetName(string pname) {  name = pname; }
	void SetSex(int psex) { sex = (SEX)psex; }
	void SetAge(int page) { age = page; }

	void InputPerson();
	void UpdatePerson();
	void OutputPerson();
protected:
	int number;   //员工编号
	string name;  // 姓名
	SEX sex;      // 性别
	int age;      // 年龄	
};
