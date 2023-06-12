#include <iostream>
#include <string>
using namespace std;
const int MAX = 4001;
int LCS[MAX][MAX];
int maxValue;
string s1, s2;

int main()
{
    cin >> s1;
    cin >> s2;
    
    for(int i = 1; i <= s1.size(); i++)
    {
        for(int j = 1; j <= s2.size(); j++)
        {
            // 만일 문자가 같다면 이전의 문자열이 늘어난 것이므로 +1, 아니라면 '연속이 아니니깐' 0으로 저장
            LCS[i][j] = (s1[i-1] == s2[j-1]) ? LCS[i-1][j-1] + 1 : 0;
            if(LCS[i][j] > maxValue) maxValue = LCS[i][j]; 
        }
    }
    cout << maxValue;
    return 0;
}