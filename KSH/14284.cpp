#include <iostream>
#include <queue>
using namespace std;

const int INF = 1e9;
const int NODE_MAX = 5001;
int nodeNum, edgeNum;
int a, b, c;
int startNode, finishNode, minCost;
int costTable[NODE_MAX];

// cost, node
vector<pair<int, int>> graph[NODE_MAX];

void Dijkstra()
{
    // cost, node
    priority_queue<pair<int, int>> pq;
    
    pq.push({0, startNode});
    costTable[startNode] = 0;
    
    while(pq.empty() == false)
    {
        int from = pq.top().second;
        int fromCost = -pq.top().first;
        pq.pop();
        
        if (from == finishNode) return;
        
        for (auto cn : graph[from])
        {
            int to = cn.second;
            int toCost = fromCost + cn.first;
            
            if (costTable[to] <= toCost) continue;
            
            pq.push({-toCost, to});
            costTable[to] = toCost;
        }
        
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodeNum >> edgeNum;
    for (int i = 0; i < edgeNum; i++)
    {
        cin >> a >> b >> c;
        
        graph[a].push_back({c, b});
        graph[b].push_back({c, a});
    }
    cin >> startNode >> finishNode;
    
    for (int i = 1; i <= nodeNum; i++)
        costTable[i] = INF;
        
    Dijkstra();
    
    cout << costTable[finishNode] << '\n';
}
