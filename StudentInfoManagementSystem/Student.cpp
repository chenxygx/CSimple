#include "Student.h"
#include<iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::cin;
using std::ios;
using std::setiosflags;
using std::setprecision;

void Student::InputStudent() {
	cout << "请输入学生学号：";
	cin >> number;
	if (number < 1 || number > 9999) {
		cout << "学生学号输入有误，请重新输入";
		return;
	}
	InputPersion();
	cout << "请输入学生专业（";
	for (int i = 0; i < 5; i++)
	{
		cout << setw(2) << i << "." << MAJOR_TITLE[i];
	}
	cout << "）：";
	for (;;) {
		cin >> major;
		if (major < 0 || major > 5) {
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		break;
	}
	double math, english, c = 0;
	cout << "请输入数学成绩：";
	cin >> math;
	if (math < 0 || math > 100) {
		cout << "数学成绩输入有误，请重新输入";
		return;
	}

	cout << "请输入英语成绩：";
	cin >> english;
	if (english < 0 || english > 100) {
		cout << "英语成绩输入有误，请重新输入";
		return;
	}

	cout << "请输入C++成绩：";
	cin >> c;
	if (c < 0 || c > 100) {
		cout << "C++输入有误，请重新输入";
		return;
	}
	score.setMathematics(math);
	score.setEnglish(english);
	score.setC(c);
}

void Student::UpdateStudent() {
	cout << "请修改学生学号：" << endl;
	cin >> number;
	if (number < 1 || number > 9999) {
		cout << "学生学号输入有误，请重新输入";
		return;
	}
	UpdatePersion();
	cout << "请修改学生专业（";
	for (int i = 0; i < 5; i++)
	{
		cout << setw(2) << i << "." << MAJOR_TITLE[i];
	}
	cout << "）：";
	for (;;) {
		cin >> major;
		if (major < 0 || major > 5) {
			cout << "输入错误，请重新输入" << endl;
			continue;
		}
		break;
	}

	double math, english, c = 0;
	cout << "请修改数学成绩：";
	cin >> math;
	if (math < 0 || math > 100) {
		cout << "数学成绩输入有误，请重新输入";
		return;
	}

	cout << "请修改英语成绩：";
	cin >> english;
	if (english < 0 || english > 100) {
		cout << "英语成绩输入有误，请重新输入";
		return;
	}

	cout << "请修改C++成绩：";
	cin >> c;
	if (c < 0 || c > 100) {
		cout << "C++输入有误，请重新输入";
		return;
	}
	score.setMathematics(math);
	score.setEnglish(english);
	score.setC(c);
}

void Student::OutputStudent() {
	cout << setw(8) << number;
	OutputPersion();
	cout << setw(12) << getMajorTitle();
	cout << setw(12) << score.getMathematics();
	cout << setw(12) << score.getEnglish();
	cout << setw(12) << score.getC();
	cout << setw(12) << getAverage();
	cout << setw(12) << getSum();
	cout << setw(12) << getLevelTitle() << endl;
}