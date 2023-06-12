#include <iostream>
#include <string>
using namespace std;


const int LENGTH_MAX = 1001;
string s1, s2;
int LCS[LENGTH_MAX][LENGTH_MAX];
int LCSLength = 0;


void findLCSLength()
{
    for (int i = 1; i <= s1.size(); i++)
    {
        for (int j = 1; j <= s2.size(); j++)
        {
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? LCS[i-1][j-1] + 1 : max(LCS[i][j-1], LCS[i-1][j]);
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
    
    findLCSLength();
    
    cout << LCSLength << '\n';
}
