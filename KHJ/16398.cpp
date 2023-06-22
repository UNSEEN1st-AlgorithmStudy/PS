#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
constexpr int MAX = 1001;
vector<pair<int, pair<int, int>>> edge;
int parents[MAX];
int V;
long long answer;

void Init()
{
    answer = 0;
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

    x > y ? parents[y] = x : parents[x] = y;
}

int main()
{
    Init();
    cin >> V;
    
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < V; j++)
        {
            int cost;
            cin >> cost;
            if(i > j) edge.push_back({cost,{i,j}});
        }
    }

    sort(edge.begin(), edge.end());
    
    for(int i = 0; i < edge.size(); i++)
    {
        if(FindRoot(edge[i].second.first) == FindRoot(edge[i].second.second))
            continue;

        Merge(edge[i].second.first, edge[i].second.second);
        answer += edge[i].first;
    }

    cout << answer << '\n';
    return 0;
}