#include "iostream"
#include "vector"
using namespace std;

const int MAX_NUM = 1001;
vector<int> connect[MAX_NUM];
bool visit[MAX_NUM];
int N,M;

void DFS(int node)
{
    visit[node] = true;
    for(int i = 0; i < connect[node].size(); i++)
    {
        int idx = connect[node][i];
        if(visit[idx]) continue;
        DFS(idx);
    }
}

int main()
{
    int u, v;
    int count = 0;
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> u >> v;
        connect[u].push_back(v);
        connect[v].push_back(u);
    }

    for(int i = 1; i<= N; i++)
    {
        if(!visit[i])
        {
            count++;
            DFS(i);
        }
    }
    cout << count;
    return 0;
}