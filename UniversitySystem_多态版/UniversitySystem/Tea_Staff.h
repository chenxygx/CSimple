/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     教师兼行政人员类
*/

#pragma once

#include "Teacher.h"
#include "Staff.h"

class Tea_Staff : public Teacher, public Staff
{
public:
	Tea_Staff(int pnumber = 0, string pname = "", SEX psex = SEX::FEMALE, int page = 0,
		int pdept = 0, string pmajor = "", string ptitle = "", int ppolitics = 0);

	void Input();
	void Update();
	void Output();
};
