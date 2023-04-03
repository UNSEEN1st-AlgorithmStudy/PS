#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 2001;
int Vertices;
int Edges;
int Visited[MAX];

bool dfs(const vector<vector<int>>& EdgeList, int StartNode);

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
		bzero(Visited, MAX);
		if (dfs(EdgeList, i) == false)
			continue;
		cout << "1" << endl;
		return 0;
	}

	cout << "0" << endl;
}


bool dfs(const vector<vector<int>>& EdgeList, int StartNode)
{
	int depth = 0;
	stack<pair<int, int>> DFSStack;
	DFSStack.push({StartNode, depth});
	
	while (DFSStack.size())
	{
		int Node = DFSStack.top().first;
		int Depth = DFSStack.top().second;
		if (Depth == 4)
			return true;
		DFSStack.pop();
		if (Visited[Node] == true)
			continue;
		Visited[Node] = true;
		const vector<int>& Friends = EdgeList[Node];
		for (const int a : Friends)
		{
			if (Visited[a] == true)
				continue;
			DFSStack.push({a , Depth + 1});
		}
	}
	return false;
}








