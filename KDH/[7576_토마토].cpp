#include <iostream>
#include <queue>
using namespace std;

int M, N;
int TomatoBox[1001][1001];
queue<pair<int,int>> BFSQueue;

int main()
{
	cin >> M >> N;
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < M ; j++)
		{
			cin >> TomatoBox[i][j];
			if (TomatoBox[i][j] == 1)
				BFSQueue.push({i, j});
		}
	}
	int n, m, DayLevel;
	while (BFSQueue.size())
	{
		n = BFSQueue.front().first;
		m = BFSQueue.front().second;
		BFSQueue.pop();
		DayLevel = TomatoBox[n][m] + 1;
		if (n > 0 && TomatoBox[n-1][m] == 0)
		{
			TomatoBox[n-1][m] = DayLevel;
			BFSQueue.push({n-1, m});
		}
		if (n < N - 1 && TomatoBox[n+1][m] == 0)
		{
			TomatoBox[n+1][m] = DayLevel;
			BFSQueue.push({n+1, m});
		}
		if (m > 0 && TomatoBox[n][m-1] == 0)
		{
			TomatoBox[n][m-1] = DayLevel;
			BFSQueue.push({n, m-1});
		}
		if (m < M - 1 && TomatoBox[n][m+1] == 0)
		{
			TomatoBox[n][m+1] = DayLevel;
			BFSQueue.push({n, m+1});
		}
	}

	int DayMax = 0;
	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < M ; j++)
		{
			if (TomatoBox[i][j] == 0) {
				DayMax = 0;
				goto end;
			}
			DayMax = std::max<int>(DayMax, TomatoBox[i][j]);
		}
	}
end :
	cout << DayMax-1 << endl;
}