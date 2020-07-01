/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	ѧ��ʵ��
*/
#pragma once
#include "Person.h"
#include "Score.h"
class Student :
	virtual public Person {
public:
	/*����ѧ��*/
	void setNumber(int number) {
		this->number = number;
	}
	/*��ȡѧ��*/
	int getNumber() {
		return this->number;
	}
	/*����רҵ*/
	void setMajor(MajorEnum major) {
		this->major = (int)major;
	}
	/*����רҵ*/
	void setMajor(int major) {
		this->major = major;
	}
	/*��ȡרҵ*/
	int getMajor() {
		return this->major;
	}
	/*��ȡרҵ*/
	string getMajorTitle() {
		return MAJOR_TITLE[this->major];
	}
	/*���óɼ�*/
	void setScore(Score score) {
		this->score = score;
	}
	/*��ȡ�ɼ�*/
	Score getScore() {
		return this->score;
	}
	/*�ܷ�*/
	double getSum() {
		return (this->score.getMathematics() + this->score.getEnglish() + this->score.getC());
	}
	/*��ȡƽ����*/
	double getAverage() {
		return (this->score.getMathematics() + this->score.getEnglish() + this->score.getC()) / 3;
	}
	/*�ȼ����ֱ���*/
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
	/*�ȼ����ֱ���*/
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
	/*�ɼ��б�*/
	Score score;
	void InputStudent();
	void UpdateStudent();
	void OutputStudent();
private:
	/*ѧ��*/
	int number;
	/*רҵ*/
	int major;
	/*ƽ����*/
	double average;
};

