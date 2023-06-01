#include <iostream>
using namespace std;


const int MODULAR = 10007;
const int WIDTH_MAX = 1000;
int width;
int dp[WIDTH_MAX];


int getNumberOfWaysToFillRectangle()
{
    dp[0] = 1;
    dp[1] = 2;
    
    for (int i = 2; i < width; i++)
    {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MODULAR;
    }
    
    return dp[width - 1];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> width;
    
    cout << getNumberOfWaysToFillRectangle() << '\n';
}
