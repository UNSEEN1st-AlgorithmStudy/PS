#include <queue>
#include <iostream>
using namespace std;

const int MAX_VALUE = 10001;
int edge[MAX_VALUE][MAX_VALUE]; //  인접한 노드
bool visit[MAX_VALUE]; //   방문 여부
queue<int> q;
int nodeCount, wayCount, startNode; //  정점 개수, 간선 개수, 시작 정점

void ResetVisit() //    방문 초기화
{
    for(int ix = 1; ix <= nodeCount; ix++)
    {
        visit[ix] = 0;
    }
}

void DFS(int startNode) //  깊이 탐색
{
    visit[startNode] = true;
    cout << startNode << " ";

    for(int ix = 1; ix <= nodeCount; ix++)
    {
        if(edge[startNode][ix] == 1 && visit[ix] == 0)
        {
            DFS(ix);
        }
    }
}

void BFS(int startNode) // 넓이 탐색
{
    q.push(startNode);
    visit[startNode] = true;
    cout << startNode << " ";
    
    while (!q.empty())
    {
        startNode = q.front();
        q.pop();

        for(int ix = 1; ix <= nodeCount; ix++)
        {
            if(visit[ix]) continue;
            q.push(ix);
            visit[ix] = true;
            cout << ix << " ";
        }
    }
}

int main()
{
    cin >> nodeCount >> wayCount >> startNode;
    for(int i = 0; i < wayCount; i++)
    {
        int a, b;
        cin >> a >> b; // 입력으로 주어진 간선은 양방향이니 양쪽 다 등록한다.
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    ResetVisit(); // 방문 노드 초기화
    DFS(startNode);

    cout << '\n';

    ResetVisit();
    BFS(startNode);
    
    return 0;
}