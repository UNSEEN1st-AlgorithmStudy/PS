#include <iostream>
#include <cstring>
using namespace std;
const int ROW_SIZE = 101;
int N = 0, G = 0;
int row[ROW_SIZE];
int result[ROW_SIZE];
bool visit[ROW_SIZE] = {false};

void DFS(int cur, int start)
{
    if(visit[cur])
    {
        if(cur == start) result[G++] = start; // 결과 배열에는 작은 수부터 입력 된다. 
    }
    else
    {
        visit[cur] = true;
        DFS(row[cur], start);
    }
}

int main()
{
    cin >> N; // 최대 정수 입력
    for(int i = 1; i <= N; i++) // 배열에 주어진 번호 입력
    {
        cin >> row[i];
    }
    
    for(int i = 1; i <= N; i++) // 모든 인덱스 DFS 탐색
    {
        memset(visit, false, sizeof(visit));
        DFS(i, i);
    }
    
    cout << G << '\n';
    
    for(int i = 0; i < G; i++)
    {
        cout << result[i] << '\n';
    }
    
    return 0;
}