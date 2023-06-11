// 15:41
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, K;
int cnt;
int resultTime;
vector<bool> visited(100'001);
queue<pair<int, int>> q; // 위치, time
void BFS(int now)
{
    q.push(make_pair(now, 0));
    while (!q.empty())
    {
        int nowIndex = q.front().first;
        int nowTime = q.front().second;
        q.pop();
        visited[nowIndex] = true;
        if (nowIndex == K && resultTime == nowTime && resultTime)
        {
            ++cnt;
        }
        if (nowIndex == K && !resultTime)
        {
            resultTime = nowTime;
            ++cnt;
        }
        
        if (nowIndex - 1 >= 0 && visited[nowIndex - 1] == false)
        {
            q.push(make_pair(nowIndex - 1, nowTime + 1));
        }
        if (nowIndex + 1 <= 100'000 && visited[nowIndex + 1] == false)
        {
            q.push(make_pair(nowIndex + 1, nowTime + 1));
        }
        if (nowIndex * 2 <= 100'000 && visited[nowIndex * 2] == false)
        {
            q.push(make_pair(nowIndex * 2, nowTime + 1));
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N >> K;
    BFS(N);
    cout << resultTime << '\n';
    cout << cnt;
}
