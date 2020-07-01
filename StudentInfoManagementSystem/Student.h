/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	学生实体
*/
#pragma once
#include "Person.h"
#include "Score.h"
class Student :
	virtual public Person {
public:
	/*设置学号*/
	void setNumber(int number) {
		this->number = number;
	}
	/*获取学号*/
	int getNumber() {
		return this->number;
	}
	/*设置专业*/
	void setMajor(MajorEnum major) {
		this->major = (int)major;
	}
	/*设置专业*/
	void setMajor(int major) {
		this->major = major;
	}
	/*获取专业*/
	int getMajor() {
		return this->major;
	}
	/*获取专业*/
	string getMajorTitle() {
		return MAJOR_TITLE[this->major];
	}
	/*设置成绩*/
	void setScore(Score score) {
		this->score = score;
	}
	/*获取成绩*/
	Score getScore() {
		return this->score;
	}
	/*总分*/
	double getSum() {
		return (this->score.getMathematics() + this->score.getEnglish() + this->score.getC());
	}
	/*获取平均分*/
	double getAverage() {
		return (this->score.getMathematics() + this->score.getEnglish() + this->score.getC()) / 3;
	}
	/*等级划分标题*/
	int getLevel() {
		double average = getAverage();
		if (average >= 90 && average <= 100) {
			return (int)LevelEnum::PERFECT;
		}
		if (average >= 80 && average <= 89) {
			return (int)LevelEnum::GOOD;
		}
		if (average >= 70 && average <= 79) {
			return (int)LevelEnum::JUST;
		}
		if (average >= 60 && average <= 69) {
			return (int)LevelEnum::PASS;
		}
		if (average < 60) {
			return (int)LevelEnum::BAD;
		}
	}
	/*等级划分标题*/
	string getLevelTitle() {
		double average = getAverage();
		if (average >= 90 && average <= 100) {
			return LEVEL_TITLE[(int)LevelEnum::PERFECT];
		}
		if (average >= 80 && average <= 89) {
			return LEVEL_TITLE[(int)LevelEnum::GOOD];
		}
		if (average >= 70 && average <= 79) {
			return LEVEL_TITLE[(int)LevelEnum::JUST];
		}
		if (average >= 60 && average <= 69) {
			return LEVEL_TITLE[(int)LevelEnum::PASS];
		}
		if (average < 60) {
			return LEVEL_TITLE[(int)LevelEnum::BAD];
		}
	}
	/*成绩列表*/
	Score score;
	void InputStudent();
	void UpdateStudent();
	void OutputStudent();
private:
	/*学号*/
	int number;
	/*专业*/
	int major;
	/*平均分*/
	double average;
};

