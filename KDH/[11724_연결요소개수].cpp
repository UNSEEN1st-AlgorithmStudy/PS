#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void BFS(set<int>& RemainNodes, const vector<vector<int> >& Connections)
{
	queue<int> BfsQueue;

	int StartNode = *RemainNodes.cbegin();
	BfsQueue.push(StartNode);
	RemainNodes.erase(StartNode);

	while(BfsQueue.size())
	{
		int TargetNode = BfsQueue.front();
		BfsQueue.pop();
		for (const auto it : Connections[TargetNode])
		{
			if (RemainNodes.find(it) == RemainNodes.end()) continue;
			BfsQueue.push(it);
			RemainNodes.erase(it);
		}
	}
}

int main()
{
	int Vertices, Edges;
	int From, To;
	int Elements = 0;

	cin >> Vertices >>  Edges;
	vector<vector<int> > Connections(Vertices + 1);

	for (int i = 0 ; i < Edges ; i++)
	{
		cin >> From >> To;
		Connections[From].push_back(To);
		Connections[To].push_back(From);
	}
	
	set<int> RemainNodes;
	for (int i = 1 ; i <= Vertices ; i++)
		RemainNodes.insert(i);

	while (RemainNodes.size())
	{
		BFS(RemainNodes, Connections);	
		Elements++;
	}
	cout << Elements << endl;
}
