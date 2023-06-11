#ifndef FUNCTION
#define FUNCTION

#include "Work.h"

class function
{
public:
	bool basic_fuction(Work a);
};

//function4
class function4
{
private:
	int workspaceN; 
	vector<vector<pair<int, int>>> dist_list;
public:
	function4(int workspaceN);
	bool inputDistance();
	bool addlist(int u, int v, int w);
	//bool dijkstra_algo(int start, int workspaceN);
	bool dijkstraAlgo(int start);
};
#endif

