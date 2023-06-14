//17:13시작
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string str1, str2;
    cin>>str1>>str2;
    vector<vector<int>> arr(str1.size()+1, vector<int>(str2.size()+2));
    vector<char> result;
    for(int i = 1; i<=str1.size(); ++i){
        for(int j = 1; j<=str2.size(); ++j){
            if(str1[i-1]==str2[j-1]){
                arr[i][j] = arr[i-1][j-1]+1;
            }
            else{
                arr[i][j] = max(arr[i-1][j], arr[i][j-1]);
            }
        }
    }
    cout<<arr[str1.size()][str2.size()];
    cout<<'\n';
    //거슬러 올라가자
    int i = str1.size();
    int j = str2.size();
    while(i>=1 && j>=1){
        if(arr[i][j]==arr[i-1][j]){
            --i;
        }
        else if(arr[i][j]==arr[i][j-1]){
            --j;
        }
        else if(arr[i][j]==arr[i-1][j-1]+1){
            result.push_back(str1[i-1]);
            --i;
            --j;
        }
    }
    for(int k = result.size()-1; k>=0; --k){
        cout<<result[k];
    }
    
}
//17:27 끝
