#include <algorithm>
#include <iostream>
using namespace std;


const int NODE_MAX = 10001;
const int EDGE_MAX = 100001;
int nodeNum, edgeNum, from, to, cost, resultCost = 0;
pair<int, pair<int, int>> edges[EDGE_MAX];
int parents[NODE_MAX];


int findParent(int x)
{
    if (x == parents[x]) return x;
    return parents[x] = findParent(parents[x]);
}

void merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a > b) parents[a] = parents[b];
    else       parents[b] = parents[a];
}


int main()
{
    cin >> nodeNum >> edgeNum;
    
    for (int i = 1; i <= nodeNum; i++)
        parents[i] = i;
    
    for (int i = 0; i < edgeNum; i++)
    {
        cin >> from >> to >> cost;
        edges[i] = {cost, {from, to}};
    }

    sort(edges, edges + edgeNum);

    for (int i = 0; i < edgeNum; i++)
    {
        if (findParent(edges[i].second.first) == findParent(edges[i].second.second)) continue;

        merge(edges[i].second.first, edges[i].second.second);
        resultCost += edges[i].first;
    }
    
    cout << resultCost << '\n';
    
}
