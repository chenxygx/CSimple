/**
* Copyright 2020 Li JiaJia. All Right Reserved.
* @Filename:
* @Author: Li JiaJia
* @Date: 2020.1.13
* @Version: 1.0
* @Description:
*/

#include<string>
using namespace std;
#pragma once

// 每类人员的最大数量
const int MAX_ = 50;

// 性别
const string SEX_[] = { "女","男" };

// 教师类所属系别名称
const string DEPT_[] = { "电子系",
						"机械系" ,
						"经管系" ,
						"建工系" ,
						"计算机系" ,
						"外语系" ,
						"财会系" ,
						"材料系" ,
						"文法系",
						"表演系"};

// 行政人员政治面貌
const string POLITICS_[] = { "中共党员",
							"共青团员",
							"群众" };

// 实验员类职务
const string DUTY_[] = { "实验员","实验助理" };

// 性别枚举
enum SEX
{
	FEMALE = 0, // 女
	MALE = 1    // 男
};
