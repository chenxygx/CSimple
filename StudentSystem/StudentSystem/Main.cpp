#include "Menu.h"
#include "StudentManage.h"
#include"ScoreManage.h"

int main()
{
	cout << "                ***��ӭ����ѧ������ϵͳ***" << endl;
	int choice;
	StudentManage *pBase;
	
	ScoreManage *scoreManage = new ScoreManage();
	
	do {
		cout << "                          *****���˵�*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                                        ||" << endl;
		cout << "||  1=>ѧ��������Ϣ�ͳɼ���Ϣ����      2=>�˳�ϵͳ      ||" << endl;
		cout << "||                                                                        ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n����������ѡ��:";
		cin >> choice;
		switch (choice)
		{
		case 1:
			pBase = scoreManage;
			menu(pBase, 1);
			break;
		case 2:cout << "\n���Ѱ�ȫ�˳�ϵͳ." << endl; break;
		default:cout << "\nû�д�ѡ��.����ѡ." << endl; break;
		}
	} while (choice != 0);

	cout << "\n                      ***��ӭ���´���ʹ�ñ�ϵͳ!***" << endl;
	delete scoreManage;
	system("pause");
	return 0;
}
