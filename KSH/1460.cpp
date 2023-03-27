#include <iostream>
#include <cstring>
#include <queue>
using namespace std;


int nodeCount, edgeCount, startNode;
int a, b;
bool graph[1001][1001];
bool visited[1001];


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
        cin >> a >> b;
        graph[a][b] = true;
        graph[b][a] = true;
    }
    
    DFS(startNode);
    
    cout << endl;
    memset(visited, false, 1001);
    
    BFS(startNode);
}
