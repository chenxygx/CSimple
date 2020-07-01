#include "LaborManager.h"

LaborManager::LaborManager()
{
	pLabor = new Labor[MAX_];
	if (!pLabor)
	{
		cout << "allocation failure!!" << endl;
		exit(1);
	}
	count = 0;
	cout << "LaborManager()" << endl;
}

LaborManager::~LaborManager()
{
	if (pLabor)
	{
		delete []pLabor;
		pLabor = NULL;
	}
	cout << "~LaborManager()" << endl;
}


void LaborManager::Add()
{
	if (count >= MAX_)
	{
		cout << "�û�����" << endl;
		return;
	}
	Labor t;
	cout << "��������ӵ���Ա����Ϣ" << endl;
	t.Input();
	for (int i = 0;i<count;i++)
		if (t.GetNumber() == pLabor[i].GetNumber())
		{
			cout << "�ñ�ŵ���Ա�Ѵ���" << endl;
			return;
		}
	pLabor[count] = t;
	count = count + 1;
	cout << "��ӳɹ�!" << endl;
	return;
}

void LaborManager::Show()
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
		<< setw(10) << "ְ��"
		<< endl;
	for (int i = 0;i<count;i++)
		pLabor[i].Output();
}

void LaborManager::Search()
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
				if (number == pLabor[i].GetNumber())
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
				if (name == pLabor[i].GetName())
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
			<< setw(10) << "ְ��"
			<< endl;
		pLabor[index].Output();
	}
	else
	{
		cout << "���޴���!" << endl;
	}
}

void LaborManager::Edit()
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
		if (number == pLabor[i].GetNumber())
		{
			cout << "���޸�Ա����Ϣ��" << endl;
			pLabor[i].Update();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	cout << "���޴��ˣ�" << endl;
}

void LaborManager::Delete()
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
			if (number == pLabor[i].GetNumber())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pLabor[j] = pLabor[j + 1];
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
			if (name == pLabor[i].GetName())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pLabor[j] = pLabor[j + 1];
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

void LaborManager::Total()
{
	cout << "1 ������    2 ���Ա�ͳ��    3 ��ְ��ͳ��" << endl;
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
			if (pLabor[i].GetSex() == SEX::FEMALE)
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
		int number[2] = { 0,0 };
		for (int i = 0;i < count; i++)
		{
			number[pLabor[i].GetDuty()]++;
		}
		for (int i = 0;i < 2;i++)
		{
			cout << DUTY_[i] << "��ʦ������Ϊ��" << number[i] << endl;
		}
	};
	break;
	default:
		cout << "�޴������ʧ�ܣ�" << endl;
		break;
	}
}

void LaborManager::Save()
{
	ofstream out("Labor.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	for (int i = 0;i < count; i++)
	{
		out << pLabor[i].GetNumber() << " "
			<< pLabor[i].GetName() << " "
			<< pLabor[i].GetSex() << " "
			<< pLabor[i].GetAge() << " "
			<< pLabor[i].GetDuty() << endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}

void LaborManager::Read()
{
	ifstream in("Labor.txt", ios::in);
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
	int duty;
	while (in >> number
		>> name
		>> sex
		>> age
		>> duty)
	{
		pLabor[count].SetNumber(number);
		pLabor[count].SetName(name);
		pLabor[count].SetSex(sex);
		pLabor[count].SetAge(age);
		pLabor[count].SetDuty(duty);
		if (++count >= MAX_)
		{
			break;
		}
	}
	cout << "��ȡ�ɹ���" << endl;
	in.close();
}
