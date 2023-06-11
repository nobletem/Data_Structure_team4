#include <iostream>
#include "Data_Struct.h"
#include "Time_Table.h"
#include "Work.h"
#include <math.h>
#include <Windows.h>

using namespace std;

int main()
{
	Time_Table time_table;
	// Work Test
	Work work;
	string* str;
	int p[10];
	double a = 0, b = 0, c = 0;
	int size;

	cout << "============== 시간표 생성 ==============" << endl << endl;
	cout << "시간표 틀을 생성합니다." << endl << endl;
	cout << "시간표의 시작 시간을 입력하세요.(0 ~ 24시) >> ";
	while (1) {
		cin >> a;
		if (a > 24 || a < 0) {
			cout << "다시 입력해주세요 >> " ;
			continue;
		}
		break;
	}
	time_table.input_start_t(a);

	cout << endl <<"시간표의 종료 시간을 입력하세요.(0 ~ 24시) >> ";
	while(1) {
		//cin.ignore();
		cin >> b;
		if (b > 24 || b < 0 || a>=b) {
			cout << "다시 입력해주세요 >> ";
			continue;
		}
		break;
	}
	time_table.input_end_t(b);

	cout << endl << "시간표 사이의 간격을 입력해주세요(1 ~ 60분). >> ";
	while (1) {
		cin.ignore();
		cin >> c;
		if (c > 60 || c < 1) {
			cout << "다시 입력해주세요 >> ";
			continue;
		}
		break;
	}
	time_table.input_unit_t(c);

	time_table.Gen_Time_Table();
	system("cls");

	cout << fixed;
	cout.precision(1);

	cout << "============== 시간표가 생성되었습니다. ============== " << endl;
	for (unsigned int j = 0; j < time_table.get_row(); j++) {
		cout << a + (j * (c / 60)) << " - " << a + ((j + 1)*(c / 60)) << "   \t";
		for (int i = 0; i < COL; i++) {
			cout << int(time_table.show_table(i, j)) << " ";
		}
		cout << endl;
	}
	cout << endl;

	while (1)
	{
		cout << "시간표에 넣고자 하는 일의 개수를 입력해주세요 >> ";
		cin.ignore();
		cin >> size;
		if (size > 50) {
			cout << "일의 개수는 50개를 넘을 수 없습니다. 다시 입력해 주세요. " << endl;
			continue;
		}
		str = new string[size];

		for (int i = 0; i < size; i++) {
			int temp[5] = { 0 };
			string nul;
			int data;
			cout << "일의 이름을 입력해주세요 >> " ;
			cin.ignore();
			getline(cin, str[i]);
			if (str[i] == nul) { cout << "다시 입력해주세요" << endl; continue; }
			if (work.input_work_n(str[i]))cout << "Success" << endl;
			else { continue; }

			cout << str[i] << "의 요일을 입력해주세요(0 ~ 7) >> ";
			cin >> temp[0];
			cout << str[i] << "의 시작 시간을 입력해주세요 >> ";
			cin.ignore();
			cin >> temp[1];
			cout << str[i] << "의 시작 분을 입력해주세요 >> ";
			cin.ignore();
			cin >> temp[2];
			cout << str[i] << "의 끝 시간을 입력해주세요 >> ";
			cin.ignore();
			cin >> temp[3];
			cout << str[i] << "의 끝 분을 입력해주세요 >> ";
			cin.ignore();
			cin >> temp[4];


			if (work.input_work_data(i, temp[0], temp[1], temp[2], temp[3], temp[4])) cout << "Success" << endl;
			data = work.get_data(i);
			if (time_table.input_work(work.get_day(data), work.get_start_t(data), work.get_end_t(data))) cout << "Success" << endl;
		}

		cout << "============== 시간표가 생성되었습니다. ============== " << endl;
		for (unsigned int j = 0; j < time_table.get_row(); j++) {
			cout << a + (j * (c / 60)) << " - " << a + ((j + 1) * (c / 60)) << "   \t";
			for (int i = 0; i < COL; i++) {
				cout << int(time_table.show_table(i, j)) << " ";
			}
			cout << endl;
		}
		cout << endl;
		break;
	}
	delete[] str;
}