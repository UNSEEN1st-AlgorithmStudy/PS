#include <algorithm>
#include <iostream>
using namespace std;


const int PLANET_MAX = 1001;
pair<int, pair<int, int>> edges[PLANET_MAX * PLANET_MAX];
int parents[PLANET_MAX];
int planetNum, cost;
long long resultCost = 0;


int findParent(int x)
{
    if (x == parents[x]) return x;
    return parents[x] = findParent(parents[x]);
}

void merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a == b) return;
    
    parents[a] = b;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> planetNum;

    for (int i = 1; i <= planetNum; i++)
        parents[i] = i;

    int edgeNum = 0;
    for (int i = 1; i <= planetNum; i++)
    {   for (int j = 1; j <= planetNum; j++)
        {
            cin >> cost;
            if (j < i) continue;
        
            edges[edgeNum++] = { cost, {i, j} };
        }
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
