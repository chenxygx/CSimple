/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     ���˵�
*/
#include "menu.h"
#include "PersonManager.h"
#include "LaborManager.h"
#include "TeacherManager.h"
#include "StaffManager.h"
#include "TeaStaffManager.h"

int main()
{
	cout << "                ***��ӭ������������ѧԺ��Ա����ϵͳ***" << endl;
	int choice;
	PersonManager *pBase;
	LaborManager *laborManager = new LaborManager();
	TeacherManager *teacherManager = new TeacherManager();
	StaffManager *staffManager = new StaffManager();
	TeaStaffManager *teaStaffManager = new TeaStaffManager();
	do {
		cout << "                          *****���˵�*****\n" << endl;
		cout << "<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<" << endl;
		cout << "||                                                                        ||" << endl;
		cout << "||1=>ʵ��Ա���� 2=>��ʦ����  3=>�������� 4=��ʦ��������  0=>�˳�ϵͳ      ||" << endl;
		cout << "||                                                                        ||" << endl;
		cout << ">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
		cout << "\n����������ѡ��:";
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
		case 0:cout << "\n���Ѱ�ȫ�˳�ϵͳ." << endl; break;
		default:cout << "\nû�д�ѡ��.����ѡ." << endl; break;
		}
	} while (choice != 0);

	cout << "\n                      ***��ӭ���´���ʹ�ñ�ϵͳ!***" << endl;
	delete laborManager;
	delete teacherManager;
	delete staffManager;
	delete teaStaffManager;
	system("pause");
	return 0;
}
