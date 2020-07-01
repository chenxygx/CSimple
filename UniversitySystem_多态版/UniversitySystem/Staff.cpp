#include "Staff.h"

Staff::Staff(int pnumber, string pname, SEX psex, int page, int ppolitics) :
	Person(pnumber, pname, psex, page),
	politics(ppolitics) {}

void Staff::Input()
{
	InputPerson();
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

void Staff::Update()
{
	UpdatePerson();
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

void Staff::Output()
{
	OutputPerson();
	cout << setw(10) << POLITICS_[politics] << endl;
}
