#ifndef WORK
#define WORK

#include <iostream>
#include <string>
#include "Data_Struct.h"

using namespace std;

class Work {
private:
	string* work_n;
	Queue work_data;
	int* priority;
public:
	void input_work_n(string* work_n);
    void input_work_data(Queue& work_data, unsigned int data);
    void input_priority(int* priority);
};

#endif WORK