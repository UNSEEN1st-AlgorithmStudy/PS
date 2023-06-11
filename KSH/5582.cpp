#include <iostream>
#include <string>
using namespace std;

const int LENGHT_MAX = 4001;
string s1, s2;
int s1Size, s2Size, LCSLength = 0;
int LCS[LENGHT_MAX][LENGHT_MAX];


void findLongestCommonSubstringLength()
{
    s1Size = s1.size();
    s2Size = s2.size();
    
    for (int i = 1; i <= s1Size; i++)
    {
        for (int j = 1; j <= s2Size; j++)
        {
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? LCS[i-1][j-1] + 1 : 0;
            LCSLength = max(LCSLength, LCS[i][j]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s1 >> s2;
    
    findLongestCommonSubstringLength();
    
    cout << LCSLength << '\n';
}
