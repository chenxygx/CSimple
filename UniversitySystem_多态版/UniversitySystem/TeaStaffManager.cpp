#include "TeaStaffManager.h"

TeaStaffManager::TeaStaffManager()
{
	pTeaStaff = new Tea_Staff[MAX_];
	if (!pTeaStaff)
	{
		cout << "allocation failure!!" << endl;
		exit(1);
	}
	count = 0;
	cout << "TeaStaffManager()" << endl;
}

TeaStaffManager::~TeaStaffManager()
{
	if (pTeaStaff)
	{
		delete[]pTeaStaff;
		pTeaStaff = NULL;
	}
	cout << "~TeaStaffManager()" << endl;
}

void TeaStaffManager::Add()
{
	if (count >= MAX_)
	{
		cout << "�û�����" << endl;
		return;
	}
	Tea_Staff t;
	cout << "��������ӵ���Ա����Ϣ" << endl;
	t.Input();
	for (int i = 0;i<count;i++)
		if (t.GetNumber() == pTeaStaff[i].GetNumber())
		{
			cout << "�ñ�ŵ���Ա�Ѵ���" << endl;
			return;
		}
	pTeaStaff[count] = t;
	count = count + 1;
	cout << "��ӳɹ�!" << endl;
	return;
}

void TeaStaffManager::Show()
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
		<<setw(10) << "������ò"
		<< endl;
	for (int i = 0;i<count;i++)
		pTeaStaff[i].Output();
}

void TeaStaffManager::Search()
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
					if (number == pTeaStaff[i].GetNumber())
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
					if (name == pTeaStaff[i].GetName())
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
			<< setw(10) << "������ò"
			<< endl;
		pTeaStaff[index].Output();
	}
	else
	{
		cout << "���޴���!" << endl;
	}
}

void TeaStaffManager::Edit()
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
		if (number == pTeaStaff[i].GetNumber())
		{
			cout << "���޸�Ա����Ϣ��" << endl;
			pTeaStaff[i].Update();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	cout << "���޴��ˣ�" << endl;
}

void TeaStaffManager::Delete()
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
			if (number == pTeaStaff[i].GetNumber())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pTeaStaff[j] = pTeaStaff[j + 1];
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
			if (name == pTeaStaff[i].GetName())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pTeaStaff[j] = pTeaStaff[j + 1];
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

void TeaStaffManager::Total()
{
	cout << "1 ������    2 ���Ա�ͳ��    3 ��ϵ��ͳ��    4 ��������òͳ��" << endl;
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
		for (int i = 0;i < count; i++)
		{
			if (pTeaStaff[i].GetSex() == SEX::FEMALE)
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
			number[pTeaStaff[i].GetDept()]++;
		}
		for (int i = 0;i < 10;i++)
		{
			cout << DEPT_[i] << "��ʦ������Ϊ��" << number[i] << endl;
		}
	};
	break;
	case 4:
	{
		int number[3] = { 0,0,0 };
		for (int i = 0;i < count; i++)
		{
			number[pTeaStaff[i].GetPolitics()]++;
		}
		for (int i = 0;i < 3;i++)
		{
			cout << POLITICS_[i] << "��ʦ������Ϊ��" << number[i] << endl;
		}
	};
	break;
	default:
		cout << "�޴������ʧ�ܣ�" << endl;
		break;
	}
}

void TeaStaffManager::Save()
{
	ofstream out("TeaStaff.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	for (int i = 0;i < count; i++)
	{
		out << pTeaStaff[i].GetNumber() << " "
			<< pTeaStaff[i].GetName() << " "
			<< pTeaStaff[i].GetSex() << " "
			<< pTeaStaff[i].GetAge() << " "
			<< pTeaStaff[i].GetDept() << " "
			<< pTeaStaff[i].GetMajor() << " "
			<< pTeaStaff[i].GetTitle() << " "
			<< pTeaStaff[i].GetPolitics() << endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}

void TeaStaffManager::Read()
{
	ifstream in("TeaStaff.txt", ios::in);
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
	int politics;
	while (in >> number
		>> name
		>> sex
		>> age
		>> dept
		>> major
		>> title
		>> politics)
	{
		pTeaStaff[count].SetNumber(number);
		pTeaStaff[count].SetName(name);
		pTeaStaff[count].SetSex(sex);
		pTeaStaff[count].SetAge(age);
		pTeaStaff[count].SetDept(dept);
		pTeaStaff[count].SetMajor(major);
		pTeaStaff[count].SetTitle(title);
		pTeaStaff[count].SetPolitics(politics);
		if (++count >= MAX_)
		{
			break;
		}
	}
	cout << "��ȡ�ɹ���" << endl;
	in.close();
}
