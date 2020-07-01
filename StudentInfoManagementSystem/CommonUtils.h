#include "Student.h"

#pragma once
bool compareAsc(Student a, Student b) {
	return a.getAverage() < b.getAverage();
}

bool compareDesc(Student a, Student b) {
	return a.getAverage() > b.getAverage();
}