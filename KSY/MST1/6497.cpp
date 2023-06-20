// 18:12 시작
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct DisjointSet
{
    vector<int> parent;
    DisjointSet(int N) : parent(N)
    {
        for (int i = 0; i < N; ++i)
        {
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u == parent[u])
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }
    void merge(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v)
            return;
        parent[u] = v;
    }
    bool isSameTree(int u, int v)
    {
        u = find(u);
        v = find(v);
        if (u == v) return true;
        else return false;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    while(true)
    {
        int M, N;
        cin >> M >> N;
        if(M==0 && N==0) break;
        DisjointSet DJ(M);                  // 부모를 저장할 DisjointSet
        vector<pair<int, pair<int, int>>> Vs; // z, x, y
        long long sumCost = 0;
        for (int i = 0; i < N; ++i)
        {
            int x, y, z;
            cin >> x >> y >> z;
            Vs.push_back({z, {x, y}});
            sumCost += z;
        }
        sort(Vs.begin(), Vs.end());

        int mergeCount = 0;
        for (int i = 0; i < Vs.size(); ++i)
        {
            int start = Vs[i].second.first;
            int end = Vs[i].second.second;
            int cost = Vs[i].first;
            if (!DJ.isSameTree(start, end))
            { // 만약 같은 트리가 아니라면 합치기
                DJ.merge(start, end);
                sumCost -= cost;
                ++mergeCount;
            }
            if (mergeCount == M - 1) break;
        }
        cout << sumCost <<'\n';
    }
}
