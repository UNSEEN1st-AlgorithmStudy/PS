#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int NODE_MAX = 101;
const int START_NODE = 1;
int nodeNum, edgeNum;
int from, to;
bool visited[NODE_MAX];
vector<int> graph[NODE_MAX];

int CountConnectedNodeByBFS()
{
	queue<int> q;
	q.push(START_NODE);
	visited[START_NODE] = true;

	int count = 0;

	while (q.empty() == false)
	{
		int curNode = q.front();
		q.pop();
		count++;

		int size = graph[curNode].size();
		for (int i = 0; i < size; i++)
		{
			int nextNode = graph[curNode][i];
			if (visited[nextNode] == true) continue;

			visited[nextNode] = true;
			q.push(nextNode);
		}
	}

	return count - 1;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> nodeNum >> edgeNum;

	for (int i = 0; i < edgeNum; i++)
	{
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	cout << CountConnectedNodeByBFS();
}