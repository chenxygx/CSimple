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
		cout << "用户已满" << endl;
		return;
	}
	Score t;
	cout << "输入新添加的学生信息" << endl;
	t.Input();
	for (int i = 0; i<count; i++)
		if (t.GetId() == pScore[i].GetId())
		{
			cout << "该学号的学生已存在" << endl;
			return;
		}
	pScore[count] = t;
	count = count + 1;
	cout << "添加成功!" << endl;
	return;
}

void ScoreManage::Show()
{
	if (count == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	cout << setw(8) << "学号"
		<< setw(10) << "姓名"
		<< setw(10) << "性别"
		<< setw(10) << "年龄"
		<< setw(10) << "专业"
		<< setw(10) << "成绩"
		<< endl;
	for (int i = 0; i<count; i++)
		pScore[i].Output();
}

void ScoreManage::Search()
{
	bool isFind = false; // 标识是否找到的flag
	int index = 0;       // 目标索引
	if (count == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int choice = 0;
	cout << "请选择查找方式：1.按学生学号查找 2.按学生姓名查找 " << endl;
	while (choice != 1 && choice != 2)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入要查找的学生学号：" << endl;
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
			cout << "请输入要查找的学生姓名：" << endl;
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
			cout << "无此选项！\n请重新选择查找方式：1.按学生学号查找 2.按学生姓名查找 " << endl;
			break;
		}
	}
	if (isFind)
	{
		cout << "查询结果：" << endl;
		cout << setw(8) << "学号"
			<< setw(10) << "姓名"
			<< setw(10) << "性别"
			<< setw(10) << "年龄"
			<< setw(10) << "专业"
			<< setw(10) << "成绩"
			<< endl;
		pScore[index].Output();
	}
	else
	{
		cout << "查无此人!" << endl;
	}
}

void ScoreManage::Edit()
{
	if (count == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "请输入要修改的学生学号：" << endl;
	int id;
	cin >> id;
	for (int i = 0; i < count; i++)
	{
		if (id == pScore[i].GetId())
		{
			cout << "请修改学生信息：" << endl;
			pScore[i].Update();
			cout << "修改成功！" << endl;
			return;
		}
	}
	cout << "查无此人！" << endl;
}

void ScoreManage::Delete()
{
	if (count == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "请选择删除方式：1.按学生学号查找 2.按学生姓名查找 " << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入员工编号：" << endl;
		int id;
		cin >> id;
		for (int i = 0; i < count; i++)
		{
			if (id == pScore[i].GetId())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j<count - 1; j++)
						pScore[j] = pScore[j + 1];
					cout << "删除成功！" << endl;
					count--;
				};
				break;
				case 2:
					break;
				default:
					cout << "输入错误，操作失败！" << endl;
					break;
				}
				return;
			}
		}
		cout << "无此人！" << endl;
	};
	break;
	case 2:
	{
		cout << "请输入学生姓名：" << endl;
		string name;
		cin >> name;;
		for (int i = 0; i < count; i++)
		{
			if (name == pScore[i].GetName())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i; j<count - 1; j++)
						pScore[j] = pScore[j + 1];
					cout << "删除成功！" << endl;
					count--;
				};
				break;
				case 2:
					break;
				default:
					cout << "输入错误，操作失败！" << endl;
					break;
				}
				return;
			}
		}
		cout << "无此人！" << endl;
	};
	break;
	default:
		cout << "无此项，操作失败！" << endl;
		break;
	}
}

void ScoreManage::Total()
{
	cout << "1 总人数    2 按性别统计    3 按专业统计" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "学生总人数为:" << count << endl;
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
		cout << "女同学总人数为:" << id[SEX::FEMALE] << endl;
		cout << "男同学总人数为:" << id[SEX::MALE] << endl;
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
			cout << MAJOR_[i] << "学生总人数为：" << id[i] << endl;
		}
	};
	break;
	default:
		cout << "无此项，操作失败！" << endl;
		break;
	}
}

void ScoreManage::Save()
{
	ofstream out("Score.txt", ios::out);
	if (!out)
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	cout << "文件打开成功!" << endl;
	for (int i = 0; i < count; i++)
	{
		out << pScore[i].GetId() << " "
			<< pScore[i].GetName() << " "
			<< pScore[i].GetSex() << " "
			<< pScore[i].GetAge() << " "
			<< pScore[i].GetMajor() << " "
			<< pScore[i].GetScore() << endl;
	}
	cout << "写入成功！" << endl;
	out.close();
}

void ScoreManage::Read()
{
	ifstream in("Score.txt", ios::in);
	if (!in)
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	cout << "文件打开成功!" << endl;
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
	cout << "读取成功！" << endl;
	in.close();
}
