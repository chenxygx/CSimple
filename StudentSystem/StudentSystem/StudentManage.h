#pragma once
#include "Student.h"
#include<fstream>

class StudentManage
{
public:
	StudentManage() { cout << "StudentManage()" << endl; };

	virtual void Add() = 0;            //实现该类记录的添加；
	virtual void Show() = 0;          //实现该类所有记录的显示； 
	virtual void Search() = 0;        //实现该类记录的查询；
	virtual void Edit() = 0;             //实现该类记录的修改；
	virtual void Delete() = 0;        //实现该类记录的删除；
	virtual void Total() = 0;          //实现该类记录的统计；
	virtual void Save() = 0;           //将该类记录保存到文件；
	virtual void Read() = 0;          //可从文件中将记录读取到该类的数组中；
private:
	Student *pStudent;
	int count;
};