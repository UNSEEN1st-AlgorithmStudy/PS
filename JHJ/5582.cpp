#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 4001;
string s1, s2;

int main(){
    int maxLength = -1;

    cin >> s1;
    cin >> s2;
    
int LCS[MAX][MAX] = {};

    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? LCS[i-1][j-1] + 1 : 0;
            maxLength = max(LCS[i][j], maxLength);
        }
    }

    cout << maxLength << '\n';
}