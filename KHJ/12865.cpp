#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_WEIGHT = 100001;
const int MAX_COUNT = 101;
int DP[MAX_COUNT][MAX_WEIGHT];
int W[MAX_COUNT];
int V[MAX_COUNT];
int N, K;

int main()
{
    cin >> N >> K; // 물품의 갯수, 넣을 수 있는 최대 무게

    for(int i = 0; i < N; i++)
    {
        cin >> W[i+1] >> V[i+1];
    }
    
    for(int i = 0; i <= N; i++)
    {
        for(int j = 0; j <= K; j++)
        {
            // ?? max 를 활용한다.
        }
    }
    cout << DP[N][K];
}