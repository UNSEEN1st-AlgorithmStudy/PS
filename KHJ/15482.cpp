#include <iostream>
#include <string>
using namespace std;
const int MAX = 1001;
int LCS[MAX][MAX];
wstring s1, s2;

int main()
{
    locale::global(locale(""));
    wcin >> s1 >> s2;
    
    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? LCS[i-1][j-1] + 1 : max(LCS[i-1][j], LCS[i][j-1]);
        }
    }

    cout << LCS[s1.size()][s2.size()];
    return 0;
}