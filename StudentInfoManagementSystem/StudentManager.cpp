#include <iostream>
#include <fstream>
#include <algorithm>
#include "StudentManager.h"
#include "CommonUtils.h"
using std::cout;
using std::cin;
using std::endl;
using std::ofstream;
using std::ios;
using std::strcat;
using namespace std;

StudentManager::StudentManager() {
	pStudent = new Student[STUDENT_MAX];
	if (!pStudent) {
		cout << "学生操作类初始化异常" << endl;
		exit(1);
	}
	count = 0;
}

StudentManager::~StudentManager() {
	if (pStudent) {
		delete[] pStudent;
		pStudent = NULL;
	}
	cout << "学生操作类释放" << endl;
}

void StudentManager::Add() {
	if (count >= STUDENT_MAX) {
		cout << "学生人员已满无法添加" << endl;
		return;
	}
	Student student;
	cout << "请输入新添加学生信息" << endl;
	student.InputStudent();
	for (int i = 0; i < count; i++)
	{
		if (student.getNumber() == pStudent[i].getNumber()) {
			cout << "该学生编号已存在，请重新输入" << endl;
			return;
		}
	}
	pStudent[count] = student;
	count = count + 1;
	cout << "添加成功！" << endl;
	return;
}

void ConsoleTitle() {
	cout << setw(8) << "学号"
		<< setw(8) << "姓名"
		<< setw(8) << "性别"
		<< setw(8) << "年龄"
		<< setw(12) << "专业"
		<< setw(12) << "数学成绩"
		<< setw(12) << "英语成绩"
		<< setw(12) << "C++成绩"
		<< setw(12) << "平均分"
		<< setw(12) << "总分"
		<< setw(12) << "等级"
		<< endl;
}

void StudentManager::Show() {
	if (count == 0) {
		cout << "无数据！" << endl;
		return;
	}
	ConsoleTitle();
	for (int i = 0; i < count; i++)
	{
		pStudent[i].OutputStudent();
	}
}

void StudentManager::Search() {
	bool isFind = false;
	int index = 0;
	if (count == 0) {
		cout << "当前系统中没有记录！" << endl;
		return;
	}
	int choice = 0;
	cout << "请选择查询方式：1.学号，2.姓名，3.排名，4.等级" << endl;
	while (choice != 1 && choice != 2)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入要查找的学生学号：";
			int number;
			cin >> number;
			for (int i = 0; i < count; i++)
			{
				if (number == pStudent[i].getNumber()) {
					isFind = true;
					index = i;
					break;
				}
			}
		}
		break;
		case 2:
		{
			cout << "请输入要查找的学生姓名：";
			string name;
			cin >> name;
			for (int i = 0; i < count; i++)
			{
				if (name == pStudent[i].getName()) {
					isFind = true;
					index = i;
					break;
				}
			}
		}
		case 3:
		{
			cout << "请输入要查找的排名数量：";
			int num = 0;
			cin >> num;
			int choice = 0;
			cout << "请输入排名顺序 1.正序，2.倒序";
			cin >> choice;
			if (choice == 1) {
				sort(pStudent, pStudent + count, compareAsc);
			}
			else {
				sort(pStudent, pStudent + count, compareDesc);
			}
			ConsoleTitle();
			for (int i = 0; i <= num; i++)
			{
				pStudent[i].OutputStudent();
			}
		}
		break;
		case 4:
		{
			cout << "请输入要查找的学生等级（";
			for (int i = 0; i < 5; i++)
			{
				cout << setw(2) << i << "." << LEVEL_TITLE[i];
			}
			cout << "）：";
			int level;
			for (;;) {
				cin >> level;
				if (level < 0 || level > 5) {
					cout << "输入错误，请重新输入" << endl;
					continue;
				}
				break;
			}
			for (int i = 0; i <= count; i++)
			{
				if (pStudent[i].getLevel() == level) {
					pStudent[i].OutputStudent();
				}
			}
		}
		default:
			cout << "无此选项！请重新选择查询方式：1.学号，2.姓名，3.排名，4.等级" << endl;
			break;
		}
	}
	if (isFind) {
		ConsoleTitle();
		pStudent[index].OutputStudent();
	}
	else
	{
		cout << "查无此人！" << endl;
	}
}

void StudentManager::Update() {
	if (count == 0) {
		cout << "当前系统中没有存储记录！" << endl;
		return;
	}
	cout << "请输入要修改的学生编号：";
	int number;
	cin >> number;
	for (int i = 0; i < count; i++)
	{
		if (number == pStudent[i].getNumber()) {
			cout << "请修改员工信息：" << endl;
			pStudent[i].UpdateStudent();
			cout << "修改成功！" << endl;
			return;
		}
	}
	cout << "查无此人！" << endl;
}

void StudentManager::Truncate() {
	cout << "请选择清空方式：1、全部清空  2、按专业清空" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (pStudent) {
			delete[] pStudent;
			pStudent = NULL;
		}
		cout << "学生操作类释放" << endl;
	}
	break;
	case 2: {
		int maj;
		cout << "请选择要清空的专业：";
		for (int i = 0; i < 5; i++)
		{
			cout << setw(2) << i << "." << MAJOR_TITLE[i];
		}
		cout << "）：";
		for (;;) {
			cin >> maj;
			if (maj < 0 || maj > 5) {
				cout << "输入错误，请重新输入" << endl;
				continue;
			}
			break;
		}
		for (int i = 0; i < count; i++)
		{
			if (pStudent[i].getMajor() == maj) {
				for (int j = i;j < count - 1;j++) {
					pStudent[j] = pStudent[j + 1];
				}
				cout << "删除成功！" << endl;
				count--;
				break;
			}
		}
	}
	default:
		break;
	}
}

void StudentManager::Delete() {
	if (count == 0) {
		cout << "当前系统中没有存储记录！" << endl;
		return;
	}
	cout << "请选择删除方式：1、按学生编号删除  2、按学生姓名删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入学生编号：" << endl;
		int number;
		cin >> number;
		for (int i = 0;i < count;i++)
		{
			if (number == pStudent[i].getNumber())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j < count - 1;j++)
						pStudent[j] = pStudent[j + 1];
					cout << "删除成功！" << endl;
					count--;
				};
				break;
				case 2:
					break;
				default:
					cout << "输入错误，操作失败！" << endl;
					break;
				}
				return;
			}
		}
		cout << "无此人！" << endl;
	};
	break;
	case 2:
	{
		cout << "请输入学生姓名：" << endl;
		string name;
		cin >> name;
		int nameCount = 0;
		for (int i = 0;i < count;i++) {
			if (name == pStudent[i].getName()) {
				nameCount = nameCount + 1;
			}
		}
		if (nameCount > 1) {
			cout << "存在重名学生，是否全部删除？ 1.是  2.否" << endl;
			int choice;
			cin >> choice;
			if (choice == 2) {
				return;
			}
		}
		for (int i = 0;i < count;i++)
		{
			if (name == pStudent[i].getName())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j < count - 1;j++)
						pStudent[j] = pStudent[j + 1];
					cout << "删除成功！" << endl;
					count--;
				};
				break;
				case 2:
					break;
				default:
					cout << "输入错误，操作失败！" << endl;
					break;
				}
			}
		}
		cout << "无此人！" << endl;
	};
	break;
	default:
		cout << "无此项，操作失败！" << endl;
		break;
	}
}

void StudentManager::Total() {
	cout << "1.按每个学生总分及平均分 2.同一专业内学生的各科成绩平均分";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < count; i++)
		{
			cout << pStudent[i].getName();
			cout << "总分：" << to_string(pStudent[i].getSum()) << "，平均分：" << to_string(pStudent[i].getAverage()) << endl;
		}
	}
	break;
	case 2:
	{
		int major;
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
		for (int i = 0; i < count; i++)
		{
			if (pStudent[i].getMajor() == major) {
				cout << pStudent[i].getName();
				cout << "平均分：" << to_string(pStudent[i].getAverage()) << endl;
			}
		}
	}
	break;
	default:
		break;
	}
}

void StudentManager::Save() {
	ofstream out("Student.txt", ios::out);
	if (!out) {
		cout << "文件打开失败！" << endl;
		return;
	}
	cout << "文件打开成功！" << endl;
	for (int i = 0;i < count; i++)
	{
		out << pStudent[i].getNumber() << " "
			<< pStudent[i].getName() << " "
			<< pStudent[i].getSex() << " "
			<< pStudent[i].getAge() << " "
			<< pStudent[i].getMajor() << " "
			<< pStudent[i].getScore().getMathematics() << " "
			<< pStudent[i].getScore().getEnglish() << " "
			<< pStudent[i].getScore().getC() << endl;
	}
	cout << "写入成功！" << endl;
	out.close();
}

void StudentManager::Read() {
	ifstream in("Student.txt", ios::in);
	if (!in) {
		cout << "文件打开失败！" << endl;
		return;
	}
	pStudent = new Student[STUDENT_MAX];
	count = 0;
	int number;
	string name;
	int sex;
	int age;
	int major;
	double mathematics;
	double english;
	double c;
	while (in >> number
		>> name
		>> sex
		>> age
		>> major
		>> mathematics
		>> english
		>> c)
	{
		pStudent[count].setNumber(number);
		pStudent[count].setName(name);
		pStudent[count].setSex(sex);
		pStudent[count].setAge(age);
		pStudent[count].setMajor(major);
		pStudent[count].score.setMathematics(mathematics);
		pStudent[count].score.setEnglish(english);
		pStudent[count].score.setC(c);
		if (++count >= STUDENT_MAX)
		{
			break;
		}
	}
	cout << "读取成功！" << endl;
	in.close();
}

void StudentManager::Sort() {
	if (count == 0) {
		cout << "无数据！" << endl;
		return;
	}
	int desc = 0;
	cout << "请输入排序方式：0.升序，1.降序" << endl;
	cin >> desc;
	if (desc == 0) {
		sort(pStudent, pStudent + count, compareAsc);
	}
	else {
		sort(pStudent, pStudent + count, compareDesc);
	}
	ConsoleTitle();
	for (int i = 0; i < count; i++)
	{
		pStudent[i].OutputStudent();
	}
}