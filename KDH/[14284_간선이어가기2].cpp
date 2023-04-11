#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Edge
{
	int To;
	int Weight;
};
struct GreaterEdge
{
	bool operator()(const Edge& A, const Edge& B) { return (A.Weight > B.Weight); }
};

int Vertices, Edges;
int Start, End;
vector<Edge> AdjList[5001];
bool Visited[5001];
priority_queue<Edge, vector<Edge>, GreaterEdge> MinHeap;
void Dijkstra(void);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> Vertices >> Edges;
	int From, To, Weight;
	for (int i = 0 ; i < Edges ; i++)
	{
		cin >> From >> To >> Weight;
		AdjList[From].push_back({To, Weight});
		AdjList[To].push_back({From, Weight});
	}
	cin >> Start >> End;
	Dijkstra();
}

void Dijkstra(void)
{
	MinHeap.push({Start, 0});
	while (MinHeap.size())
	{
		Edge e = MinHeap.top();
		MinHeap.pop();
		if (e.To == End)
		{
			cout << e.Weight << endl;
			return ;
		}
		if (Visited[e.To] == true)
			continue;
		Visited[e.To] = true;

		for(const Edge& Next : AdjList[e.To])
		{
			if (Visited[Next.To] == false)
			{
				MinHeap.push({Next.To, e.Weight + Next.Weight});
			}
		}
	}
}

