#include<iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#define INF (2147483647)
using namespace std;

vector<vector<pair<int, int>>> AdjList;

priority_queue<
	pair<int,int>,
	vector<pair<int,int> >,
	greater<pair<int,int> >
>MinHeap;

vector<int> Dist;

void Dijkstra(int StartNode);

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int Vertices,Edges,Start;
	int From, To, Weight;
	
	cin >> Vertices >> Edges >> Start;
	
	AdjList.reserve(Vertices + 1);
	Dist.assign(Vertices + 1, INF);

	for(int i = 0 ; i < Edges ; i++)
	{
		cin >> From >> To >> Weight;
		AdjList[From].push_back({To,Weight});
	}
	
	Dijkstra(Start);
	
	for(int i = 1 ; i <= Vertices ; i++)
		(Dist[i] == INF) ? (cout << "INF" << endl) : (cout << Dist[i] << endl);
	
	return 0;
}

void Dijkstra(int StartNode)
{
	Dist[StartNode] = 0;
	MinHeap.push({0,StartNode});
	
	while(MinHeap.size())
	{
		int Distance = MinHeap.top().first;
		int Node = MinHeap.top().second;
		MinHeap.pop();
		
		for (const pair<int, int>& X : AdjList[Node])
		{
			int V = X.first;
			int W = X.second;
			if(Distance+W<Dist[V])
			{
				Dist[V] = Distance + W;
				MinHeap.push({Distance + W,V});
			}
		}
	}
}