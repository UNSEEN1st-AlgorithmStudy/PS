#include <iostream>
#include <string>
using namespace std;


const int LENGTH_MAX = 1001;
string s1, s2;
int LCS[LENGTH_MAX][LENGTH_MAX];
int s1Size, s2Size, LCSLength = 0;
bool found = false;
char printArr[LENGTH_MAX];


void findLCSLength()
{
    s1Size = s1.size();
    s2Size = s2.size();
    
    for (int i = 1; i <= s1Size; i++)
    {
        for (int j = 1; j <= s2Size; j++)
        {
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? LCS[i-1][j-1] + 1 : max(LCS[i][j-1], LCS[i-1][j]);
            LCSLength = max(LCSLength, LCS[i][j]);
        }
    }
}

void findLCS(int i, int j, int len)
{
    if (len == 0) return;

    int nextLen = len;
    
    if (LCS[i-1][j-1] != len && LCS[i][j-1] != len && LCS[i-1][j] != len)
    {
        printArr[len-1] = s1[i-1];
        nextLen = len-1;
    }

    if (LCS[i-1][j-1] == nextLen)
        findLCS(i-1, j-1, nextLen);
    else if (LCS[i-1][j] == nextLen)
        findLCS(i-1, j, nextLen);
    else if (LCS[i][j-1] == nextLen)
        findLCS(i, j-1, nextLen);
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> s1 >> s2;
    
    findLCSLength();
    
    cout << LCSLength << '\n';
    
    for (int i = s1Size; i >= 1; i--)
    {
        for (int j = s2Size; j >= 1; j--)
        {
            if (LCS[i][j] != LCSLength) continue;
            findLCS(i, j, LCSLength);
            break;
        }
    }

    for (int i = 0; i < LCSLength; i++)
        cout << printArr[i];
    cout << '\n';
}