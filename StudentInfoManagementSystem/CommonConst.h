/**
* @Author: QiuTong
* @Date:2020.06.30
* @Version:v1.0.0
* @Description
*	ͨ�ó�����
*/
#pragma once
#include <string>
using std::string;

/*�Ա����*/
const string SEX_TITLE[] = { "Ů", "��" };

/*�Ա�ö��*/
enum class SexEnum {
	WOMAN=0,
	MAN=1
};

/*רҵ����*/
const string MAJOR_TITLE[] = { "�����","�Զ���","���ܿ�ѧ","������","�˹�����" };

/*רҵö��*/
enum class MajorEnum {
	COMPUTERS=0,
	AUTO=1,
	SCIENCE=2,
	ROBOT=3,
	AI=4
};

/*�ɼ�����*/
const int SCORE_MAX = 3;

// ÿ����Ա���������
const int STUDENT_MAX = 50;

/*�ȼ�*/
enum class LevelEnum {
	PERFECT = 0,
	GOOD = 1,
	JUST = 2,
	PASS = 3,
	BAD = 4
};

/*�ȼ�����*/
const string LEVEL_TITLE[] = { 
	"��","��","��","����","������" 
};
