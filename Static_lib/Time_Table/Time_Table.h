#ifndef TIME_TABLE
#define	TIME_TABLE

#include <iostream>
#include <string>
#include <cmath>
#include "params.h"

using namespace std;

class Time_Table {
private:
	bool* Table[COL];
	unsigned int Start_t, End_t, Unit_t;
	unsigned int row;
public:
	void Gen_Time_Table();
	~Time_Table();
	void input_start_t(unsigned int strat_t);
	void input_end_t(unsigned int end_t);
	void input_unit_t(unsigned int unit_t);
	bool show_table(int i, int j);
	unsigned int get_row();
};

#endif TIME_TABLE
