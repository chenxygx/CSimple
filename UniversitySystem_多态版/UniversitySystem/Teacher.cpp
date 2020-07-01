#include<iomanip>
#include "Teacher.h"

Teacher::Teacher(int pnumber, string pname, SEX psex , int page,
	int pdept, string pmajor, string ptitle) :
	Person(pnumber, pname, psex, page),
	dept(pdept), major(pmajor), title(ptitle) {}

void Teacher::Input()
{
	int choice = -1;
	InputPerson();
	cout << "请选择所在系部:" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << setw(3) << i << "." << DEPT_[i];
		if (i == 4)
			cout << endl;
	}
	cout << endl;
	while (choice < 0 || choice > 9 ) {
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		    case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				dept = choice;
				break;
			default:
				cout << "输入错误。请重新输入！" << endl;
				break;
		}
	}
	cout << "请输入专业:" << endl;
	cin >> major;
	cout << "请输入职称:" << endl;
	cin >> title;
}

void Teacher::Update()
{
	int choice = -1;
	UpdatePerson();
	cout << "请修改所在系部:" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << setw(3) << i << "." << DEPT_[i];
		if (i == 4)
			cout << endl;
	}
	cout << endl;
	while (choice < 0 || choice > 9) {
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		    case 0:
			case 1:
			case 2:
			case 3:
			case 4:
			case 5:
			case 6:
			case 7:
			case 8:
			case 9:
				dept = choice;
				break;
			default:
				cout << "输入错误。请重新输入！" << endl;
				break;
		}
	}
	cout << "请修改专业:" << endl;
	cin >> major;
	cout << "请修改职称:" << endl;
	cin >> title;
}

void Teacher::Output()
{
	OutputPerson();
	cout << setw(10) << DEPT_[dept]
		<< setw(10) << major
		<< setw(10) << title << endl;
}
