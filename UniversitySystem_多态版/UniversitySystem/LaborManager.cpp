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
		cout << "用户已满" << endl;
		return;
	}
	Labor t;
	cout << "输入新添加的人员的信息" << endl;
	t.Input();
	for (int i = 0;i<count;i++)
		if (t.GetNumber() == pLabor[i].GetNumber())
		{
			cout << "该编号的人员已存在" << endl;
			return;
		}
	pLabor[count] = t;
	count = count + 1;
	cout << "添加成功!" << endl;
	return;
}

void LaborManager::Show()
{
	if (count == 0)
	{
		cout << "无数据!" << endl;
		return;
	}
	cout << setw(8) << "编号"
		<< setw(10) << "姓名"
		<< setw(10) << "性别"
		<< setw(10) << "年龄"
		<< setw(10) << "职务"
		<< endl;
	for (int i = 0;i<count;i++)
		pLabor[i].Output();
}

void LaborManager::Search()
{
	bool isFind = false; // 标识是否找到的flag
	int index = 0;       // 目标索引
	if (count == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	int choice = 0;
	cout << "请选择查找方式：1.按员工编号查找 2.按员工姓名查找 " << endl;
	while (choice != 1 && choice != 2)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "请输入要查找的员工编号：" << endl;
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
			cout << "请输入要查找的员工姓名：" << endl;
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
			cout << "无此选项！\n请重新选择查找方式：1.按员工编号查找 2.按员工姓名查找" << endl;
			break;
		}
	}
	if (isFind)
	{
		cout << "查询结果：" << endl;
		cout << setw(8) << "编号"
			<< setw(10) << "姓名"
			<< setw(10) << "性别"
			<< setw(10) << "年龄"
			<< setw(10) << "职务"
			<< endl;
		pLabor[index].Output();
	}
	else
	{
		cout << "查无此人!" << endl;
	}
}

void LaborManager::Edit()
{
	if (count == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "请输入要修改的员工编号：" << endl;
	int number;
	cin >> number;
	for (int i = 0;i < count;i++)
	{
		if (number == pLabor[i].GetNumber())
		{
			cout << "请修改员工信息：" << endl;
			pLabor[i].Update();
			cout << "修改成功！" << endl;
			return;
		}
	}
	cout << "查无此人！" << endl;
}

void LaborManager::Delete()
{
	if (count == 0)
	{
		cout << "当前系统中没有存储记录!" << endl;
		return;
	}
	cout << "请选择删除方式：1、按员工编号删除  2、按员工姓名删除" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		cout << "请输入员工编号：" << endl;
		int number;
		cin >> number;
		for (int i = 0;i < count;i++)
		{
			if (number == pLabor[i].GetNumber())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pLabor[j] = pLabor[j + 1];
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
		cout << "请输入员工姓名：" << endl;
		string name;
		cin >> name;;
		for (int i = 0;i < count;i++)
		{
			if (name == pLabor[i].GetName())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pLabor[j] = pLabor[j + 1];
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

void LaborManager::Total()
{
	cout << "1 总人数    2 按性别统计    3 按职务统计" << endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
		cout << "教师总人数为:" << count << endl;
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
		cout << "女教师总人数为:" << number[SEX::FEMALE] << endl;
		cout << "男教师总人数为:" << number[SEX::MALE] << endl;
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
			cout << DUTY_[i] << "教师总人数为：" << number[i] << endl;
		}
	};
	break;
	default:
		cout << "无此项，操作失败！" << endl;
		break;
	}
}

void LaborManager::Save()
{
	ofstream out("Labor.txt", ios::out);
	if (!out)
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	cout << "文件打开成功!" << endl;
	for (int i = 0;i < count; i++)
	{
		out << pLabor[i].GetNumber() << " "
			<< pLabor[i].GetName() << " "
			<< pLabor[i].GetSex() << " "
			<< pLabor[i].GetAge() << " "
			<< pLabor[i].GetDuty() << endl;
	}
	cout << "写入成功！" << endl;
	out.close();
}

void LaborManager::Read()
{
	ifstream in("Labor.txt", ios::in);
	if (!in)
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	cout << "文件打开成功!" << endl;
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
	cout << "读取成功！" << endl;
	in.close();
}
