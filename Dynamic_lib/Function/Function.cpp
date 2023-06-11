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

//function4 - 개발실패
function4::function4(int workspaceN)
{
	this->workspaceN = workspaceN;
	dist_list.resize(workspaceN, vector<pair<int, int>>(workspaceN, make_pair(0, INFINITY)));
}

bool function4::inputDistance()
{
	//각 장소의 거리 정보를 입력받는 반복문
	for (int i = 0; i < workspaceN; ++i)
	{
		for (int j = i + 1; j < workspaceN; ++j)
		{
			int distance;
			cout << i << "에서 " << j << "까지 거리: ";
			cin >> distance;
			addlist(i, j, distance);
		}
	}
	return true;
}

bool function4::addlist(int u, int v, int w) 
{
	dist_list[u][v] = make_pair(v, w);
	dist_list[v][u] = make_pair(u, w);
	return true;
}

bool function4::dijkstraAlgo(int start)
{
	vector<int> dist(workspaceN, MAX_QUEUE_SIZE);
	dist[start] = 0;
	PriorityQueue pq;
	pq.pqaddqueue(0);
	
	//최단거리 구하는 반복문
	while (!pq.pqempty())
	{
		int current = pq.pqdequeue();
		int currentDist = dist[current];

		if (currentDist < dist[current])
			continue;

		for (int i = 0; i < workspaceN; i++)
		{
			if (dist_list[current][i].first != -1)
			{
				int next = dist_list[current][i].first;
				int edgeWeight = dist_list[current][i].second;
				int nextDist = currentDist + edgeWeight;

				if (nextDist < dist[next])
				{
					dist[next] = nextDist;
					pq.pqaddqueue(nextDist);
				}
			}
		}
	}

	for (int i = 0; i < workspaceN; i++)
	{
		cout << "장소" << start << "에서 장소 " << i << "까지의 최단 거리: ";
		if (dist[i] == MAX_QUEUE_SIZE)
			cout << "도달할 수 없음" << endl;
		else
			cout << dist[i] << endl;
	}

	return true;
}

//work 클래스를 이용한 main 함수 부분((실질적으로 실행되어야함
int main()
{
	Work work;
	string workName[MAX_Work_Name];
	//string workspace[MAX_Work_Name];
	int workspaceN = 0;
	unsigned int d, s_h, s_m, e_h, e_m;

	for (int i = 0; i < MAX_Work_Name; i++) {
		cout << "일의 이름을 입력하세요(q를 입력하면 종료됩니다.): ";
		cin >> workName[i];

		if (workName[i] == "q")
		{
			break;
		}
		else
		{
			work.input_work_n(workName[i]);
			cout << "날짜를 입력해주세요(예시:월~금 = 0~6): ";
			cin >> d;

			cout << "시작 시간과 분을 입력해주세요(예시: 3시 30분 > 15 30): ";
			cin >> s_h >> s_m;
			
			cout << "끝 시간과 분을 입력해주세요(예시: 4시 45분 > 16 45): ";
			cin >> e_h >> e_m;

			work.input_work_data(i, d, s_h, s_m, e_h, e_m);
			workspaceN++;
		}
	}

	int workSize = work.get_size();

	for (int i = 0; i < workSize; i++)
	{
		if (d == work.get_work_data(i))
		{
			string workName = work.get_work_n();
			unsigned int workData = work.get_work_data(i);

			cout << "일 이름: " << workName << endl;
			cout << endl;
		}
	}

	cout << "장소의 수: " << workspaceN << endl;

	if(d==0||d==1||d==2||d==3||d==4||d==5||d==6)
	{
		if (d >= 0 && d <= 6)
		{
			function4 dijkstra(workspaceN);
			dijkstra.inputDistance();

			int startPlace;
			cout << "시작 장소: ";
			cin >> startPlace;

			dijkstra.dijkstraAlgo(startPlace);
		}
	}
}
