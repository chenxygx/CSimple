#include<iomanip>
#include "TeacherManager.h"

TeacherManager::TeacherManager()
{
	pTeacher = new Teacher[MAX_];
	if (!pTeacher)
	{
		cout << "allocation failure!!" << endl;
		exit(1);
	}
	count = 0;
	cout << "TeacherManager()" << endl;
}

TeacherManager::~TeacherManager()
{
	if (pTeacher)
	{
		delete[]pTeacher;
		pTeacher = NULL;
	}
	cout << "~TeacherManager()" << endl;
}

void TeacherManager::Add()
{
	if (count >= MAX_)
	{
		cout << "�û�����" << endl;
		return;
	}
	Teacher t;
	cout << "��������ӵ���Ա����Ϣ" << endl;
	t.Input();
	for (int i = 0;i<count;i++)
		if (t.GetNumber() == pTeacher[i].GetNumber())
		{
			cout << "�ñ�ŵ���Ա�Ѵ���" << endl;
			return;
		}
	pTeacher[count] = t;
	count = count + 1;
	cout << "��ӳɹ�!" << endl;
	return;
}

void TeacherManager::Show()
{
	if (count == 0)
	{
		cout << "������!" << endl;
		return;
	}
	cout << setw(8) << "���"
		<< setw(10) << "����"
		<< setw(10) << "�Ա�"
		<< setw(10) << "����"
		<< setw(10) << "ϵ��"
		<< setw(10) << "רҵ"
		<< setw(10) << "ְ��"
		<< endl;
	for (int i = 0;i<count;i++)
		pTeacher[i].Output();
}

void TeacherManager::Search()
{
	bool isFind = false; // ��ʶ�Ƿ��ҵ���flag
	int index = 0;       // Ŀ������
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int choice = 0;
	cout << "��ѡ����ҷ�ʽ��1.��Ա����Ų��� 2.��Ա���������� " << endl;
	while (choice != 1 && choice != 2)
	{
		cin >> choice;
		switch (choice)
		{
			case 1:
			{
				cout << "������Ҫ���ҵ�Ա����ţ�" << endl;
				int number;
				cin >> number;
				for (int i = 0;i < count;i++)
				{
					if (number == pTeacher[i].GetNumber())
					{
						isFind = true;
						index = i;
						break;
					}
				}
			}
			break;
			case 2:
			{
				cout << "������Ҫ���ҵ�Ա��������" << endl;
				string name;
				cin >> name;
				for (int i = 0;i < count;i++)
				{
					if (name == pTeacher[i].GetName())
					{
						isFind = true;
						index = i;
						break;
					}
				}
			}
			break;
			default:
				cout << "�޴�ѡ�\n������ѡ����ҷ�ʽ��1.��Ա����Ų��� 2.��Ա����������" << endl;
				break;
		}
	}
	if (isFind)
	{
		cout << "��ѯ�����" << endl;
		cout << setw(8) << "���"
			<< setw(10) << "����"
			<< setw(10) << "�Ա�"
			<< setw(10) << "����"
			<< setw(10) << "ϵ��"
			<< setw(10) << "רҵ"
			<< setw(10) << "ְ��"
			<< endl;
		pTeacher[index].Output();
	}
	else
	{
		cout << "���޴���!" << endl;
	}
}

void TeacherManager::Edit()
{
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "������Ҫ�޸ĵ�Ա����ţ�" << endl;
	int number;
	cin >> number;
	for (int i = 0;i < count;i++)
	{
		if (number == pTeacher[i].GetNumber())
		{
			cout << "���޸�Ա����Ϣ��" << endl;
			pTeacher[i].Update();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	cout << "���޴��ˣ�" << endl;
}

void TeacherManager::Delete()
{
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "��ѡ��ɾ����ʽ��1����Ա�����ɾ��  2����Ա������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
		case 1:
		{
			cout << "������Ա����ţ�" << endl;
			int number;
			cin >> number;
			for (int i = 0;i < count;i++)
			{
				if (number == pTeacher[i].GetNumber())
				{
					cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
					int choice;
					cin >> choice;
					switch (choice)
					{
						case 1:
						{
							for (int j = i;j<count - 1;j++)
								pTeacher[j] = pTeacher[j + 1];
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
			cout << "������Ա��������" << endl;
			string name;
			cin >> name;;
			for (int i = 0;i < count;i++)
			{
				if (name == pTeacher[i].GetName())
				{
					cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
					int choice;
					cin >> choice;
					switch (choice)
					{
					case 1:
					{
						for (int j = i;j<count - 1;j++)
							pTeacher[j] = pTeacher[j + 1];
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
		default:
			cout << "�޴������ʧ�ܣ�" << endl;
			break;
	}
}

void TeacherManager::Total()
{
	cout << "1 ������    2 ���Ա�ͳ��    3 ��ϵ��ͳ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "��ʦ������Ϊ:" << count << endl;
		break;
	case 2:
	{
		int number[] = { 0,0 };
		for (int i = 0;i < count ; i++)
		{
			if (pTeacher[i].GetSex() == SEX::FEMALE)
				number[SEX::FEMALE]++;
			else
				number[SEX::MALE]++;
		}
		cout << "Ů��ʦ������Ϊ:" << number[SEX::FEMALE] << endl;
		cout << "�н�ʦ������Ϊ:" << number[SEX::MALE] << endl;
	};
	break;
	case 3:
	{
		int number[10] = { 0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0;i < count; i++)
		{
			number[pTeacher[i].GetDept()]++;
		}
		for (int i = 0;i < 10;i++)
		{
			cout << DEPT_[i] << "��ʦ������Ϊ��" << number[i] << endl;
		}
	};
	break;
	default:
		cout << "�޴������ʧ�ܣ�" << endl;
		break;
	}
}

void TeacherManager::Save()
{
	ofstream out("Teacher.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	for (int i = 0;i < count; i++)
	{
		out << pTeacher[i].GetNumber() << " "
			<< pTeacher[i].GetName() << " "
			<< pTeacher[i].GetSex() << " "
			<< pTeacher[i].GetAge() << " "
			<< pTeacher[i].GetDept() << " "
			<< pTeacher[i].GetMajor() << " "
			<< pTeacher[i].GetTitle() << endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}

void TeacherManager::Read()
{
	ifstream in("Teacher.txt", ios::in);
	if (!in)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	int number;
	string name;
	int sex;
	int age;
	int dept;
	string major;
	string title;
	while (in >> number
		>> name
		>> sex
		>> age
		>> dept
		>> major
		>> title)
	{
		pTeacher[count].SetNumber(number);
		pTeacher[count].SetName(name);
		pTeacher[count].SetSex(sex);
		pTeacher[count].SetAge(age);
		pTeacher[count].SetDept(dept);
		pTeacher[count].SetMajor(major);
		pTeacher[count].SetTitle(title);
		if (++count >= MAX_)
		{
			break;
		}
	}
	cout << "��ȡ�ɹ���" << endl;
	in.close();
}
