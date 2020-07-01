/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*    行政人员类
*/

#pragma once
#include "Person.h"

class Staff :virtual public Person
{
public:
	Staff(int pnumber = 0, string pname = "", SEX psex = SEX::FEMALE, int page = 0, int ppolitics = 0);

	int GetPolitics() { return politics; }
	void SetPolitics(int ppolitics) { politics = ppolitics; }

	void Input();
	void Update();
	void Output();
protected:
	int politics;
};
