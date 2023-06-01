#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001; 
int DP[MAX][3];
int cost[3]; // 비용. 0 빨간색, 1 초록색, 2 파란색 이다.
int N;

// 이전 집 색깔중 최소 비용을 골라 현재 집 색깔을 선택하여 이어나간다. 

int main()
{
    cin >> N; // 집의 수
    DP[0][0] = 0;
    DP[0][1] = 0;
    DP[0][2] = 0;
    
    for(int i = 0; i < N; i++)
    {
        cin >> cost[0] >> cost[1] >> cost[2];
        DP[i+1][0] = min(DP[i][1], DP[i][2]) + cost[0];
        DP[i+1][1] = min(DP[i][0], DP[i][2]) + cost[1];
        DP[i+1][2] = min(DP[i][1], DP[i][0]) + cost[2];
    }
    cout << min(DP[N][0],min(DP[N][1],DP[N][2]));
}