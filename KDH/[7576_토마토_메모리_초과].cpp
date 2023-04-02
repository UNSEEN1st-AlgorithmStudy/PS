#include <iostream>
using namespace std;
#include <array>
#include <vector>
#include <queue>

long RipenedTomatos = 0;
int Days = -1;
int Empties = 0;
int M, N;
void func( vector<vector<int>>&, queue<pair<int, int>>&, int, int );
void BFS(vector<vector<int>>&, queue<pair<int, int>>& TargetQueue);

int main() {
	cin >> M >> N;
	vector<vector<int> > TomatoBox(N);

	vector<queue<pair<int, int>>> BFSQueues;
	for (int i = 0 ; i < N ; i++)
	{
		TomatoBox[i].reserve(M);
		for (int j = 0 ; j < M ; j++)
		{
			cin >> TomatoBox[i][j];
			if (TomatoBox[i][j] == 1)
			{
				BFSQueues.push_back(queue<pair<int, int>>());
				BFSQueues.back().push(make_pair(i,j));
				RipenedTomatos++;
			} 
			else if (TomatoBox[i][j] == -1)
				Empties++;
		}
	}

	while (BFSQueues.size())
	{
		Days++;
		for (auto it = BFSQueues.begin() ;  it < BFSQueues.end() ; it++)
		{
			if (it->size() == 0)
				BFSQueues.erase(it--);
			else
				BFS(TomatoBox, *it);
		}
	}

	if ( N * M - Empties != RipenedTomatos )
		cout << "-1" << endl;
	else
		cout << Days-1 << endl;
}

void func
(
	vector<vector<int>>& TomatoBox,
	queue<pair<int, int>>& TargetQueue,
	int n,
	int m
)
{
	TargetQueue.push(make_pair(n, m));
	TomatoBox[n][m] = Days + 2;
	RipenedTomatos++;
}

void BFS(vector<vector<int>>& TomatoBox, queue<pair<int, int>>& TargetQueue)
{
	while (TargetQueue.size())
	{
		pair<int, int> Node = TargetQueue.front();
		int n = Node.first;
		int m = Node.second;
		int DayLevel = TomatoBox[n][m];
		if (DayLevel != Days + 1)
			break;
		TargetQueue.pop();
		if ( n > 0 && TomatoBox[n-1][m] == 0)
			func(TomatoBox, TargetQueue, n-1, m);
		if ( n < N-1 && TomatoBox[n+1][m] == 0)
			func(TomatoBox, TargetQueue, n+1, m);
		if ( m > 0 && TomatoBox[n][m-1] == 0)
			func(TomatoBox, TargetQueue, n, m-1);
		if ( m < M-1 && TomatoBox[n][m+1] == 0)
			func(TomatoBox, TargetQueue, n, m+1);
	}
}


