#include <iostream>
#include <string>
using namespace std;

int LCS[3001][3001];
string s1, s2;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s1 >> s2;

    for(int i = 3; i <= s1.size(); i += 3){
        for(int j = 3; j <= s2.size(); j += 3){
            LCS[i][j] = (s1.substr(i - 3, 3) == s2.substr(j - 3, 3)) ? 
                        LCS[i-3][j-3] + 1 : 
                        max(LCS[i-3][j], LCS[i][j-3]);
        }
    }

    cout << LCS[s1.size()][s2.size()] << '\n';
}