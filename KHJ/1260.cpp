#include <queue>
#include <iostream>
using namespace std;

bool path[1001][1001], visit[1001]; //  인접한 노드, 방문 여부
queue<int> q;
int nodeCount, wayCount, startNode; //  정점 개수, 간선 개수, 시작 정점

void ResetVisit() //    방문 초기화
{
    for(int ix = 0; ix <= nodeCount; ix++)
    {
        visit[ix] = false;
    }
}

void DFS(int startNode) //  깊이 탐색
{
    visit[startNode] = true;
    cout << startNode << " ";

    for(int ix = 1; ix <= nodeCount; ix++)
    {
        if(startNode != ix && path[startNode][ix]&& !visit[ix])
        {
            DFS(ix);
        }
    }
}

void BFS(int startNode) // 넓이 탐색
{
    q.push(startNode);
    visit[startNode] = true;

    while (!q.empty())
    {
        int nextNode = q.front();
        q.pop();
        cout << nextNode << " ";
        for(int ix = 1; ix <= nodeCount; ix++)
        {
            if(!visit[ix] && nextNode != ix && path[nextNode][ix])
            {
                q.push(ix);
                visit[ix] = true;
            }
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
        path[a][b] = path[b][a] = true;
    }
    ResetVisit(); // 방문 노드 초기화
    DFS(startNode);
    cout << '\n';
    ResetVisit();
    BFS(startNode);
    cout << '\n';
    
    return 0;
}