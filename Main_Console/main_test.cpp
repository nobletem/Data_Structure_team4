#include <iostream>
#include "Data_Struct.h"
#include "Time_Table.h"
#include "Work.h"

using namespace std;

int main()
{
	/* 
	* Queue Test
	Queue a;
	for (int i = 0; i < 10; i++) {
		a.addQueue(i);
	}
	cout << a.getSize() << endl;
	for (int i = 0; i < 10; i++) {
		cout << a.deleteQueue() << endl;
	}
	*/
	/*
	* Time_Table Test
	Time_Table a;
	a.input_start_t(9);
	a.input_end_t(13);
	a.input_unit_t(60);
	a.Gen_Time_Table();
	for (int i = 0; i < COL; i++) {
		for (unsigned int j = 0; j < a.get_row(); j++) {
			cout << int(a.show_table(i, j)) << " ";
		}
		cout << endl;
	}
	*/
	Work a;
	string str[10];
	int p[10];
	int t;
	cout << "Input work name 6 " << endl;
	for (int i = 0; i < 6; i++) { // 일 이름 10개 입력
		cout << ">>  ";
		getline(cin, str[i]);
		cout << (bool)a.input_work_n(str[i]) << endl;
		cout << str[i] << endl;
	}
	cout << "number of Work : " << a.get_size() << endl;
	t = a.get_size();
	cout << "Work name list" << endl;
	for (int i = 0; i < t; i++) {
		cout << a.get_work_n() << endl;
	}
	cout << "=========================" << endl;

	for (int i = 0; i < 6; i++) {
		cout << " >> ";
		cin >> p[i];
		cout << (bool)a.input_priority(p[i]) << endl;
		cout << "input " << p[i] << endl;
	}
	for (int i = 0; i < a.get_size(); i++) {
		cout << a.get_priority() << endl;
	}
	while(1)
	{
		int index;
		int temp[5];
		cout << "Input work_index" << endl;
		cout << ">> ";
		cin >> index; // index < MAX_QUEUE_SIZE

		if (index == -1) break;

		cout << "Input D s_h s_m e_h e_m " << endl;
		for (int i = 0; i < 5; i++) cin >> temp[i];
		cout << "Testing result : " <<(bool)a.input_work_data(index, temp[0], temp[1], temp[2], temp[3], temp[4]) << endl;
	}
	for (int i = 0; i < 5; i++) {
		t = a.work_data_size(i);
		for (int j = 0; j < t; j++) {
			a.work_data_divide(a.get_work_data(i));
		}
	}
}
