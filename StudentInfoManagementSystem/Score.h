/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	�ɼ�ʵ��
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

	/*������ѧ�ɼ�*/
	void setMathematics(double mathematics) {
		this->mathematics = mathematics;
	}
	/*��ȡ��ѧ�ɼ�*/
	double getMathematics() {
		return this->mathematics;
	}
	/*����Ӣ��ɼ�*/
	void setEnglish(double english) {
		this->english = english;
	}
	/*��ȡӢ��ɼ�*/
	double getEnglish() {
		return this->english;
	}
	/*����C++�ɼ�*/
	void setC(double c) {
		this->c = c;
	}
	/*��ȡC++�ɼ�*/
	double getC() {
		return this->c;
	}
private:
	/*��ѧ*/
	double mathematics;
	/*Ӣ��*/
	double english;
	/*C++*/
	double c;
};

