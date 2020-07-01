/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	成绩实体
*/
#pragma once
class Score
{
public:
	Score() {
		mathematics = 0;
		english = 0;
		c = 0;
	}

	/*设置数学成绩*/
	void setMathematics(double mathematics) {
		this->mathematics = mathematics;
	}
	/*获取数学成绩*/
	double getMathematics() {
		return this->mathematics;
	}
	/*设置英语成绩*/
	void setEnglish(double english) {
		this->english = english;
	}
	/*获取英语成绩*/
	double getEnglish() {
		return this->english;
	}
	/*设置C++成绩*/
	void setC(double c) {
		this->c = c;
	}
	/*获取C++成绩*/
	double getC() {
		return this->c;
	}
private:
	/*数学*/
	double mathematics;
	/*英语*/
	double english;
	/*C++*/
	double c;
};

