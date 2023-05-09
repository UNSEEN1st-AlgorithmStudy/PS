#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX_SIZE = 500;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };
int N, M, answer;
int graph[MAX_SIZE][MAX_SIZE];
bool visit[MAX_SIZE][MAX_SIZE];

bool IsInside(int ny, int nx)
{
    return (nx >= 0 && ny >= 0 && nx < M && ny < N);
}

void DFS(int a, int b, int depth, int sum)
{
    if (depth == 3)
    {
        answer = max(answer, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int ny = a + dy[i];
        int nx = b + dx[i];
        if (!IsInside(ny, nx)) continue;
        if (visit[ny][nx])continue;
        visit[ny][nx] = true;
        DFS(ny, nx, depth + 1, sum + graph[ny][nx]);
        visit[ny][nx] = false;
    }
}

void ArrowShape1(int a, int b)
{
    int sum = 0;
    sum = graph[a][b] + graph[a][b + 1] + graph[a][b + 2] + graph[a - 1][b + 1];
    answer = max(answer, sum);
}

void ArrowShape2(int a, int b)
{
    int sum = 0;
    sum = graph[a][b] + graph[a][b + 1] + graph[a][b + 2] + graph[a + 1][b + 1];
    answer = max(answer, sum);
}

void ArrowShape3(int a, int b)
{
    int sum = 0;
    sum = graph[a][b] + graph[a + 1][b] + graph[a + 2][b] + graph[a + 1][b + 1];
    answer = max(answer, sum);
}

void ArrowShape4(int a, int b)
{
    int sum = 0;
    sum = graph[a][b] + graph[a - 1][b + 1] + graph[a][b + 1] + graph[a + 1][b + 1];
    answer = max(answer, sum);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    answer = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visit[i][j] = true;
            DFS(i, j, 0, graph[i][j]);
            visit[i][j] = false;
            if (i - 1 >= 0 && j + 2 < M) ArrowShape1(i, j);
            if (j + 2 < M && i + 1 < N) ArrowShape2(i, j);
            if (i + 2 < N && j + 1 < M) ArrowShape3(i, j);
            if (i + 1 < N && i - 1 >= 0 && j + 1 < M) ArrowShape4(i, j);
        }
    }

    cout << answer << '\n';
}