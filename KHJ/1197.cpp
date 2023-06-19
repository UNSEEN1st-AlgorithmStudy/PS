#include <algorithm>
#include <iostream>
using namespace std;
constexpr int NODE_MAX = 10001;
constexpr int EDGE_MAX = 100001;
pair<int, pair<int, int>> edge[EDGE_MAX];
int parents[NODE_MAX];
int V, E, C, result = 0;

int FindRoot(int x)
{
    if(x == parents[x]) return x;
    return parents[x] = FindRoot(parents[x]);
}

void Merge(int x, int y)
{
    x = FindRoot(x);
    y = FindRoot(y);

    if(x == y) return;
    parents[x] = y;
}

int main()
{
    cin >> V >> E;
    for(int i = 0; i < V; i++)
    {
        parents[i] = i;
    }
    for(int i = 0; i < E; i++)
    {
        int a,b,c;
        cin >> a >> b >> c;
        edge[i] = {c,{a,b}};
    }
    
    sort(edge, edge+E);

    int edgeNum = 0;
    for(int i = 0; i < E; i++)
    {
        if(FindRoot(edge[i].second.first) == FindRoot(edge[i].second.second))
            continue;

        Merge(edge[i].second.first, edge[i].second.second);
        result += edge[i].first;
        
        edgeNum++;
        if(edgeNum == V-1) break;
    }

    cout << result << '\n';
}