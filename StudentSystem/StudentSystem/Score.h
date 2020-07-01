#include<iostream>
#include"Student.h"
using namespace std;

class Score: public Student
{
public:
	Score(int pid = 0, string pname = "", SEX psex = SEX::FEMALE, int page = 0, int pmajor = 0,
		int pscore = 0);

	int GetScore() { return score; }
	void SetScore(int pscore) { score = pscore; }
	
	void Input();
	void Update();
	void Output();
protected:
	int score;
	//³É¼¨
};
