#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
const int BOX_SIZE = 1001;

struct tomato
{
    int y, x;
};
queue<tomato> q;

int dx[4] = { 1, 0, -1, 0};
int dy[4] = { 0, 1, 0, -1};

int V, H, resultDay = 0;
int graph[BOX_SIZE][BOX_SIZE];

bool IsInside(int ny, int nx)
{
    return (0 <= nx && 0 <= ny && nx < H && ny < V);
}

void BFS()
{
    while (!q.empty())
    {
        int y = q.front().y;
        int x = q.front().x;
        q.pop();
        
        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (IsInside(ny,nx) == 1 && graph[ny][nx] == 0)
            {
                graph[ny][nx] = graph[y][x] + 1;
                q.push({ ny, nx });
            }
        }
    }
}

int main()
{
    scanf("%d %d", &H, &V);
    for(int i = 0; i < V; i++)
    {
        for(int j = 0; j < H; j++)
        {
            scanf("%d", &graph[i][j]);
            if(graph[i][j] == 1) q.push({i,j});
        }
    }

    BFS();

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < H; j++)
        {
            if (graph[i][j] == 0)
            { 
                printf("-1\n");
                return 0;
            }
            if (resultDay < graph[i][j])
            {
                resultDay = graph[i][j];
            }
        }
    }
    
    printf("%d\n", resultDay-1);
    
    return 0;
}
