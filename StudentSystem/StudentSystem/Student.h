#include <iostream>
#include<string>
#include <iomanip>
#include"Common.h"
using namespace std;

class Student
{
public:
	Student(int pid = 0, string pname = "", SEX psex = SEX::FEMALE, int page = 0,int pmajor = 0);

	int GetId() { return id; }
	string GetName() { return name; }
	SEX GetSex() { return sex; }
	int GetAge() { return age; }
	int GetMajor() { return major; }
	void SetId(int pid) { id = pid; }
	void SetName(string pname) { name = pname; }
	void SetSex(int psex) { sex = (SEX)psex; }
	void SetAge(int page) { age = page; }
	void SetMajor(int pmajor) { major = pmajor; }

	void InputStudent();//����
	void UpdateStudent();//�޸�
	void OutputStudent();//��ʾ
protected:
	int id;   //ѧ��
	string name; // ����
	SEX sex;      // �Ա�
	int age;      // ����	
	int major;  // רҵ
};

