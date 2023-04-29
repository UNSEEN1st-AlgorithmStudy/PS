#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAP_SIZE = 25;
vector<int> totalComplex; 

int dx[] = { 1, 0, -1, 0};
int dy[] = { 0, 1, 0, -1};

int M, currentComplex = 0;

bool visit[MAP_SIZE][MAP_SIZE] = {0,};
int graph[MAP_SIZE][MAP_SIZE];

bool IsValid(int ny, int nx)
{
    return (nx >= 0 && ny >= 0 && nx < M && ny < M);
}

void DFS(int y, int x)
{
    visit[y][x] = true;
    totalComplex.at(currentComplex)++;
    for(int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(IsValid(ny,nx) && !visit[ny][nx] &&graph[ny][nx] == 1)
        {
            DFS(ny, nx);
        }
    }
}

int main()
{
    scanf("%d", &M);
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }
    
    for(int i = 0; i < M; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(graph[i][j] != 1 || visit[i][j])
            {
                continue;
            }
            totalComplex.push_back(0);
            DFS(i,j);
            currentComplex++;
        }
    }
    sort(totalComplex.begin(), totalComplex.end());
    printf("%d\n",totalComplex.size());
    for(auto idx : totalComplex) printf("%d\n", idx);
    return 0;
}