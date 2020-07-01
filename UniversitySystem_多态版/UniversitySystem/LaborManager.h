/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*     实验员管理类
*/

#pragma once

#include <fstream>
#include "PersonManager.h"
#include "Labor.h"

class LaborManager:public PersonManager
{
public :
	LaborManager();
	~LaborManager();
	void Add();            //实现该类记录的添加；
	void Show();          //实现该类所有记录的显示； 
	void Search();        //实现该类记录的查询；
	void Edit();             //实现该类记录的修改；
	void Delete();        //实现该类记录的删除；
	void Total();          //实现该类记录的统计；
	void Save();           //将该类记录保存到文件；
	void Read();          //可从文件中将记录读取到该类的数组中；
private:
	Labor *pLabor;
	int count;
};