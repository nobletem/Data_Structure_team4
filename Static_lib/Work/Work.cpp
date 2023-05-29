#include <iostream>
#include "Data_Struct.h"
#include "Work.h"
#include "params.h"

using namespace std;

Work::Work()
{
	this->work_data = new Queue[MAX_Work_data];
}

Work::~Work()
{
	delete[] work_data;
}

bool Work::input_work_n(string work_n)
{
	string a;
	if (work_n == a) {
		return false;
	}
	this->work_n.addQueue(work_n);
	return true;
}

bool Work::input_work_data(int index, unsigned char D, unsigned char s_h, unsigned char s_m, unsigned char e_h, unsigned char e_m)
{
	if (index < 0 && index >= MAX_Work_data) {
		return false;
	}
	if (s_h > 24 && e_h > 24) {
		return false;
	}
	if (s_m > 60 && e_m > 60) {
		return false;
	}
	unsigned int temp = 0;
	temp = ((D << 22) | (s_h << 17) | (s_m << 11) | (e_h << 6) | e_m);
	this->work_data[index].addQueue(temp);
	return true;
}

bool Work::input_priority(int priority)
{
	if (priority <= 0 && priority > MAX_Work_Name) return false;
	this->priority.addQueue(priority);
	return true;
}

string Work::get_work_n()
{
	return this->work_n.deleteQueue();
}

unsigned int Work::get_work_data(int index)
{
	return this->work_data[index].deleteQueue();
}

int Work::get_priority()
{
	return this->priority.deleteQueue();
}

int Work::get_size()
{
	return this->work_n.getSize();
}

int Work::work_data_size(int index)
{
	return this->work_data[index].getSize();
}

/*
	cout << "Day : " << temp[0] << "s_h : " << temp[1] << " s_m : " << temp[2] << " e_h : " << temp[3] << " e_m : " << temp[4] << endl;

*/
unsigned int Work::get_day(unsigned int data)
{
	return (data >> 22);
}
unsigned int Work::get_start_t(unsigned int data)
{
	return (((data >> 17) & 0x1F) * 60) + ((data >> 11) & 0x3F);
}
unsigned int Work::get_end_t(unsigned int data)
{
	return (((data >> 6) & 0x1F) * 60) + ((data & 0x3F));
}