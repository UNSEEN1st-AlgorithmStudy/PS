#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int result = 0;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str1, str2;
    cin>>str1>>str2;
    vector<vector<int>> v(str1.size()+1, vector<int>(str2.size()+1, 0)); //str1 = row, str2 = col
    for(int i = 1; i<=str1.size(); ++i){
        for(int j = 1; j<=str2.size(); ++j){
            if(str1[i-1]==str2[j-1]){
                v[i][j] = v[i-1][j-1]+1;
                result = max(result, v[i][j]);
            }
            else{
                v[i][j] = 0;
            }
        }
    }
    cout<<result;

}
