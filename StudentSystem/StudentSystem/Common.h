#include<string>
using namespace std;
#pragma once

// 最大数量
const int MAX_ = 50;

// 性别
const string SEX_[] = { "女","男" };

const string MAJOR_[] = { "电子系",
"机械系" ,
"经管系" ,
"建工系" ,
"计算机系" ,
"外语系" ,
"财会系" ,
"材料系" ,
"文法系",
"表演系" };

const string SCORE_[] = 
{ 
"数学",
"英语" ,
"C++" ,
 };


// 性别枚举
enum SEX
{
	FEMALE = 0, // 女
	MALE = 1    // 男
};
