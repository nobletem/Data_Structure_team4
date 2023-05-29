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
	
	// Time_Table Test
	Time_Table a;
	a.input_start_t(9);
	a.input_end_t(20);
	a.input_unit_t(60);
	a.Gen_Time_Table();
	a.input_work(0, 9, 11);
	a.input_work(1, 11, 13);
	a.input_work(2, 10, 20);
	a.input_work(3, 11, 18);
	for (int i = 0; i < COL; i++) {
		for (unsigned int j = 0; j < a.get_row(); j++) {
			cout << int(a.show_table(i, j)) << " ";
		}
		cout << endl;
	}
	

	/*
	// Work Test
	Work a;
	string str[10];
	int p[10];
	int t;
	unsigned int s;

	cout << "Input work name 6 " << endl;
	for (int i = 0; i < 3; i++) { // 일 이름 10개 입력
		cout << ">>  ";
		getline(cin, str[i]);
		cout << a.input_work_n(str[i]) << endl;
		cout << str[i] << endl;
	}
	cout << "number of Work : " << a.get_size() << endl;
	t = a.get_size();
	cout << "Work name list" << endl;
	for (int i = 0; i < t; i++) {
		cout << a.get_work_n() << endl;
	}
	cout << "=========================" << endl;

	for (int i = 0; i < 3; i++) {
		cout << " >> ";
		cin >> p[i];
		cout << a.input_priority(p[i]) << endl;
		cout << "input " << p[i] << endl;
	}
	for (int i = 0; i < a.get_size(); i++) {
		cout << a.get_priority() << endl;
	}
	while (1)
	{
		int index;
		int temp[5];
		cout << "Input work_index" << endl;
		cout << ">> ";
		cin >> index; // index < MAX_QUEUE_SIZE

		if (index == -1) break;

		cout << "Input D s_h s_m e_h e_m " << endl;
		for (int i = 0; i < 5; i++) cin >> temp[i];
		cout << "Testing result : " << a.input_work_data(index, temp[0], temp[1], temp[2], temp[3], temp[4]) << endl;
	}
	for (int i = 0; i < 5; i++) {
		t = a.work_data_size(i);
		s = a.get_work_data(i);
		for (int j = 0; j < t; j++) {
			cout << "Day : " << a.get_day(s) << "s_h : " << a.get_start_t(s) << " e_h : " << a.get_end_t(s) << endl;
		}
	}
	*/

	/*
	* priority queue test
	unsigned int data[10];

	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 100;     // random data
	}

	cout << "origin data : ";
	for (int i = 0; i < 10; i++) cout << data[i] << " ";
	cout << endl;

	heapSort(data, sizeof(data) / sizeof(int));
	cout << "sorted data : ";
	for (int i = 0; i < 10; i++) cout << data[i] << " ";
	cout << endl;

	return 0;
	*/

	/*
	// SortandSelect test
SortandSelect a;
	int data[10];

	for (int i = 0; i < 10; i++) {
		data[i] = rand() % 100;     // random data
	}cout << "origin data : ";
	for (int i = 0; i < 10; i++) cout << data[i] << " ";
	cout << endl;

	a.quickSort(data, 0, 9);
	cout << "sorted data : ";
	for (int i = 0; i < 10; i++) cout << data[i] << " ";
	cout << endl;
	*/
}