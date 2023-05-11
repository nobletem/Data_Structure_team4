#include <iostream>
#include <string>
#include <cmath>
#include "Time_Table.h"
#include "params.h"

using namespace std;

Time_Table::Time_Table() 
{
	int Start_t, end_t, Unit_t;
	int row = 0;
	cin >> Start_t >> end_t >> Unit_t;

	row = ceil((COL * (end_t - Start_t))*(60 / Unit_t));	
	//cout << row << endl;	
	for (int i = 0; i < COL; i++) {
		Table[i] = new int[row];
	}
	
}

Time_Table::~Time_Table()
{
	
	for (int i = 0; i < COL; i++) {
		delete Table[i];
	}
	
}
