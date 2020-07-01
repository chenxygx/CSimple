#include "Score.h"

Score::Score(int pid, string pname, SEX psex, int page, int pmajor, int pscore):
	Student(pid, pname, psex, page,pmajor),score(pscore)
{
}

void Score::Input()
{
	int choice = -1;
	InputStudent();
	cout << "请选择学科:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(3) << i << "." << SCORE_[i];
	}
	cout << endl;
	while (choice < 0 || choice > 3) {
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			score = choice;
			break;
		default:
			cout << "输入错误。请重新输入！" << endl;
			break;
		}
	}
}

void Score::Update()
{
	int choice = -1;
	UpdateStudent();
	cout << "请修改选择学科:" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << setw(3) << i << "." << SCORE_[i];
	}
	cout << endl;
	while (choice < 0 || choice > 3) {
		cout << "请输入你的选择:" << endl;
		cin >> choice;
		switch (choice)
		{
		case 0:
		case 1:
		case 2:
		case 3:
			score = choice;
			break;
		default:
			cout << "输入错误。请重新输入！" << endl;
			break;
		}
	}
}

void Score::Output()
{
	OutputStudent();
	cout << setw(10) << SCORE_[score] << endl;
}
