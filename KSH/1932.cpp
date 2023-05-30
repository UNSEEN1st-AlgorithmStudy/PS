#include <iostream>
#include <cmath>
using namespace std;

const int TRI_MAX = 501;
int triSize;
int triangle[TRI_MAX][TRI_MAX];
int dp[TRI_MAX][TRI_MAX];


int getMaxSumOfTriangle()
{
    dp[0][0] = triangle[0][0];

    for (int r = 0; r < triSize - 1; r++)
    {
        for (int c = 0; c <= r; c++)
        {
            dp[r + 1][c]     = max(dp[r + 1][c],     dp[r][c] + triangle[r + 1][c]);
            dp[r + 1][c + 1] = max(dp[r + 1][c + 1], dp[r][c] + triangle[r + 1][c + 1]);
        }
    }
    
    int resultMax = 0;
    for (int c = 0; c < triSize; c++)
    {
        resultMax = max(resultMax, dp[triSize - 1][c]);
    }
    
    return resultMax;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> triSize;
    
    for (int r = 0; r < triSize; r++)
        for (int c = 0; c <= r; c++)
            cin >> triangle[r][c];
    
    cout << getMaxSumOfTriangle() << '\n';
}
