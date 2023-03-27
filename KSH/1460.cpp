#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


const int NODE_MAX = 1001;
int nodeCount, edgeCount, startNode;
int from, to;
bool graph[NODE_MAX][NODE_MAX];
bool visited[NODE_MAX];


void DFS(int startNode)
{
    cout << startNode << " ";
    visited[startNode] = true;
    
    for (int i = 1; i < nodeCount + 1; i++)
    {
        if (graph[startNode][i] == false || visited[i] == true) continue;
        DFS(i);
    }
}

void BFS(int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    
    while(q.empty() == false)
    {
        int curNode = q.front();
        q.pop();
        
        cout << curNode << " ";
        
        for (int i = 1; i < nodeCount + 1; i++)
        {
            if (graph[curNode][i] == false || visited[i] == true) continue;
            
            q.push(i);
            visited[i] = true;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cin >> nodeCount >> edgeCount >> startNode;
    
    for (int i = 0; i < edgeCount; i++)
    {
        cin >> from >> to;
        graph[from][to] = true;
        graph[to][from] = true;
    }
    
    DFS(startNode);
    
    cout << '\n';
    memset(visited, false, sizeof(visited));
    
    BFS(startNode);
}
