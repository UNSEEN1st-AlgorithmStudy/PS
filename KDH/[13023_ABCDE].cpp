#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2001;
int Vertices;
int Edges;
int Visited[MAX];

bool backtrackingDfs(const vector<vector<int>>& EdgeList, int StartNode, int depth);

int main()
{
	cin >> Vertices >> Edges;
	vector<vector<int>> EdgeList(Vertices);

	int from, to;
	for (int i =  0 ; i < Edges ; i++)
	{
		cin >> from >> to;
		EdgeList[from].push_back(to);
		EdgeList[to].push_back(from);;
	}

	for (int i = 0 ; i < Vertices ; i++)
	{
		if (backtrackingDfs(EdgeList, i, 0))
		{
			cout<< "1" << endl;
			return 0;
		}
	}

	cout << "0" << endl;
	return 0;
}

bool backtrackingDfs(const vector<vector<int>>& EdgeList, int StartNode, int depth)
{
	const vector<int>& Friends = EdgeList[StartNode];
	Visited[StartNode] = true;
	for (const int next : Friends)
	{
		if (Visited[next] == true)
			continue;
		if (depth == 3) // 다음꺼 무조건 있음.
			return true;
		if (backtrackingDfs(EdgeList, next, depth + 1))
			return true;
	}
	Visited[StartNode] = false;
	return false;
}
