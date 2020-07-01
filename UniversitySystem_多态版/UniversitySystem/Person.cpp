#include "Person.h"

Person::Person(int pnumber, string pname, SEX psex, int page) :
	number(pnumber), name(pname), sex(psex), age(page) {
	
}

void Person::InputPerson()
{
	int inputSex = -1;
	cout << "请输入员工编号：" << endl;
	cin >> number;
	cout << "请输入员工姓名：" << endl;
	cin >> name;
	cout << "请输入员工性别（";
	for (int i = 0;i < 2;i++)
	{
		cout << setw(3) << i << "." << SEX_[i];
	}
	cout << "）：";
	while (inputSex < 0 || inputSex >1)
	{
		cin >> inputSex;
		switch (inputSex)
		{
		case 0:
		case 1:
			sex = (SEX)inputSex;
			break;
		default:
			cout << "输入错误，请重新输入：";
			break;
		}
	}

	cout << "请输入员工年龄：" << endl;
	cin >> age;
}

void Person::UpdatePerson()
{
	int inputSex = -1;
	cout << "请修改员工姓名：" << endl;
	cin >> name;
	cout << "请修改员工性别（";
	for (int i = 0;i < 2;i++)
	{
		cout << setw(3) << i << "." << SEX_[i];
	}
	cout << "）：";
	while (inputSex < 0 || inputSex >1)
	{
		cin >> inputSex;
		switch (inputSex)
		{
		case 0:
		case 1:
			sex = (SEX)inputSex;
			break;
		default:
			cout << "输入错误，请重新输入：";
			break;
		}
	}
	cout << "请修改员工年龄：" << endl;
	cin >> age;
}

void Person::OutputPerson()
{
	cout << setw(8) << number
		<< setw(10) << name
		<< setw(10) << SEX_[sex]
		<< setw(10) << age;
}
