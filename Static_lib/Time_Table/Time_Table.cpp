#include <iostream>
#include <string>
#include <cmath>
#include "Time_Table.h"
#include "params.h"

using namespace std;

bool Time_Table::input_start_t(unsigned int start_t = 9) // Start_t 값 초기화.
{
	if (start_t < 0) return false;
	this->Start_t = start_t;
	return true;
}

bool Time_Table::input_end_t(unsigned int end_t) // end_t 값 초기화.
{
	if (end_t < this->Start_t) {
		cout << " end_t < Start_t" << endl;
		return false;
	}
	if (end_t > 24) return false;

	this->End_t = end_t;
	return true;
}

bool Time_Table::input_unit_t(unsigned int unit_t = 60) // Unit_t 값 초기화.
{
	if (unit_t > (24 * 60)) return false;
	this->Unit_t = unit_t;
	return true;
}

bool Time_Table::Gen_Time_Table() // 시간표 틀을 생성합니다.
{
	this->row = ceil((this->End_t - this->Start_t) * (60 / this->Unit_t));
	if (row < 0) {
		cout << "ROW can not be negative" << endl;
		return false;
	}

	for (int i = 0; i < COL; i++) {
		Table[i] = new bool[row];
	}

	for (int i = 0; i < COL; i++)
		for (unsigned int j = 0; j < this->row; j++) {
			Table[i][j] = false;
		}
	return true;
}

bool Time_Table::show_table(int i, int j) // Table[i][j] 값을 리턴합니다.
{
	return Table[i][j];
}

Time_Table::~Time_Table() // 동적 할당 된 Table 변수를 모두 소멸시킵니다.
{
	for (int i = 0; i < COL; i++) {
		delete[] Table[i];
	}
}

unsigned int Time_Table::get_row() //row 값을 받아옵니다.
{
	return this->row;
}
bool Time_Table::input_work(unsigned int day, unsigned int start, unsigned int end)
{
	bool token = false;
	if (day > 7) {
		cout << "day can not greater than 7" << endl;
		return false;
	}
	if (start < this->Start_t) {
		cout << "The start time is less than the minimum" << endl;
		return false;
	}
	if (end > this->End_t) {
		cout << "The end time is greater than the maximum" << endl;
		return false;
	}
	for (unsigned int i = 0; i < this->row; i++) {
		if ((this->Start_t*60) + (this->Unit_t * i) <= (start*60) && (start * 60) < (this->Start_t * 60) + (this->Unit_t * (i+1))) {
			token = true;
		}
		if (token) {
			this->Table[day][i] = true;
		}
		if ((this->Start_t * 60) + (this->Unit_t * i) < (end*60) && (end * 60) <= (this->Start_t * 60) + (this->Unit_t * (i + 1))) {
			token = false;
		}
	}
	return true;
}