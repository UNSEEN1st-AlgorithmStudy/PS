#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;
const int MAX_MAP = 125;
const int STEPS[] = {0, 0, 1, -1};

int caseNum = 0, mapNum;
int map[MAX_MAP][MAX_MAP];
int minCosts[MAX_MAP][MAX_MAP];

bool CanGo(int r, int c)
{
	return r >= 0 && c >= 0 && r < mapNum && c < mapNum;
}


void Djikstra()
{
	// cost, row, col
	priority_queue<pair<int, pair<int, int>>> pq;
	pq.push({ -map[0][0], {0, 0}});
	minCosts[0][0] = map[0][0];

	while (pq.empty() == false)
	{
		int fromR = pq.top().second.first;
		int fromC = pq.top().second.second;
		int fromCost = -pq.top().first;
		pq.pop();

		if (fromR == mapNum - 1 && fromC == mapNum - 1) return;

		for (int i = 0; i < 4; i++)
		{
			int toR = fromR + STEPS[i];
			int toC = fromC + STEPS[4 - i - 1];
			int toCost = fromCost + map[toR][toC];

			if (CanGo(toR, toC) == false) continue;
			if (minCosts[toR][toC] <= toCost) continue;

			pq.push({ -toCost, {toR, toC} });
			minCosts[toR][toC] = toCost;
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	while(cin >> mapNum && mapNum != 0)
	{
		caseNum++;

		for (int r = 0; r < mapNum; r++)
		{
			for (int c = 0; c < mapNum; c++)
			{
				cin >> map[r][c];
				minCosts[r][c] = INF;
			}
		}

		Djikstra();

		cout << "Problem " << caseNum << ": " << minCosts[mapNum - 1][mapNum - 1] << '\n';
	}
}