#include "Student.h"


Student::Student(int pid, string pname, SEX psex, int page, int pmajor):
	id(pid), name(pname), sex(psex), age(page),major(pmajor)
{
}

void Student::InputStudent()
{
	int inputSex = -1;
	cout << "������ѧ�ţ�" << endl;
	cin >> id;
	cout << "������������" << endl;
	cin >> name;
	cout << "�������Ա�";
	for (int i = 0; i < 2; i++)
	{
		cout << setw(3) << i << "." << SEX_[i];
	}
	cout << "����";
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
			cout << "����������������룺";
			break;
		}
	}
	cout << "���������䣺" << endl;
	cin >> age;

	int choice = -1;
	cout << "��ѡ��רҵ:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(3) << i << "." << MAJOR_[i];
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
			major = choice;
			break;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	}
}

void Student::UpdateStudent()
{
	int inputSex = -1;
	cout << "���޸�������" << endl;
	cin >> name;
	cout << "���޸��Ա�";
	for (int i = 0; i < 2; i++)
	{
		cout << setw(3) << i << "." << SEX_[i];
	}
	cout << "����";
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
			cout << "����������������룺";
			break;
		}
	}
	cout << "���޸����䣺" << endl;
	cin >> age;

	int choice = -1;
	cout << "���޸�רҵ:" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(3) << i << "." << MAJOR_[i];
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
			major = choice;
			break;
		default:
			cout << "����������������룡" << endl;
			break;
		}
	}
}

void Student::OutputStudent()
{
	cout << setw(8) << id
		<< setw(10) << name
		<< setw(10) << SEX_[sex]
		<< setw(10) << age
		<< setw(10) << MAJOR_[major];
}
