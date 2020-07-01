#include "Menu.h"
#include "StudentManage.h"
#include"ScoreManage.h"

int main()
{
	cout << "                ***欢迎进入学生管理系统***" << endl;
	int choice;
	StudentManage *pBase;
	
	ScoreManage *scoreManage = new ScoreManage();
	
	do {
		cout << "                          *****主菜单*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                                        ||" << endl;
		cout << "||  1=>学生基础信息和成绩信息管理      2=>退出系统      ||" << endl;
		cout << "||                                                                        ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n请输入您的选择:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			pBase = scoreManage;
			menu(pBase, 1);
			break;
		case 2:cout << "\n您已安全退出系统." << endl; break;
		default:cout << "\n没有此选项.请重选." << endl; break;
		}
	} while (choice != 0);

	cout << "\n                      ***欢迎您下次再使用本系统!***" << endl;
	delete scoreManage;
	system("pause");
	return 0;
}
