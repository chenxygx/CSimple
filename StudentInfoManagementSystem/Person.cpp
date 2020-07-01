#include "Person.h"
using std::cout;
using std::endl;
using std::cin;

void Person::InputPersion() {
	cout << "请输入学生姓名：";
	cin >> name;
	cout << "请输入学生年龄：";
	cin >> age;
	if (age < 0 || age > 100) {
		cout << "数学年龄输入有误，请重新输入";
		return;
	}
	cout << "请输入学生性别（";
	for (int i = 0; i < 2; i++)
	{
		cout << setw(2) << i << "." << SEX_TITLE[i];
	}
	cout << "）：";
	for (;;) {
		cin >> sex;
		if (sex < 0 || sex > 1) {
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		break;
	}
}

void Person::UpdatePersion() {
	cout << "请修改学生姓名：";
	cin >> name;
	cout << "请修改学生年龄：";
	cin >> age;
	if (age < 0 || age > 100) {
		cout << "数学年龄输入有误，请重新输入";
		return;
	}
	cout << "请修改学生性别（";
	for (int i = 0; i < 2; i++)
	{
		cout << setw(2) << i << "." << SEX_TITLE[i];
	}
	cout << "）：";
	for (;;) {
		cin >> sex;
		if (sex < 0 || sex > 1) {
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		break;
	}
}

void Person::OutputPersion() {
	cout << setw(8) << name
		<< setw(8) << SEX_TITLE[sex]
		<< setw(8) << age;
}