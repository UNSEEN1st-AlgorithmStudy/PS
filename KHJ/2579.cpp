#include <iostream>
using namespace std;
const int MAX_SIZE = 301;
int DP[MAX_SIZE];
int arr[MAX_SIZE];
int N;

int Max(int A, int B) { if (A > B) return A; return B;}

int main()
{
    cin >> N;
    for(int i = 1; i <= N; i++)
    {
        cin >> arr[i];
    }
    
    DP[1] = arr[1];
    DP[2] = arr[1] + arr[2];
    DP[3] = Max(arr[1], arr[2]) + arr[3];

    for(int i = 4; i <= N; i++)
    {
        DP[i] = Max(DP[i-3] + arr[i-1], DP[i-2]) + arr[i];
    }
    cout << DP[N] << '\n';
}