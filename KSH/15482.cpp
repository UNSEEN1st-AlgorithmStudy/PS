#include <iostream>
#include <string>
using namespace std;


const int LENGTH_MAX = 1001;
const int CHAR_SIZE = 3;
string s1, s2;
int LCS[LENGTH_MAX * CHAR_SIZE][LENGTH_MAX * CHAR_SIZE];
int s1Size, s2Size, LCSLength = 0;


void findLCSLength()
{
    s1Size = s1.size();
    s2Size = s2.size();

    for (int i = CHAR_SIZE; i <= s1Size; i += CHAR_SIZE)
    {
        for (int j = CHAR_SIZE; j <= s2Size; j += CHAR_SIZE)
        {
            LCS[i][j] = (s1.substr(i - CHAR_SIZE, CHAR_SIZE) == s2.substr(j - CHAR_SIZE, CHAR_SIZE)) ?
                LCS[i - CHAR_SIZE][j - CHAR_SIZE] + 1 : max(LCS[i - CHAR_SIZE][j], LCS[i][j - CHAR_SIZE]);
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

    cout << LCSLength;
}