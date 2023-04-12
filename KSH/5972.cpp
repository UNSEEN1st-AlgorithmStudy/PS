#include <iostream>
#include <queue>
using namespace std;


const int INF = 1e9;
const int NODE_MAX = 50001;
int startNode = 1, finishNode;
int nodeNum, edgeNum;
int a, b, c;
int minCosts[NODE_MAX];

// node cost
vector<pair<int, int>> graph[NODE_MAX];

void Djikstra()
{
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, startNode });
	minCosts[startNode] = 0;

	while (pq.empty() == false)
	{
		int from = pq.top().second;
		int fromCost = -pq.top().first;
		pq.pop();

		for (auto nc : graph[from])
		{
			int to = nc.second;
			int toCost = nc.first + fromCost;

			if (minCosts[to] <= toCost) continue;

			pq.push({ -toCost, to });
			minCosts[to] = toCost;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> nodeNum >> edgeNum;

	for (int i = 0; i < edgeNum; i++)
	{
		cin >> a >> b >> c;

		graph[a].push_back({ c, b });
		graph[b].push_back({ c, a });
	}

	finishNode = nodeNum;

	for (int i = 1; i <= nodeNum; i++)
		minCosts[i] = INF;


	Djikstra();

	cout << minCosts[finishNode] << '\n';
}