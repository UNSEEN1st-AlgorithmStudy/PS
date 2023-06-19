#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool visit[10001];
vector<pair<int, int>> node[10001];         // 목표 간선, 비용

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // INPUT
    int n, m, from, target, cost;
    long long answer = 0;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> from >> target >> cost;
        node[from].push_back({ target,cost });
        node[target].push_back({ from,cost });
    }

    priority_queue<pair<int, int>> PQ; // 현재 비용, 현재 지점
    PQ.push({ 0, 1 });

    // 계산
    while (!PQ.empty())
    {
        int curPos = PQ.top().second;
        int curCost = -PQ.top().first;
        PQ.pop();

        if (visit[curPos]) continue;

        visit[curPos] = true;
        answer += curCost;

        for (int i = 0; i < node[curPos].size(); i++)
        {
            int nextNode = node[curPos][i].first;
            int nextCost = -node[curPos][i].second;

            PQ.push({ nextCost, nextNode });
        }
    }
    cout << answer;
}