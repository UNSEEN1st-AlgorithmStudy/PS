#include <iostream>
#include <string>
using namespace std;

string s1, s2;
int LCS[1001][1001];

void PrintLCS(int i, int j){
    if(LCS[i][j] == 0)  return;

    if(s1[i-1] == s2[j-1]){
        PrintLCS(i-1, j-1);
        cout << s1[i-1];
        return;
    }

    (LCS[i-1][j] > LCS[i][j-1]) ? PrintLCS(i-1, j) : PrintLCS(i, j-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> s1;
    cin >> s2;

    for(int i = 1; i <= s1.size(); i++){
        for(int j = 1; j <= s2.size(); j++){
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? 
                        LCS[i-1][j-1] + 1 : 
                        max(LCS[i-1][j], LCS[i][j-1]);
        }
    }

    cout << LCS[s1.size()][s2.size()] << '\n';
    if(LCS[s1.size()][s2.size()] == 0)    return 0;

    PrintLCS(s1.size(), s2.size());
}