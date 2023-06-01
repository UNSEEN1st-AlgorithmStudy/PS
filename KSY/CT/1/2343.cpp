#include<iostream>
#include<vector>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, M;
    cin>>N>>M;
    vector<int> lecture(N);
    int sumSize = 0;
    int Min = 0;
    for(int i = 0; i<N; ++i){
        cin>>lecture[i];
        sumSize+=lecture[i];
        //이 부분에서 많이 소요됨. lo를 결정하는 부분에서 원소 중 가장 큰 애로 해야 가장 작은 단위의 블루레이가 나올텐데 당연히 min으로 생각함
        Min = max(Min, lecture[i]);
    }
    //사이즈
    int lo = Min;
    int hi = sumSize;
    int mid;
    while(lo<=hi){
        mid = (lo+hi)/2;
        long long tempSum = 0;
        int layCnt = 0;
        for(int i = 0; i<N; ++i){
            if((tempSum+lecture[i])>mid){
                ++layCnt;
                tempSum = 0;
            }
            tempSum+=lecture[i];
        }
        if(tempSum>0) ++layCnt;
        if(layCnt<=M) hi = mid-1;
        else lo = mid+1;
    }
    cout<<lo;
}
