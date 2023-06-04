#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int score[3];
int N;
pair<int,int> DP[MAX][3];
int main()
{
    cin >> N;

    for(int i = 0; i < 3; i++)
    {
        DP[0][i] = {0,0};
    }
    
    for(int i = 0; i < N; i++)
    {
        cin >> score[0] >> score[1] >> score[2];
        DP[i+1][0] = {min(DP[i][0].first,DP[i][1].first ) + score[0], max(DP[i][0].second, DP[i][1].second) + score[0]};
        DP[i+1][1] = {min(DP[i][0].first,min(DP[i][1].first,DP[i][2].first)) + score[1], max(DP[i][0].second, max(DP[i][1].second,DP[i][2].second)) + score[1]};
        DP[i+1][2] = {min(DP[i][1].first,DP[i][2].first ) + score[2], max(DP[i][1].second, DP[i][2].second) + score[2]};
    }
    cout << max(DP[N][0].second, max(DP[N][1].second,DP[N][2].second)) << " " << min(DP[N][0].first,min(DP[N][1].first,DP[N][2].first)) << '\n';
}