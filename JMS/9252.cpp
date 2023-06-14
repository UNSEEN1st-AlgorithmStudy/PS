/* 틀린 풀이 */
#include <iostream>
#include <string>
using namespace std;

string LCS[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str1, str2, answer;
    cin >> str1 >> str2;

    // dp의 최대 인덱스 값
    int n = str1.length();
    int m = str2.length();

    // 계산
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                LCS[i][j] = LCS[i - 1][j - 1] + str1[i - 1];
            }
            else
            {
                LCS[i][j] = (LCS[i - 1][j].length() >= LCS[i][j - 1].length()) ? LCS[i - 1][j] : LCS[i][j - 1];
            }
        }
    }

    cout << LCS[n][m].length() << '\n' << LCS[n][m];
}