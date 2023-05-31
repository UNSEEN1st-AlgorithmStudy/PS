#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N;
vector<int> stairs;
vector<int> dp;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin>>N;
    stairs.resize(N);
    dp.resize(N);
    for(int i = 0; i<N; ++i){
        cin>>stairs[i];
    }
    dp[0] = stairs[0];
    dp[1] = dp[0] + stairs[1];
    dp[2] = max(dp[0]+stairs[2], stairs[1]+stairs[2]);
    for(int i = 3; i<N; ++i){
        dp[i] = max(dp[i-3]+stairs[i-1], dp[i-2])+stairs[i];
    }
    cout<<dp[N-1];
}
