#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;

const int XY_MAX = 1000;
int xMax, yMax;
int box[XY_MAX][XY_MAX];

const int STEP_MAX = 4;
int xSteps[] = { 0, 0, 1, -1 };
int ySteps[] = { 1, -1, 0, 0 };

enum { NONE = -1, UNRIPE = 0, RIPE = 1 };

int unripeTomatoCount = 0;
int totalDays = 0;

queue<pair<pair<int, int>, int>> q;


bool IsValidStep(int x, int y)
{
	return x >= 0 && y >= 0 && x < xMax && y < yMax && box[x][y] == UNRIPE;
}

void BFS()
{
	while (q.empty() == false)
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int day = q.front().second;
		q.pop();
		totalDays = day;
		
		for (int i = 0; i < STEP_MAX; i++)
		{
			int nextX = xSteps[i] + x;
			int nextY = ySteps[i] + y;

			if (IsValidStep(nextX, nextY) == false) continue;
			
			q.push({ { nextX, nextY }, day + 1 });
			box[nextX][nextY] = RIPE;
			unripeTomatoCount--;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> xMax >> yMax;

	for (int y = 0; y < yMax; y++)
	{
		for (int x = 0; x < xMax; x++)
		{
			cin >> box[x][y];
			if (box[x][y] == UNRIPE) unripeTomatoCount++;
			if (box[x][y] == RIPE)   q.push({ {x, y}, 0 });
		}
	}

	BFS();

	if (unripeTomatoCount != 0) cout << -1;
	else                        cout << totalDays;
}