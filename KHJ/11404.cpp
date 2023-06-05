#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int INF = INT32_MAX;
int road[MAX][MAX] = { 0, };
int N, M;
int main()
{
    cin >> N >> M;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            road[i][j] = INF;
        }
    }

    for(int i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if(road[a][b] > c) road[a][b] = c;
    }
    
    for(int via = 1; via <= N; via++)
    {
        for(int from = 1; from <= N; from++)
        {
            for(int to = 1; to <= N; to++)
            {
                if(road[from][via] != INF && road[via][to] != INF)
                road[from][to] = min(road[from][to], road[from][via] + road[via][to]);
            }
        }
    }

    for(int i = 1; i <= N; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if( i == j || road[i][j] == INF) cout << 0 << " ";
            else  cout << road[i][j] << " ";
        }
        cout << '\n';
    }
    return 0;
}