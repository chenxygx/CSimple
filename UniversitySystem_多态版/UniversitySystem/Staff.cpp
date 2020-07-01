#include "Staff.h"

Staff::Staff(int pnumber, string pname, SEX psex, int page, int ppolitics) :
	Person(pnumber, pname, psex, page),
	politics(ppolitics) {}

void Staff::Input()
{
	InputPerson();
	cout << "������������ò��";
	for (int i = 0;i < 3;i++)
	{
		cout << setw(5) << i << "." << POLITICS_[i];
	}
	cout << "����";
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
			cout << "�����������������:";
			break;
		}
	}
}

void Staff::Update()
{
	UpdatePerson();
	cout << "���޸�������ò��";
	for (int i = 0;i < 3;i++)
	{
		cout << setw(5) << i << "." << POLITICS_[i];
	}
	cout << "����";
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
			cout << "�����������������:";
			break;
		}
	}
}

void Staff::Output()
{
	OutputPerson();
	cout << setw(10) << POLITICS_[politics] << endl;
}
