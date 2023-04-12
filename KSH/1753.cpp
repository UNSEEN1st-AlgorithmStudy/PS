#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;
const int NODE_MAX = 20001;
int nodeNum, edgeNum, startNode;
int from, to, cost;
int minCostTable[NODE_MAX];

// cost, node
vector<pair<int, int>> graph[NODE_MAX];

void Dijkstra()
{
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, startNode});
    minCostTable[startNode] = 0;
    
    while(pq.empty() == false)
    {
        int fromCost = -pq.top().first;
        int from = pq.top().second;
        pq.pop();
        
        for (auto cn : graph[from])
        {
            int to = cn.second;
            int toCost = fromCost + cn.first;
            if (minCostTable[to] <= toCost) continue;
            
            pq.push({-toCost, to});
            minCostTable[to] = toCost;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodeNum >> edgeNum;
    cin >> startNode;
    
    for (int i = 0; i < edgeNum; i++)
    {
        cin >> from >> to >> cost;
        graph[from].push_back({cost, to});
    }
    
    for (int i = 1; i <= nodeNum; i++)
        minCostTable[i] = INF;
    
    Dijkstra();
    
    for (int i = 1; i <= nodeNum; i++)
    {
        if (minCostTable[i] == INF) cout << "INF" << '\n';
        else                        cout << minCostTable[i] << '\n';
    }
}
