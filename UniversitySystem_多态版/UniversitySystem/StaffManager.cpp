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
		cout << "用户已满" << endl;
		return;
	}
	Staff t;
	cout << "输入新添加的人员的信息" << endl;
	t.Input();
	for (int i = 0;i<count;i++)
		if (t.GetNumber() == pStaff[i].GetNumber())
		{
			cout << "该编号的人员已存在" << endl;
			return;
		}
	pStaff[count] = t;
	count = count + 1;
	cout << "添加成功!" << endl;
	return;
}

void StaffManager::Show()
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
		<< setw(10) << "政治面貌"
		<< endl;
	for (int i = 0;i<count;i++)
		pStaff[i].Output();
}

void StaffManager::Search()
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
			cout << "请输入要查找的员工姓名：" << endl;
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
			<< setw(10) << "政治面貌"
			<< endl;
		pStaff[index].Output();
	}
	else
	{
		cout << "查无此人!" << endl;
	}
}

void StaffManager::Edit()
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
		if (number == pStaff[i].GetNumber())
		{
			cout << "请修改员工信息：" << endl;
			pStaff[i].Update();
			cout << "修改成功！" << endl;
			return;
		}
	}
	cout << "查无此人！" << endl;
}

void StaffManager::Delete()
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
			if (number == pStaff[i].GetNumber())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pStaff[j] = pStaff[j + 1];
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
			if (name == pStaff[i].GetName())
			{
				cout << "是否确认删除？     1、是    2、否  " << endl;
				int choice;
				cin >> choice;
				switch (choice)
				{
				case 1:
				{
					for (int j = i;j<count - 1;j++)
						pStaff[j] = pStaff[j + 1];
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

void StaffManager::Total()
{
	cout << "1 总人数    2 按性别统计    3 按政治面貌统计" << endl;
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
			if (pStaff[i].GetSex() == SEX::FEMALE)
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
		int number[3] = { 0,0,0 };
		for (int i = 0;i < count; i++)
		{
			number[pStaff[i].GetPolitics()]++;
		}
		for (int i = 0;i < 3;i++)
		{
			cout << POLITICS_[i] << "教师总人数为：" << number[i] << endl;
		}
	};
	break;
	default:
		cout << "无此项，操作失败！" << endl;
		break;
	}
}

void StaffManager::Save()
{
	ofstream out("Staff.txt", ios::out);
	if (!out)
	{
		cout << "文件打开失败!" << endl;
		return;
	}
	cout << "文件打开成功!" << endl;
	for (int i = 0;i < count; i++)
	{
		out << pStaff[i].GetNumber() << " "
			<< pStaff[i].GetName() << " "
			<< pStaff[i].GetSex() << " "
			<< pStaff[i].GetAge() << " "
			<< pStaff[i].GetPolitics() << endl;
	}
	cout << "写入成功！" << endl;
	out.close();
}

void StaffManager::Read()
{
	ifstream in("Staff.txt", ios::in);
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
	cout << "读取成功！" << endl;
	in.close();
}
