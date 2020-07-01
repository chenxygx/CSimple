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
		cout << "ѧ���������ʼ���쳣" << endl;
		exit(1);
	}
	count = 0;
}

StudentManager::~StudentManager() {
	if (pStudent) {
		delete[] pStudent;
		pStudent = NULL;
	}
	cout << "ѧ���������ͷ�" << endl;
}

void StudentManager::Add() {
	if (count >= STUDENT_MAX) {
		cout << "ѧ����Ա�����޷����" << endl;
		return;
	}
	Student student;
	cout << "�����������ѧ����Ϣ" << endl;
	student.InputStudent();
	for (int i = 0; i < count; i++)
	{
		if (student.getNumber() == pStudent[i].getNumber()) {
			cout << "��ѧ������Ѵ��ڣ�����������" << endl;
			return;
		}
	}
	pStudent[count] = student;
	count = count + 1;
	cout << "��ӳɹ���" << endl;
	return;
}

void ConsoleTitle() {
	cout << setw(8) << "ѧ��"
		<< setw(8) << "����"
		<< setw(8) << "�Ա�"
		<< setw(8) << "����"
		<< setw(12) << "רҵ"
		<< setw(12) << "��ѧ�ɼ�"
		<< setw(12) << "Ӣ��ɼ�"
		<< setw(12) << "C++�ɼ�"
		<< setw(12) << "ƽ����"
		<< setw(12) << "�ܷ�"
		<< setw(12) << "�ȼ�"
		<< endl;
}

void StudentManager::Show() {
	if (count == 0) {
		cout << "�����ݣ�" << endl;
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
		cout << "��ǰϵͳ��û�м�¼��" << endl;
		return;
	}
	int choice = 0;
	cout << "��ѡ���ѯ��ʽ��1.ѧ�ţ�2.������3.������4.�ȼ�" << endl;
	while (choice != 1 && choice != 2)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������Ҫ���ҵ�ѧ��ѧ�ţ�";
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
			cout << "������Ҫ���ҵ�ѧ��������";
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
			cout << "������Ҫ���ҵ�����������";
			int num = 0;
			cin >> num;
			int choice = 0;
			cout << "����������˳�� 1.����2.����";
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
			cout << "������Ҫ���ҵ�ѧ���ȼ���";
			for (int i = 0; i < 5; i++)
			{
				cout << setw(2) << i << "." << LEVEL_TITLE[i];
			}
			cout << "����";
			int level;
			for (;;) {
				cin >> level;
				if (level < 0 || level > 5) {
					cout << "�����������������" << endl;
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
			cout << "�޴�ѡ�������ѡ���ѯ��ʽ��1.ѧ�ţ�2.������3.������4.�ȼ�" << endl;
			break;
		}
	}
	if (isFind) {
		ConsoleTitle();
		pStudent[index].OutputStudent();
	}
	else
	{
		cout << "���޴��ˣ�" << endl;
	}
}

void StudentManager::Update() {
	if (count == 0) {
		cout << "��ǰϵͳ��û�д洢��¼��" << endl;
		return;
	}
	cout << "������Ҫ�޸ĵ�ѧ����ţ�";
	int number;
	cin >> number;
	for (int i = 0; i < count; i++)
	{
		if (number == pStudent[i].getNumber()) {
			cout << "���޸�Ա����Ϣ��" << endl;
			pStudent[i].UpdateStudent();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	cout << "���޴��ˣ�" << endl;
}

void StudentManager::Truncate() {
	cout << "��ѡ����շ�ʽ��1��ȫ�����  2����רҵ���" << endl;
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
		cout << "ѧ���������ͷ�" << endl;
	}
	break;
	case 2: {
		int maj;
		cout << "��ѡ��Ҫ��յ�רҵ��";
		for (int i = 0; i < 5; i++)
		{
			cout << setw(2) << i << "." << MAJOR_TITLE[i];
		}
		cout << "����";
		for (;;) {
			cin >> maj;
			if (maj < 0 || maj > 5) {
				cout << "�����������������" << endl;
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
				cout << "ɾ���ɹ���" << endl;
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
		cout << "��ǰϵͳ��û�д洢��¼��" << endl;
		return;
	}
	cout << "��ѡ��ɾ����ʽ��1����ѧ�����ɾ��  2����ѧ������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "������ѧ����ţ�" << endl;
		int number;
		cin >> number;
		for (int i = 0;i < count;i++)
		{
			if (number == pStudent[i].getNumber())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j < count - 1;j++)
						pStudent[j] = pStudent[j + 1];
					cout << "ɾ���ɹ���" << endl;
					count--;
				};
				break;
				case 2:
					break;
				default:
					cout << "������󣬲���ʧ�ܣ�" << endl;
					break;
				}
				return;
			}
		}
		cout << "�޴��ˣ�" << endl;
	};
	break;
	case 2:
	{
		cout << "������ѧ��������" << endl;
		string name;
		cin >> name;
		int nameCount = 0;
		for (int i = 0;i < count;i++) {
			if (name == pStudent[i].getName()) {
				nameCount = nameCount + 1;
			}
		}
		if (nameCount > 1) {
			cout << "��������ѧ�����Ƿ�ȫ��ɾ���� 1.��  2.��" << endl;
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
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j < count - 1;j++)
						pStudent[j] = pStudent[j + 1];
					cout << "ɾ���ɹ���" << endl;
					count--;
				};
				break;
				case 2:
					break;
				default:
					cout << "������󣬲���ʧ�ܣ�" << endl;
					break;
				}
			}
		}
		cout << "�޴��ˣ�" << endl;
	};
	break;
	default:
		cout << "�޴������ʧ�ܣ�" << endl;
		break;
	}
}

void StudentManager::Total() {
	cout << "1.��ÿ��ѧ���ּܷ�ƽ���� 2.ͬһרҵ��ѧ���ĸ��Ƴɼ�ƽ����";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		for (int i = 0; i < count; i++)
		{
			cout << pStudent[i].getName();
			cout << "�ܷ֣�" << to_string(pStudent[i].getSum()) << "��ƽ���֣�" << to_string(pStudent[i].getAverage()) << endl;
		}
	}
	break;
	case 2:
	{
		int major;
		cout << "������ѧ��רҵ��";
		for (int i = 0; i < 5; i++)
		{
			cout << setw(2) << i << "." << MAJOR_TITLE[i];
		}
		cout << "����";
		for (;;) {
			cin >> major;
			if (major < 0 || major > 5) {
				cout << "�����������������" << endl;
				continue;
			}
			break;
		}
		for (int i = 0; i < count; i++)
		{
			if (pStudent[i].getMajor() == major) {
				cout << pStudent[i].getName();
				cout << "ƽ���֣�" << to_string(pStudent[i].getAverage()) << endl;
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
		cout << "�ļ���ʧ�ܣ�" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ���" << endl;
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
	cout << "д��ɹ���" << endl;
	out.close();
}

void StudentManager::Read() {
	ifstream in("Student.txt", ios::in);
	if (!in) {
		cout << "�ļ���ʧ�ܣ�" << endl;
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
	cout << "��ȡ�ɹ���" << endl;
	in.close();
}

void StudentManager::Sort() {
	if (count == 0) {
		cout << "�����ݣ�" << endl;
		return;
	}
	int desc = 0;
	cout << "����������ʽ��0.����1.����" << endl;
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