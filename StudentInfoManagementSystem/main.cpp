#include <iostream>
#include "StudentManager.h"

using std::cout;
using std::endl;
using std::cin;

int main()
{
	cout << "                ***欢迎进入沈阳城市学院人员管理系统***" << endl;
	StudentManager* studentManager = new StudentManager();
	int choice = -1;
	while (choice != 0)
	{
		cout << " \n                          ***";
		cout << "学生管理";
		cout << "***                   " << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "|                                                                         |" << endl;
		cout << "|  1.添加 2.列表 3.查找 4.修改 5.删除 6.清空 7.统计                       |" << endl;
		cout << "|  8.保存文件 9.读取文件 10.排序 0=>退出                                     |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n输入您操作的选项：";
		cin >> choice;
		switch (choice)
		{
		case 1:
			studentManager->Add();
			break;
		case 2:
			studentManager->Show();
			break;
		case 3:
			studentManager->Search();
			break;
		case 4:
			studentManager->Update();
			break;
		case 5:
			studentManager->Delete();
			break;
		case 6:
			studentManager->Truncate();
			break;
		case 7:
			studentManager->Total();
			break;
		case 8:
			studentManager->Save();
			break;
		case 9:
			studentManager->Read();
			break;
		case 10:
			studentManager->Sort();
			break;
		case 0:
			cout << "退出成功！" << endl;
			break;
		default:
			cout << "无此选项!请重试!" << endl;
			break;
		}
	}

	cout << "\n                      ***欢迎您下次再使用本系统!***" << endl;
	delete studentManager;
	system("pause");
	return 0;
}
