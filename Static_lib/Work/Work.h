#ifndef WORK
#define WORK

#include <iostream>
#include <string>
#include "Data_Struct.h"

using namespace std;

class Work {
private:
	s_Queue work_n;
	Queue* work_data;
	Queue priority;
public:
	Work();
	bool input_work_n(string work_n);
	bool input_work_data(int index, unsigned char D, unsigned char s_h, unsigned char s_m, unsigned char e_h, unsigned char e_m);
	bool input_priority(int priority);
	string get_work_n();
	unsigned int get_work_data(int index);
	int get_priority();				
	int get_size();					// work_n과 priority queue에 담겨있는 원소 개수 출력
	int work_data_size(int index);	// work_data[i]에 담겨 있는 데이터의 개수 출력
	void work_data_divide(unsigned int data);
	~Work();
};

#endif WORK