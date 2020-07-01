/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     ��ʦ��
*/

#pragma once
#include<iostream>
#include"Person.h"
using namespace std;

// ��ʦ��
class Teacher :virtual public Person
{
public:
	Teacher(int pnumber = 0, string pname = "", SEX psex = SEX::FEMALE, int page = 0,
		int pdept = 0, string pmajor = "", string ptitle = "");

	int GetDept() { return dept; }
	string GetMajor() { return major; }
	string GetTitle() { return title; }
	void SetDept(int pdept) { dept = pdept; }
	void SetMajor(string pmajor) { major = pmajor; }
	void SetTitle(string ptitle) { title = ptitle; }

	void Input();
	void Update();
	void Output();
protected:
	int dept;   // ����ϵ��
	string major;  // רҵ
	string title;  // ְ��
};
