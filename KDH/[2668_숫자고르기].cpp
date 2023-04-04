#include <iostream>
#include <vector>
#include <stack>
#include <cstring>
using namespace std;

const int SIZEMAX = 101;

int  Arr[SIZEMAX];
bool Visited[SIZEMAX];
int  N;

vector<int> Res;
void DFS(int StartIdx)
{
	if (StartIdx == Arr[StartIdx])
	{
		Res.push_back(StartIdx);
		return ;
	}
	stack<int> DFSStack;
	bzero(Visited, SIZEMAX);
	
	DFSStack.push(StartIdx);
	while (DFSStack.size())
	{
		int a = DFSStack.top();
		DFSStack.pop();
		if (Visited[a] == true)
		{
			if (a == StartIdx)
			{
				Res.push_back(a);
				return;
			}
			continue;
		}
		Visited[a] = true;
		DFSStack.push(Arr[a]);
	}
}
	
int main()
{
	cin >> N;
	for (int i = 1 ; i <= N ; i++)
		cin >> Arr[i];
	
	for (int i = 1 ; i <= N ; i++)
		DFS(i);

	cout << Res.size() << endl;
	for (const int a : Res)
		cout << a << endl;
}






