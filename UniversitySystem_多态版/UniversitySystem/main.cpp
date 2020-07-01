/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     主菜单
*/
#include "menu.h"
#include "PersonManager.h"
#include "LaborManager.h"
#include "TeacherManager.h"
#include "StaffManager.h"
#include "TeaStaffManager.h"

int main()
{
	cout << "                ***欢迎进入沈阳城市学院人员管理系统***" << endl;
	int choice;
	PersonManager *pBase;
	LaborManager *laborManager = new LaborManager();
	TeacherManager *teacherManager = new TeacherManager();
	StaffManager *staffManager = new StaffManager();
	TeaStaffManager *teaStaffManager = new TeaStaffManager();
	do {
		cout << "                          *****主菜单*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                                        ||" << endl;
		cout << "||1=>实验员管理 2=>教师管理  3=>行政管理 4=教师行政管理  0=>退出系统      ||" << endl;
		cout << "||                                                                        ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n请输入您的选择:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			pBase = laborManager;
			menu(pBase, 1);
			break;
		case 2:
			pBase = teacherManager;
			menu(pBase, 2);
			break;
		case 3:
			pBase = staffManager;
			menu(pBase, 3);
			break;
		case 4:
			pBase = teaStaffManager;
			menu(pBase, 4);
			break;
		case 0:cout << "\n您已安全退出系统." << endl; break;
		default:cout << "\n没有此选项.请重选." << endl; break;
		}
	} while (choice != 0);

	cout << "\n                      ***欢迎您下次再使用本系统!***" << endl;
	delete laborManager;
	delete teacherManager;
	delete staffManager;
	delete teaStaffManager;
	system("pause");
	return 0;
}
