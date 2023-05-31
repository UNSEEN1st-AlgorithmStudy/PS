#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_SIZE = 501;
int DP[MAX_SIZE][MAX_SIZE];
int N, A = 0;

int main()
{
    // Input Data
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j <= i; j++)
        {
            cin >> DP[i][j];
        }
    }

    for(int i = N-1; i >= 1; i--)
    {
        for(int j = 0; j < i; j++)
        {
            DP[i-1][j] += max(DP[i][j], DP[i][j+1]);
        }
    }

    cout << DP[0][0] << '\n';
    return 0;
}