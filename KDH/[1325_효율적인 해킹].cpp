#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct MyLess
{
	bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const { return (p1.second > p2.second); }
};

int	CountTrustComputers(int StartNode, const vector<vector<int> >& Relationships, vector<bool>& Visited);

int main()
{
	int Vertices, Edges;
	MyLess Less;
	cin >> Vertices >>  Edges;

	vector<vector<int> >	TrustRelationships(Vertices + 1);
	vector<pair<int, int> >	NumOfTrusts(Vertices + 1);
	vector<bool>			Visited(Vertices + 1);


	NumOfTrusts.begin()->second = -1;
	for (int i = 0 ; i <= Vertices ; i++)
		NumOfTrusts[i].first = i;

	for (int i = 1 ; i <= Edges ; i++)
	{
		int From, To;
		cin >> To >> From;
		TrustRelationships[From].push_back(To);
	}

	for (int i = 1 ; i <= Vertices ; i++)
	{
		Visited.assign(Vertices + 1, false);
		NumOfTrusts[i].second = CountTrustComputers(i, TrustRelationships, Visited);
	}
	
	sort(NumOfTrusts.begin(), NumOfTrusts.end(), Less);
	
	vector<int> FinalVector;
	FinalVector.push_back(NumOfTrusts.cbegin()->first);
	for (auto it = NumOfTrusts.cbegin() + 1 ; it != NumOfTrusts.cend() - 1; it++)
	{
		if ((it - 1)->second > (it)->second)
			break;
		FinalVector.push_back(it->first);
	}
	sort(FinalVector.begin(), FinalVector.end());
	for (auto Elem : FinalVector)
		cout << Elem << " ";
	cout << endl;
}

int	CountTrustComputers(int StartNode, const vector<vector<int> >& Relationships, vector<bool>& Visited)
{
	int Count = 0;
	
	queue<int> BfsQueue;
	BfsQueue.push(StartNode);
	Visited[StartNode] = true;
	Count++;
	
	while(BfsQueue.size())
	{
		int TargetNode = BfsQueue.front();
		BfsQueue.pop();
		const vector<int>& TrustingComputers = Relationships[TargetNode];
		for (auto elem : TrustingComputers)
		{
			if (Visited[elem] == true)
				continue;
			BfsQueue.push(elem);
			Visited[elem] = true;
			Count++;
		}
		
	}
	return Count;
}