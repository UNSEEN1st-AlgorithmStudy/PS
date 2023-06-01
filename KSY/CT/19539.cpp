#include<iostream>
#include<vector>
using namespace std;
int N;
int sum;
int Resume2;
int Divide2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>N;
    for(int i = 0; i<N; ++i){
        int input;
        cin>>input;
        sum+=input;
        Divide2+=input/2;
        Resume2+=input%2;
    }
    if(sum%3!=0){
        cout<<"NO";
        return 0;
    }
    if(Resume2>Divide2){
        cout<<"NO";
        return 0;
    }
    if(Resume2!=0){
        Divide2-=Resume2;
    }
    if(Divide2%3==0){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }
    return 0;
}
