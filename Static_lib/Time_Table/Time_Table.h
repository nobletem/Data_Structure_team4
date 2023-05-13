#ifndef TIME_TABLE
#define	TIME_TABLE

#include <iostream>
#include <string>
#include <cmath>
#include "params.h"

using namespace std;

class Time_Table {
private:
	int* Table[COL];
public:
	Time_Table();
	~Time_Table();
};

class Work {
private:
	string* work_n;
	string* work_data;
	int* priority;
public:
	
};

#endif TIME_TABLE
