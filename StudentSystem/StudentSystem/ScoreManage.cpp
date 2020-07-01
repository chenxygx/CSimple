#include "ScoreManage.h"
#include<iomanip>

ScoreManage::ScoreManage()
{
	pScore = new Score[MAX_];
	if (!pScore)
	{
		cout << "allocation failure!!" << endl;
		exit(1);
	}
	count = 0;
	cout << "ScoreManage()" << endl;
}

void ScoreManage::Add()
{
	if (count >= MAX_)
	{
		cout << "�û�����" << endl;
		return;
	}
	Score t;
	cout << "��������ӵ�ѧ����Ϣ" << endl;
	t.Input();
	for (int i = 0; i<count; i++)
		if (t.GetId() == pScore[i].GetId())
		{
			cout << "��ѧ�ŵ�ѧ���Ѵ���" << endl;
			return;
		}
	pScore[count] = t;
	count = count + 1;
	cout << "��ӳɹ�!" << endl;
	return;
}

void ScoreManage::Show()
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
		<< setw(10) << "�ɼ�"
		<< endl;
	for (int i = 0; i<count; i++)
		pScore[i].Output();
}

void ScoreManage::Search()
{
	bool isFind = false; // ��ʶ�Ƿ��ҵ���flag
	int index = 0;       // Ŀ������
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	int choice = 0;
	cout << "��ѡ����ҷ�ʽ��1.��ѧ��ѧ�Ų��� 2.��ѧ���������� " << endl;
	while (choice != 1 && choice != 2)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "������Ҫ���ҵ�ѧ��ѧ�ţ�" << endl;
			int id;
			cin >> id;
			for (int i = 0; i < count; i++)
			{
				if (id == pScore[i].GetId())
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
				if (name == pScore[i].GetName())
				{
					isFind = true;
					index = i;
					break;
				}
			}
		}
		break;
		default:
			cout << "�޴�ѡ�\n������ѡ����ҷ�ʽ��1.��ѧ��ѧ�Ų��� 2.��ѧ���������� " << endl;
			break;
		}
	}
	if (isFind)
	{
		cout << "��ѯ�����" << endl;
		cout << setw(8) << "ѧ��"
			<< setw(10) << "����"
			<< setw(10) << "�Ա�"
			<< setw(10) << "����"
			<< setw(10) << "רҵ"
			<< setw(10) << "�ɼ�"
			<< endl;
		pScore[index].Output();
	}
	else
	{
		cout << "���޴���!" << endl;
	}
}

void ScoreManage::Edit()
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
		if (id == pScore[i].GetId())
		{
			cout << "���޸�ѧ����Ϣ��" << endl;
			pScore[i].Update();
			cout << "�޸ĳɹ���" << endl;
			return;
		}
	}
	cout << "���޴��ˣ�" << endl;
}

void ScoreManage::Delete()
{
	if (count == 0)
	{
		cout << "��ǰϵͳ��û�д洢��¼!" << endl;
		return;
	}
	cout << "��ѡ��ɾ����ʽ��1.��ѧ��ѧ�Ų��� 2.��ѧ���������� " << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "������Ա����ţ�" << endl;
		int id;
		cin >> id;
		for (int i = 0; i < count; i++)
		{
			if (id == pScore[i].GetId())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j<count - 1; j++)
						pScore[j] = pScore[j + 1];
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
			if (name == pScore[i].GetName())
			{
				cout << "�Ƿ�ȷ��ɾ����     1����    2����  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j<count - 1; j++)
						pScore[j] = pScore[j + 1];
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

void ScoreManage::Total()
{
	cout << "1 ������    2 ���Ա�ͳ��    3 ��רҵͳ��" << endl;
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
			if (pScore[i].GetSex() == SEX::FEMALE)
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
			id[pScore[i].GetMajor()]++;
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

void ScoreManage::Save()
{
	ofstream out("Score.txt", ios::out);
	if (!out)
	{
		cout << "�ļ���ʧ��!" << endl;
		return;
	}
	cout << "�ļ��򿪳ɹ�!" << endl;
	for (int i = 0; i < count; i++)
	{
		out << pScore[i].GetId() << " "
			<< pScore[i].GetName() << " "
			<< pScore[i].GetSex() << " "
			<< pScore[i].GetAge() << " "
			<< pScore[i].GetMajor() << " "
			<< pScore[i].GetScore() << endl;
	}
	cout << "д��ɹ���" << endl;
	out.close();
}

void ScoreManage::Read()
{
	ifstream in("Score.txt", ios::in);
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
	int score;
	while (in >> id
		>> name
		>> sex
		>> age
		>> major
		>> score)
	{
		pScore[count].SetId(id);
		pScore[count].SetName(name);
		pScore[count].SetSex(sex);
		pScore[count].SetAge(age);
		pScore[count].SetMajor(major);
		pScore[count].SetScore(score);
		if (++count >= MAX_)
		{
			break;
		}
	}
	cout << "��ȡ�ɹ���" << endl;
	in.close();
}
