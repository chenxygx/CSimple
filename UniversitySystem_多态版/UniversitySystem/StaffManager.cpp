#include "StaffManager.h"

StaffManager::StaffManager()
{
	pStaff = new Staff[MAX_];
	if (!pStaff)
	{
		cout << "allocation failure!!" << endl;
		exit(1);
	}
	cout << "StaffManager()" << endl;
}

StaffManager::~StaffManager()
{
	if (pStaff)
	{
		delete[]pStaff;
		pStaff = NULL;
	}

	cout << "~StaffManager()" << endl;
}

void StaffManager::Add()
{
	if (count >= MAX_)
	{
		cout << "�û�����" << endl;
		return;
	}
	Staff t;
	cout << "��������ӵ���Ա����Ϣ" << endl;
	t.Input();
	for (int i = 0;i<count;i++)
		if (t.GetNumber() == pStaff[i].GetNumber())
		{
			cout << "�ñ�ŵ���Ա�Ѵ���" << endl;
			return;
		}
	pStaff[count] = t;
	count = count + 1;
	cout << "��ӳɹ�!" << endl;
	return;
}

void StaffManager::Show()
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
		<< setw(10) << "������ò"
		<< endl;
	for (int i = 0;i<count;i++)
		pStaff[i].Output();
}

void StaffManager::Search()
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
				if (number == pStaff[i].GetNumber())
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
				if (name == pStaff[i].GetName())
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
			<< setw(10) << "������ò"
			<< endl;
		pStaff[index].Output();
	}
	else
	{
		cout << "���޴���!" << endl;
	}
}

void StaffManager::Edit()
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
		if (number == pStaff[i].GetNumber())
		{
			cout << "���޸�Ա����Ϣ��" << endl;
			pStaff[i].Update();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	cout << "���޴��ˣ�" << endl;
}

void StaffManager::Delete()
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
			if (number == pStaff[i].GetNumber())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pStaff[j] = pStaff[j + 1];
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
			if (name == pStaff[i].GetName())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pStaff[j] = pStaff[j + 1];
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

void StaffManager::Total()
{
	cout << "1 ������    2 ���Ա�ͳ��    3 ��������òͳ��" << endl;
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
			if (pStaff[i].GetSex() == SEX::FEMALE)
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
		int number[3] = { 0,0,0 };
		for (int i = 0;i < count; i++)
		{
			number[pStaff[i].GetPolitics()]++;
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

void StaffManager::Save()
{
	ofstream out("Staff.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	for (int i = 0;i < count; i++)
	{
		out << pStaff[i].GetNumber() << " "
			<< pStaff[i].GetName() << " "
			<< pStaff[i].GetSex() << " "
			<< pStaff[i].GetAge() << " "
			<< pStaff[i].GetPolitics() << endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}

void StaffManager::Read()
{
	ifstream in("Staff.txt", ios::in);
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
	int politics;
	while (in >> number
		>> name
		>> sex
		>> age
		>> politics)
	{
		pStaff[count].SetNumber(number);
		pStaff[count].SetName(name);
		pStaff[count].SetSex(sex);
		pStaff[count].SetAge(age);
		pStaff[count].SetPolitics(politics);
		if (++count >= MAX_)
		{
			break;
		}
	}
	cout << "��ȡ�ɹ���" << endl;
	in.close();
}
