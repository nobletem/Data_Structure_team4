#include <iostream>
#include "Function.h"
#include <vector>

using namespace std;

int greedy;
bool function::basic_fuction(Work a)
{
	SortandSelect Sort;
	int num = a.get_size();
	int max, check, able;
	int* p_buf = new int[num];
	int* sp_buf = new int[num];
	int** w_buf = new int*[num];
	int i;

	for (i = 0; i < num; i++) { // 원본 값이 변하지 않도록
		p_buf[i] = a.get_priority();
		a.input_priority(p_buf[i]);
	}

	Sort.quickSort(sp_buf, 0, num - 1);
	max = sp_buf[num - 1]; // 우선순위의 최댓값
	int** index = new int* [max];
	for (i = 0; i < num; i++) {
		w_buf[i] = new int[a.work_data_size(i)];
		index[i] = new int[num];
		for (int j = 0; j < a.work_data_size(i); j++) {
			w_buf[i][j] = a.get_work_data(i);
		}
	}

	for (i = 1; i <= max; i++) { // 우선순위가 i인 일들의 인덱스를 저장
		check = 0;
		for (int j = 0; j < num; j++) {
			if (p_buf[j] == i) {
				index[i][check] = j;
				check++;
			}
		}
	}

	for (i = 1; i <= max; i++) {

	}

	delete[] p_buf;
	delete[] sp_buf;
	for (int i = 0; i < num; i++) {
		delete[] index[i];
	}
	delete[] index;
	for (int i = 0; i < num; i++) {
		delete[] w_buf[i];
	}
	delete[] w_buf;

	return true;
}
