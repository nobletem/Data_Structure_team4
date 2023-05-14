#include <iostream>
#include <string>
#include <cmath>
#include "Time_Table.h"
#include "params.h"

using namespace std;

void Time_Table::input_start_t(unsigned int strat_t = 0)
{
	this->Start_t = strat_t;
}

void Time_Table::input_end_t(unsigned int end_t)
{
	this->End_t = end_t;
}

void Time_Table::input_unit_t(unsigned int unit_t = 0)
{
	this->Unit_t = unit_t;
}

void Time_Table::Gen_Time_Table()
{	
	this->row = ceil((this->End_t - this->Start_t)*(60 / this->Unit_t));
	if(row < 0){
		cout << "ROW can not be negative" << endl;
		return;
	}

	for (int i = 0; i < COL; i++) {
		Table[i] = new bool[row];
	}

	for(int i = 0; i < COL; i++)
		for(unsigned int j = 0; j < this->row; j++){
			Table[i][j] = false;
		}
}

bool Time_Table::show_table(int i, int j)
{
	return Table[i][j];
}

Time_Table::~Time_Table()
{
	for (int i = 0; i < COL; i++) {
		delete [] Table[i];
	}
}

unsigned int Time_Table::get_row()
{
	return this->row;
}

