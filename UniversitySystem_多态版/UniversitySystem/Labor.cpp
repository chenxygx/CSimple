#include "Labor.h"

void Labor::Input()
{
	int choice = -1;
	InputPerson();
	cout << "请输入职务（";
	cout << "0." << DUTY_[0] << setw(5) << "1." << DUTY_[1] <<"）：";
	while (choice < 0 || choice > 1) {
		cin >> choice;
		switch (choice)
		{
		case 0:
		case 1:
			duty = choice;
			break;
		default:
			cout << "输入错误。请重新输入：" ;
			break;
		}
	}
}

void Labor::Update()
{
	int choice = -1;
	UpdatePerson();
	cout << "请修改职务（";
	cout << "0." << DUTY_[0] << setw(5) << "1." << DUTY_[1] << "）：";
	while (choice < 0 || choice > 1) {
		cin >> choice;
		switch (choice)
		{
		case 0:
		case 1:
			duty = choice;
			break;
		default:
			cout << "输入错误。请重新输入：";
			break;
		}
	}
}

void Labor::Output()
{
	OutputPerson();
	cout << setw(10) << DUTY_[duty] << endl;
}

Labor::Labor(int pnumber , string pname , SEX psex, int page, int pduty) :
	Person(pnumber, pname, psex, page), duty(pduty) {};
