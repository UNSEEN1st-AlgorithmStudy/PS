#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

struct Path{ int To; int Cows; };
struct PathGreater{ bool operator() (const Path& A, const Path& B) { return (A.Cows > B.Cows);} };

int Vertices, Edges;
int Start, Goal;
vector<Path> AdjList[50001];
priority_queue<	Path, vector<Path>, PathGreater > MinHeap;
vector<int> DistanceArr;

void Djikstra();

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> Vertices >> Edges;
	Start = 1;
	Goal = Vertices;
	DistanceArr.assign(Vertices + 1, INT_MAX);

	for (int i = 0 ; i < Edges ; i++)
	{
		int From, To, Cows;
		cin >> From >> To >> Cows;
		AdjList[From].push_back({To, Cows});
		AdjList[To].push_back({From, Cows});
	}

	Djikstra();
}

void Djikstra()
{
	MinHeap.push({Start, 0});
	DistanceArr[Start] = 0;
	
	while (!MinHeap.empty())
	{
		int CurrNode = MinHeap.top().To;
		int CurrCows = MinHeap.top().Cows;
		MinHeap.pop();
		if (CurrNode == Goal)
		{
			cout << CurrCows << endl;
			return;
		}
		
		const vector<Path>& ConnectedEdges = AdjList[CurrNode];
		for (const Path& p : ConnectedEdges)
		{
			int NextNode = p.To;
			int NextCows = p.Cows;
			if (DistanceArr[NextNode] <= CurrCows + NextCows)
				continue;
			DistanceArr[NextNode] = CurrCows + NextCows;
			MinHeap.push({NextNode, NextCows + CurrCows});
		}
	}
	cout << '0' << endl;
}
