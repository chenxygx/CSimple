/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     实验员类
*/

#pragma once

#include "Person.h"

class Labor :public Person
{
public:
	Labor(int pnumber = 0, string pname = "", SEX psex = SEX::FEMALE, int page = 0, int pduty = 0);

	int GetDuty() { return duty; };
	void SetDuty(int pduty) { duty = pduty; };

	void Input();
	void Update();
	void Output();

protected:
	int duty;  // 职务
};
