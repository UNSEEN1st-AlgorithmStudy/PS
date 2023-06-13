/** 실제 정답 */
#include <iostream>
#include <string>
using namespace std;

int LCS[1001][1001];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string str1, str2;
    cin >> str1 >> str2;

    // dp의 최대 인덱스 값
    int n = str1.size() / 3;
    int m = str2.size() / 3;

    // 계산
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (str1.substr((i * 3) - 3, 3) == str2.substr((j * 3) - 3, 3))
            {
                LCS[i][j] = LCS[i - 1][j - 1] + 1;
            }
            else
            {
                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
            }
        }
    }

    cout << LCS[n][m] << endl;
}

/** 내 컴퓨터 */
//#include <iostream>
//#include <string>
//using namespace std;
//
//int LCS[1001][1001];
//
//int main()
//{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//    cout.tie(0);
//
//    string str1, str2;
//    cin >> str1 >> str2;
//
//    // dp의 최대 인덱스 값
//    int n = str1.size() / 2;
//    int m = str2.size() / 2;
//
//    // 계산
//    for (int i = 1; i <= n; i++)
//    {
//        for (int j = 1; j <= m; j++)
//        {
//            if (str1.substr((i * 2) - 2, 2) == str2.substr((j * 2) - 2, 2))
//            {
//                LCS[i][j] = LCS[i - 1][j - 1] + 1;
//            }
//            else
//            {
//                LCS[i][j] = max(LCS[i - 1][j], LCS[i][j - 1]);
//            }
//        }
//    }
//
//    cout << LCS[n][m] << endl;
//}