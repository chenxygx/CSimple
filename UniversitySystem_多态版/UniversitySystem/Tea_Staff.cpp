#include "Tea_Staff.h"

Tea_Staff::Tea_Staff(int pnumber, string pname, SEX psex, int page,
	int pdept, string pmajor, string ptitle, int ppolitics) :
	Person(pnumber, pname, psex, page),
	Teacher(pnumber, pname, psex, page, pdept, pmajor, ptitle),
	Staff(pnumber, pname, psex, page, ppolitics) {}

void Tea_Staff::Input()
{
	Teacher::Input();
	cout << "请输入政治面貌（";
	for (int i = 0;i < 3;i++)
	{
		cout << setw(5) << i << "." << POLITICS_[i];
	}
	cout << "）：";
	int choice = -1;
	while (choice < 0 || choice>2)
	{
		cin >> choice;
		switch (choice)
		{
		case 0:
		case 1:
		case 2:
			this->politics = choice;
			break;
		default:
			cout << "输入错误。请重新输入:";
			break;
		}
	}	
}

void Tea_Staff::Update()
{
	Teacher::Update();
	cout << "请修改政治面貌（";
	for (int i = 0;i < 3;i++)
	{
		cout << setw(5) << i << "." << POLITICS_[i];
	}
	cout << "）：";
	int choice = -1;
	while (choice < 0 || choice>2)
	{
		cin >> choice;
		switch (choice)
		{
		case 0:
		case 1:
		case 2:
			this->politics = choice;
			break;
		default:
			cout << "输入错误。请重新输入:";
			break;
		}
	}
}

void Tea_Staff::Output()
{
	OutputPerson();
	cout << setw(10) << DEPT_[dept]
		    << setw(10) << major
		    << setw(10) << title 
	        << setw(10) << POLITICS_[politics] << endl;
}
