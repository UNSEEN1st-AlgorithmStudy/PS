#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int N;
int gap = 987'654'321;
//S, B
vector<pair<int, int>> ingredient;
void dfs(int idx, int nowS, int nowB){
    if(idx==N){
        int nowGap = abs(nowS-nowB);
        //아무것도 재료가 추가되지 않았을 때
        if(nowB==0) return;
        gap = min(nowGap, gap);
        return;
    }
    //해당 재료를 추가하기로 하자
    dfs(idx+1, nowS*ingredient[idx].first, nowB+ingredient[idx].second);
    //해당 재료를 추가하지 말자
    dfs(idx+1, nowS, nowB);
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    ingredient.resize(N);
    for(int i = 0; i<N;++i){
        cin>>ingredient[i].first>>ingredient[i].second;
    }
    dfs(0, 1, 0);
    cout<<gap;
}
