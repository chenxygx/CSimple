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
	cout << "��ѡ������ϵ��:" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << setw(3) << i << "." << DEPT_[i];
		if (i == 4)
			cout << endl;
	}
	cout << endl;
	while (choice < 0 || choice > 9 ) {
		cout << "���������ѡ��:" << endl;
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
				cout << "����������������룡" << endl;
				break;
		}
	}
	cout << "������רҵ:" << endl;
	cin >> major;
	cout << "������ְ��:" << endl;
	cin >> title;
}

void Teacher::Update()
{
	int choice = -1;
	UpdatePerson();
	cout << "���޸�����ϵ��:" << endl;
	for (int i = 0;i < 10;i++)
	{
		cout << setw(3) << i << "." << DEPT_[i];
		if (i == 4)
			cout << endl;
	}
	cout << endl;
	while (choice < 0 || choice > 9) {
		cout << "���������ѡ��:" << endl;
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
				cout << "����������������룡" << endl;
				break;
		}
	}
	cout << "���޸�רҵ:" << endl;
	cin >> major;
	cout << "���޸�ְ��:" << endl;
	cin >> title;
}

void Teacher::Output()
{
	OutputPerson();
	cout << setw(10) << DEPT_[dept]
		<< setw(10) << major
		<< setw(10) << title << endl;
}
