#include "Person.h"
using std::cout;
using std::endl;
using std::cin;

void Person::InputPersion() {
	cout << "������ѧ��������";
	cin >> name;
	cout << "������ѧ�����䣺";
	cin >> age;
	if (age < 0 || age > 100) {
		cout << "��ѧ����������������������";
		return;
	}
	cout << "������ѧ���Ա�";
	for (int i = 0; i < 2; i++)
	{
		cout << setw(2) << i << "." << SEX_TITLE[i];
	}
	cout << "����";
	for (;;) {
		cin >> sex;
		if (sex < 0 || sex > 1) {
			cout << "�����������������" << endl;
			continue;
		}
		break;
	}
}

void Person::UpdatePersion() {
	cout << "���޸�ѧ��������";
	cin >> name;
	cout << "���޸�ѧ�����䣺";
	cin >> age;
	if (age < 0 || age > 100) {
		cout << "��ѧ����������������������";
		return;
	}
	cout << "���޸�ѧ���Ա�";
	for (int i = 0; i < 2; i++)
	{
		cout << setw(2) << i << "." << SEX_TITLE[i];
	}
	cout << "����";
	for (;;) {
		cin >> sex;
		if (sex < 0 || sex > 1) {
			cout << "�����������������" << endl;
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