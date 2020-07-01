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
	cout << "������ѧ��ѧ�ţ�";
	cin >> number;
	if (number < 1 || number > 9999) {
		cout << "ѧ��ѧ��������������������";
		return;
	}
	InputPersion();
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
	double math, english, c = 0;
	cout << "��������ѧ�ɼ���";
	cin >> math;
	if (math < 0 || math > 100) {
		cout << "��ѧ�ɼ�������������������";
		return;
	}

	cout << "������Ӣ��ɼ���";
	cin >> english;
	if (english < 0 || english > 100) {
		cout << "Ӣ��ɼ�������������������";
		return;
	}

	cout << "������C++�ɼ���";
	cin >> c;
	if (c < 0 || c > 100) {
		cout << "C++������������������";
		return;
	}
	score.setMathematics(math);
	score.setEnglish(english);
	score.setC(c);
}

void Student::UpdateStudent() {
	cout << "���޸�ѧ��ѧ�ţ�" << endl;
	cin >> number;
	if (number < 1 || number > 9999) {
		cout << "ѧ��ѧ��������������������";
		return;
	}
	UpdatePersion();
	cout << "���޸�ѧ��רҵ��";
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

	double math, english, c = 0;
	cout << "���޸���ѧ�ɼ���";
	cin >> math;
	if (math < 0 || math > 100) {
		cout << "��ѧ�ɼ�������������������";
		return;
	}

	cout << "���޸�Ӣ��ɼ���";
	cin >> english;
	if (english < 0 || english > 100) {
		cout << "Ӣ��ɼ�������������������";
		return;
	}

	cout << "���޸�C++�ɼ���";
	cin >> c;
	if (c < 0 || c > 100) {
		cout << "C++������������������";
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