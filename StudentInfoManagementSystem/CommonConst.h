/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	通用常量集
*/
#pragma once
#include <string>
using std::string;

/*性别标题*/
const string SEX_TITLE[] = { "女", "男" };

/*性别枚举*/
enum class SexEnum {
	WOMAN=0,
	MAN=1
};

/*专业标题*/
const string MAJOR_TITLE[] = { "计算机","自动化","智能科学","机器人","人工智能" };

/*专业枚举*/
enum class MajorEnum {
	COMPUTERS=0,
	AUTO=1,
	SCIENCE=2,
	ROBOT=3,
	AI=4
};

/*成绩上限*/
const int SCORE_MAX = 3;

// 每类人员的最大数量
const int STUDENT_MAX = 50;

/*等级*/
enum class LevelEnum {
	PERFECT = 0,
	GOOD = 1,
	JUST = 2,
	PASS = 3,
	BAD = 4
};

/*等级标题*/
const string LEVEL_TITLE[] = { 
	"优","良","中","及格","不及格" 
};
