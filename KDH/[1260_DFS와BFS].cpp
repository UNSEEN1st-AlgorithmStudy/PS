#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>

bool visited[1001] {0, };
int edge_array[1001][1001] = {0, };

// stack
void DFS(int start_node, int size);
// queue
void BFS(int start_node, int size);

int main()
{
	int vertices, edges, start_node;
	int from, to;

	std::cin >> vertices >> edges >> start_node;
	
	for (int i = 1; i <= edges ; i++)
	{
		std::cin >> from >> to;
		edge_array[from][to] = 1;
		edge_array[to][from] = 1;
	}

	DFS(start_node, vertices);
	bzero(visited, sizeof(bool) * (vertices + 1));
	BFS(start_node, vertices);
}

void DFS(int start_node, int size)
{
	std::stack<int> dfs_stack;
	dfs_stack.push(start_node);

	int target_node = -1;
	while (dfs_stack.size() > 0)
	{
		target_node = dfs_stack.top();
		dfs_stack.pop();

		if (visited[target_node] == true)
			continue;
		printf("%d ", target_node);
		visited[target_node] = true;

		const int* const connected_nodes = edge_array[target_node];
		for (int i = size ; i >= 1 ; i--)
		{
			if (connected_nodes[i] && !visited[i])
				dfs_stack.push(i);
		}
	}
	printf("\n");
}

void BFS(int start_node, int size)
{
	std::queue<int> bfs_queue;
	bfs_queue.push(start_node);

	int target_node = -1;
	while (bfs_queue.size() > 0)
	{
		target_node = bfs_queue.front();
		bfs_queue.pop();

		if (visited[target_node] == true)
			continue;
		printf("%d ", target_node);
		visited[target_node] = true;

		const int* const connected_nodes = edge_array[target_node];
		for (int i = 1 ; i <= size ; i++)
		{
			if (connected_nodes[i] && !visited[i])
				bfs_queue.push(i);
		}
	}
	printf("\n");
}