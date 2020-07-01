#include<iomanip>
#include"StudentManage.h"


void StudentManage::Add()
{
	if (count >= MAX_)
	{
		cout << "�û�����" << endl;
		return;
	}
	Student t;
	cout << "��������ӵ�ѧ������Ϣ" << endl;
	t.InputStudent();
	for (int i = 0; i<count; i++)
		if (t.GetId() == pStudent[i].GetId())
		{
			cout << "�ñ�ŵ�ѧ���Ѵ���" << endl;
			return;
		}
	pStudent[count] = t;
	count = count + 1;
	cout << "��ӳɹ�!" << endl;
	return;
}

void StudentManage::Show()
{
	if (count == 0)
	{
		cout << "������!" << endl;
		return;
	}
	cout << setw(8) << "ѧ��"
		<< setw(10) << "����"
		<< setw(10) << "�Ա�"
		<< setw(10) << "����"
		<< setw(10) << "רҵ"
		<< endl;
	for (int i = 0; i<count; i++)
		pStudent[i].OutputStudent();
}

void StudentManage::Search()
{
	bool isFind = false; // ��ʶ�Ƿ��ҵ���flag
	int index = 0;       // Ŀ������
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int choice = 0;
	cout << "��ѡ����ҷ�ʽ��1.��ѧ�Ų��� 2.��Ա���������� " << endl;
	while (choice != 1 && choice != 2)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������Ҫ���ҵ�ѧ�ţ�" << endl;
			int id;
			cin >> id;
			for (int i = 0; i < count; i++)
			{
				if (id == pStudent[i].GetId())
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
			cout << "������Ҫ���ҵ�ѧ��������" << endl;
			string name;
			cin >> name;
			for (int i = 0; i < count; i++)
			{
				if (name == pStudent[i].GetName())
				{
					isFind = true;
					index = i;
					break;
				}
			}
		}
		break;
		default:
			cout << "�޴�ѡ�\n������ѡ����ҷ�ʽ��1.��ѧ��ѧ�Ų��� 2.��ѧ����������" << endl;
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
			<< setw(10) << "רҵ"
			<< endl;
		pStudent[index].OutputStudent();
	}
	else
	{
		cout << "���޴���!" << endl;
	}
}

void StudentManage::Edit()
{
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "������Ҫ�޸ĵ�ѧ��ѧ�ţ�" << endl;
	int id;
	cin >> id;
	for (int i = 0; i < count; i++)
	{
		if (id == pStudent[i].GetId())
		{
			cout << "���޸�ѧ����Ϣ��" << endl;
			pStudent[i].UpdateStudent();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	cout << "���޴��ˣ�" << endl;
}

void StudentManage::Delete()
{
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "��ѡ��ɾ����ʽ��1����ѧ��ѧ��ɾ��  2����ѧ������ɾ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "������ѧ�ţ�" << endl;
		int id;
		cin >> id;
		for (int i = 0; i < count; i++)
		{
			if (id == pStudent[i].GetId())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j<count - 1; j++)
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
		cin >> name;;
		for (int i = 0; i < count; i++)
		{
			if (name == pStudent[i].GetName())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j<count - 1; j++)
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
	default:
		cout << "�޴������ʧ�ܣ�" << endl;
		break;
	}
}

void StudentManage::Total()
{
	cout << "1 ������    2 ���Ա�ͳ��    3 ��ϵ��ͳ��" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "ѧ��������Ϊ:" << count << endl;
		break;
	case 2:
	{
		int id[] = { 0,0 };
		for (int i = 0; i < count; i++)
		{
			if (pStudent[i].GetSex() == SEX::FEMALE)
				id[SEX::FEMALE]++;
			else
				id[SEX::MALE]++;
		}
		cout << "Ůͬѧ������Ϊ:" << id[SEX::FEMALE] << endl;
		cout << "��ͬѧ������Ϊ:" << id[SEX::MALE] << endl;
	};
	break;
	case 3:
	{
		int id[10] = { 0,0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < count; i++)
		{
			id[pStudent[i].GetMajor()]++;
		}
		for (int i = 0; i < 10; i++)
		{
			cout << MAJOR_[i] << "ѧ��������Ϊ��" << id[i] << endl;
		}
	};
	break;
	default:
		cout << "�޴������ʧ�ܣ�" << endl;
		break;
	}
}

void StudentManage::Save()
{

	ofstream out("Student.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	for (int i = 0; i < count; i++)
	{
		out << pStudent[i].GetId() << " "
			<< pStudent[i].GetName() << " "
			<< pStudent[i].GetSex() << " "
			<< pStudent[i].GetAge() << " "
			<< pStudent[i].GetMajor() << " " << endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}

void StudentManage::Read()
{
	ifstream in("Student.txt", ios::in);
	if (!in)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	int id;
	string name;
	int sex;
	int age;
	int major;
	while (in >> id
		>> name
		>> sex
		>> age
		>> major)
	{
		pStudent[count].SetId(id);
		pStudent[count].SetName(name);
		pStudent[count].SetSex(sex);
		pStudent[count].SetAge(age);
		pStudent[count].SetMajor(major);
		if (++count >= MAX_)
		{
			break;
		}
	}
	cout << "��ȡ�ɹ���" << endl;
	in.close();
}
