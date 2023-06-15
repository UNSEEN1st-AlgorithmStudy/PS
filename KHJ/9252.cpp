#include <iostream>
#include <string>
using namespace std;
const int MAX = 1001;
int LCS[MAX][MAX];
string s1, s2;
string ans;

int main()
{
    cin >> s1;
    cin >> s2;
    
    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? LCS[i-1][j-1] + 1 : max(LCS[i-1][j], LCS[i][j-1]);
        }
    }
    
    cout << LCS[s1.size()][s2.size()] << '\n';

    int col = s2.size();

    for(int i = s1.size(); i >= 0; i--)
    {
        if(LCS[i][col] == 0) break;
        for(int j = col; j >= 0; j--)
        {
            if(LCS[i][j] == LCS[i-1][j]) break;
            if(LCS[i][j] != LCS[i][j-1])
            {
                ans += s2[j-1];
                col = j-1;
                break;
            }
        }
    }
    
    if(LCS[s1.size()][s2.size()] == 0)
        return 0;
    
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i];
}