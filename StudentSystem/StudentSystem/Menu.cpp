#include "menu.h"

void menu(StudentManage * pBase, int index)
{

	string title = "";
	switch (index)
	{
	case 1:
		title = "ѧ��������Ϣ�ͳɼ���Ϣ����";
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
		cout << "|  1.���  2.����  3.�޸�   4.ɾ��  5.��ʾ  6.����  7.��ȡ 8.ͳ�� 0=>�˳� |" << endl;
		cout << "|                                                                         |" << endl;
		cout << "+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
		cout << "\n������������ѡ�";
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
			cout << "�˳��ɹ���" << endl;
			break;
		default:
			cout << "�޴�ѡ��!������!" << endl;
			break;
		}
	}
}


