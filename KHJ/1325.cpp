#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX_N = 10001, MAX_M = 100001;
vector<int> trustPC[MAX_M];
vector<pair<int, int>> hacked;
bool visit[MAX_N];
int N,M, prevCnt = 0,cnt = 0;


void DFS(int node)
{
    visit[node] = true;
    cnt++;
    for(int i = 0; i < trustPC[node].size(); i++)
    {
        int idx = trustPC[node][i];
        if(visit[idx]) continue;
        DFS(idx);
    }
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++) //   입력
    {
        int a,b;
        cin >> a >> b;
        trustPC[b].push_back(a);
    }

    for(int i=1; i <= N; i++) //    DFS 수행
    {
        DFS(i);
        memset(visit, false, sizeof(visit));
        hacked.push_back(make_pair(i,cnt));
        cnt = 0;
    }

    int maxHack = -1;
    for(int i = 0; i <hacked.size(); i++)
    {
        if(hacked[i].second > maxHack) maxHack = hacked[i].second;
    }

    for(int i = 0; i < hacked.size(); i++)
    {
        if(hacked[i].second == maxHack) cout<< hacked[i].first << " ";
    }
    
    return 0;
}