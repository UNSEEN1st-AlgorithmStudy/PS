#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int NODE_MAX = 1000;
int nodeNum, edgeNum, from, to;

vector<int> graph[NODE_MAX + 1];
bool visited[NODE_MAX + 1];


void BFS(int startNode)
{
    queue<int> q;
    q.push(startNode);
    visited[startNode] = true;
    
    while(q.empty() == false)
    {
        int from = q.front();
        q.pop();
        
        for(auto to : graph[from])
        {
            if (visited[to] == true) continue;
            
            visited[to] = true;
            q.push(to);
        }
    }
}

int CountConnectedComponents()
{
    int count = 0;
    
    for (int node = 1; node < nodeNum + 1; node++)
    {
        if (visited[node] == true) continue;
        
        BFS(node);
        count++;
    }
    
    return count;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> nodeNum >> edgeNum;
    
    for (int i = 0; i < edgeNum; i++)
    {
        cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    cout << CountConnectedComponents();
}
