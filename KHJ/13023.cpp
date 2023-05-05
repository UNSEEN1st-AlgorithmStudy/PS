#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
const int MAX_COUNT = 2001;
vector<int> friendship[MAX_COUNT];
bool visit[MAX_COUNT];
int answer = 0;
int N = 0, M = 0;

void DFS(int cur, int friendCount)
{
    visit[cur] = true;
    if(friendCount == 4)
    {
        answer = 1;
        return;
    }
    for(auto nextFriend : friendship[cur])
    {
        if(visit[nextFriend]) continue;
        DFS(nextFriend, friendCount + 1);
    }
    visit[cur] = false;
}

int main()
{
    cin >> N >> M;
    for(int i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }
    for(int i = 0; i < N; i++)
    {
        DFS(i, 0);
    }
    cout << answer << '\n';
    return 0;
}