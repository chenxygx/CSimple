#include "menu.h"

void menu(StudentManage * pBase, int index)
{

	string title = "";
	switch (index)
	{
	case 1:
		title = "学生基础信息和成绩信息管理";
		break;
	}
	int choice = -1;
	while (choice != 0)
	{
		cout << " \n                          ***";
		cout << title;
		cout << "***                   " << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                         |" << endl;
		cout << "|  1.添加  2.查找  3.修改   4.删除  5.显示  6.保存  7.读取 8.统计 0=>退出 |" << endl;
		cout << "|                                                                         |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n输入您操作的选项：";
		cin >> choice;
		switch (choice)
		{
		case 1:
			pBase->Add();
			break;
		case 2:
			pBase->Search();
			break;
		case 3:
			pBase->Edit();
			break;
		case 4:
			pBase->Delete();
			break;
		case 5:
			pBase->Show();
			break;
		case 6:
			pBase->Save();
			break;
		case 7:
			pBase->Read();
			break;
		case 8:
			pBase->Total();
			break;
		case 0:
			cout << "退出成功！" << endl;
			break;
		default:
			cout << "无此选项!请重试!" << endl;
			break;
		}
	}
}


