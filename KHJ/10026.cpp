#include <iostream>
#include <queue>
#include <cstring>
using namespace std;
const int MAP_SIZE = 101;

struct color
{
    int y, x;
};

int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};

int N, totalArea_0, totalArea_1 = 0;

bool visit[MAP_SIZE][MAP_SIZE];
char graph[MAP_SIZE][MAP_SIZE];

queue<color> q;

bool IsValid(int ny, int nx)
{
    return (nx >= 0 && ny >= 0 && nx < N && ny < N);
}

void BFS(int a, int b)
{
    q.push({a,b});
    visit[a][b] = true;

    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();

        for(int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(IsValid(ny,nx) && !visit[ny][nx] && graph[ny][nx] == graph[y][x])
            {
                visit[ny][nx] = true;
                q.push({ny,nx});
            }
        }
    }
}

int main()
{
    //  입력
    cin >> N;
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(!visit[i][j])
            {
                BFS(i,j);
                totalArea_0++;
            }
        }
    }

    memset(visit, false, sizeof(visit));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (graph[i][j] == 'G') graph[i][j] = 'R';
        }
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visit[i][j])
            {
                BFS(i, j);
                totalArea_1++;
            }
        }
    }
    cout << totalArea_0 << " " << totalArea_1 << '\n';
    return 0;
}