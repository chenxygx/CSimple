#pragma once
#include<fstream>
#include "StudentManage.h"
#include"Score.h"

class ScoreManage : public StudentManage
{
public:
	ScoreManage();
	void Add();          //实现该类记录的添加；
	void Show();         //实现该类所有记录的显示； 
	void Search();       //实现该类记录的查询；
	void Edit();         //实现该类记录的修改；
	void Delete();       //实现该类记录的删除；
	void Total();        //实现该类记录的统计；
	void Save();         //将该类记录保存到文件；
	void Read();         //可从文件中将记录读取到该类的数组中；
private:
	Score *pScore;
	int count;
};