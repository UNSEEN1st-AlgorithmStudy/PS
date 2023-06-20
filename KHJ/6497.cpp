#include <algorithm>
#include <iostream>
using namespace std;
constexpr int MAX = 200012;
pair<int, pair<int, int>> edge[MAX];
int parents[MAX];
int V, E, total, result = 0;

void Init()
{
    total = result = 0;
    for(int i = 0; i < MAX; i++) parents[i] = i;
}

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
    while (true)
    {
        Init();
        cin >> V >> E;
        if(V == 0 && E == 0) break;
        
        for(int i = 0; i < E; i++)
        {
            int a,b,c;
            cin >> a >> b >> c;
            edge[i] = {c,{a,b}};
            total += c;
        }
    
        sort(edge, edge+E);
        

        for(int i = 0; i < E; i++)
        {
            if(FindRoot(edge[i].second.first) == FindRoot(edge[i].second.second))
                continue;

            Merge(edge[i].second.first, edge[i].second.second);
            result += edge[i].first;
        
        }

        cout << total - result << '\n';
    }
    
    return 0;
}