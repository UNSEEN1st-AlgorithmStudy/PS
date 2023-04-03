#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

const int MAP_MAX = 25;
int mapNum;
int map[MAP_MAX + 1][MAP_MAX + 1];
int countHouse;

const int STEP_MAX = 4;
int steps[] = { 0, 0, 1, -1 };
enum { NONE, HOUSE };

vector<int> groups;


bool CanGo(int r, int c)
{
	return r >= 0 && c >= 0 && r < mapNum && c < mapNum;
}

void DFS(int row, int col)
{
	map[row][col] = NONE;
	countHouse++;

	for (int i = 0; i < STEP_MAX; i++)
	{
		int r = row + steps[i];
		int c = col + steps[STEP_MAX - i - 1];

		if (CanGo(r, c) == false || map[r][c] != HOUSE) continue;
		
   		DFS(r, c);
	}
}

void CountGroups()
{
	for (int r = 0; r < mapNum; r++)
	{
		for (int c = 0; c < mapNum; c++)
		{
			if (map[r][c] != HOUSE) continue;

			countHouse = 0;
			DFS(r, c);
			groups.push_back(countHouse);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	scanf("%d", &mapNum);

	for (int r = 0; r < mapNum; r++)
		for (int c = 0; c < mapNum; c++)
			scanf("%1d", &map[r][c]);

	CountGroups();

	sort(groups.begin(), groups.end());

	printf("%d\n", groups.size());
	for (auto count : groups)
		printf("%d\n", count);
}