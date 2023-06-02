#include <iostream>
using namespace std;


enum Color { RED, BLUE, GREEN, PAINT_COUNT_MAX };
const int HOUSE_COUNT_MAX = 1001;
int houseCount;
int costs[HOUSE_COUNT_MAX][PAINT_COUNT_MAX];
int dp[HOUSE_COUNT_MAX][PAINT_COUNT_MAX];


int getMinCostToPaintAllHouses()
{
    dp[0][RED] = dp[0][BLUE] = dp[0][GREEN] = 0;
    
    for (int i = 1; i <= houseCount; i++)
    {
        dp[i][RED]   = min(dp[i - 1][BLUE], dp[i - 1][GREEN]) + costs[i][RED];
        dp[i][BLUE]  = min(dp[i - 1][RED],  dp[i - 1][GREEN]) + costs[i][BLUE];
        dp[i][GREEN] = min(dp[i - 1][RED],  dp[i - 1][BLUE])  + costs[i][GREEN];
    }
    
    return min(dp[houseCount][RED], min(dp[houseCount][BLUE], dp[houseCount][GREEN]));
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> houseCount;
    
    for (int i = 1; i <= houseCount; i++)
        for (int j = 0; j < PAINT_COUNT_MAX; j++)
            cin >> costs[i][j];
    
    cout << getMinCostToPaintAllHouses() << '\n';
}
