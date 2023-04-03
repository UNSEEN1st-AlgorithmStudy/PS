#include <iostream>
#include <vector>
using namespace std;

const int NODE_MAX = 10000;
int nodeNum, edgeNum, from, to;
vector<int> graph[NODE_MAX + 1];
vector<pair<int, int>> nodeAndCount;
bool visited[NODE_MAX + 1];

void DFS(int startNode, int& count)
{
	visited[startNode] = true;

	for (auto node : graph[startNode])
	{
		if (visited[node] == true) continue;

		visited[node] = true;
		count++;
		DFS(node, count);
	}
}

void ResetVisited()
{
	for (int i = 1; i < nodeNum + 1; i++)
	{
		visited[i] = false;
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
		cin >> to >> from;
		graph[from].push_back(to);
	}

	int maxCount = 0;

	for (int i = 1; i < nodeNum + 1; i++)
	{
		int count = 0;
		DFS(i, count);
		nodeAndCount.push_back({ i, count });

		if (maxCount < count) maxCount = count;

		ResetVisited();
	}

	for (auto node : nodeAndCount)
	{
		if (node.second != maxCount) continue;

		cout << node.first << " ";
	}
}