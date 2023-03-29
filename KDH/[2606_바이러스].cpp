#include <iostream>
#include <queue>

bool Arr[101][101];
bool Visited[100];
int BFS(int);

int main()
{
	unsigned int NumOfComputers, NumOfConnections;

	std::cin >> NumOfComputers >> NumOfConnections;
	for (int i = 0 ; i < NumOfConnections ; i++)
	{
		int from, to;
		std::cin >> from >> to;
		Arr[from][to] = true;
		Arr[to][from] = true;
	}

	std::cout << BFS(NumOfComputers) << std::endl;	
	return 0;
}

int BFS(int NumOfComputers)
{
	int Infected = -1;
	std::queue<int>  Queue;
	Queue.push(1);
	Visited[1] = true;

	int TargetNode;
	while (Queue.size())
	{
		TargetNode = Queue.front();
		Queue.pop();
		
		Infected++;
			
		const bool* const ConnectedNodes = Arr[TargetNode];
		for (int i = 1 ; i <= NumOfComputers ; i++)
		{
			if (ConnectedNodes[i] == false || Visited[i] == true)
				continue;
			Queue.push(i);
			Visited[i] = true;
		}
	}
	return Infected;
}
