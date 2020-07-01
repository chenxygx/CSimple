/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	学生操作管理
*/
#pragma once
#include "Student.h"
#include "PersonManager.h"
class StudentManager : public PersonManager
{
public:
	StudentManager();
	~StudentManager();
	/*添加*/
	void Add();
	/*展示*/
	void Show();
	/*搜索*/
	void Search();
	/*更新*/
	void Update();
	/*删除*/
	void Delete();
	/*清空*/
	void Truncate();
	/*统计*/
	void Total();
	/*持久化*/
	void Save();
	/*获取文件内容*/
	void Read();
	/*平均分排序*/
	void Sort();
private:
	/*学生集合*/
	Student* pStudent;
	/*学生集合数量*/
	int count;
};

