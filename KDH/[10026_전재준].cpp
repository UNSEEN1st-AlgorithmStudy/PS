#include <iostream>
#include <queue>
using namespace std;
#define R (3)
#define G (2)
#define B (1)

char Input;
int  Size;
int  Arr[101][101];
int  Arr2[101][101];

int dx[4] {-1, 1, 0, 0};
int dy[4] {0, 0, -1, 1};

queue<pair<int, int>> BFSQueue;

void BFS(int Color);
void BFS2(int Color);

int Output, Output2;

int main()
{
	cin >> Size;
	for (int i = 0 ; i < Size ; i++)
	{
		for (int j = 0 ; j < Size ; j++)
		{
			cin >> Input;
			if (Input == 'R')
			{
				Arr[i][j] = R;
				Arr2[i][j] = G;
			}
			else if (Input == 'G')
			{
				Arr[i][j] = G;
				Arr2[i][j] = G;
			}
			else if (Input == 'B')
			{
				Arr[i][j] = B;
				Arr2[i][j] = B;
			}
		}
	}
	/* ============================== */
	
	for (int n = 0 ; n < Size ; n++)
	{
		for (int m = 0 ; m < Size ; m++)
		{
			if (Arr[n][m])
			{
				BFSQueue.push({n,m});
				int color = Arr[n][m];
				Arr[n][m] = 0;
				BFS(color);
				Output++;
			}
			if (Arr2[n][m])
			{
				BFSQueue.push({n,m});
				int color = Arr2[n][m];
				Arr2[n][m] = 0;
				BFS2(color);
				Output2++;
			}
		}
	}
	cout << Output << " " << Output2 << endl;
}

void BFS(int color)
{
	while (BFSQueue.size())
	{
		int n = BFSQueue.front().first;
		int m = BFSQueue.front().second;
		BFSQueue.pop();
		for (int i=0 ; i < 4 ; i++)
		{
			int next_n = n + dx[i];
			int next_m = m + dy[i];
		
			if ( 
				 next_n >= 0 && next_n < Size && \
				 next_m >= 0 && next_m < Size && \
				 Arr[next_n][next_m] != 0  && \
				 Arr[next_n][next_m] == color
				)
			{
				BFSQueue.push({next_n, next_m});
				Arr[next_n][next_m] = 0;
			}
		}
	}
}


void BFS2(int color)
{
	while (BFSQueue.size())
	{
		int n = BFSQueue.front().first;
		int m = BFSQueue.front().second;
		BFSQueue.pop();
		for (int i=0 ; i < 4 ; i++)
		{
			int next_n = n + dx[i];
			int next_m = m + dy[i];
		
			if ( 
				 next_n >= 0 && next_n < Size && \
				 next_m >= 0 && next_m < Size && \
				 Arr2[next_n][next_m] != 0  && \
				 Arr2[next_n][next_m] == color
				)
			{
				BFSQueue.push({next_n, next_m});
				Arr2[next_n][next_m] = 0;
			}
		}
	}
}

