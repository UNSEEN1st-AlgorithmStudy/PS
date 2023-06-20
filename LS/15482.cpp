#include <iostream>
#include <string>

using namespace std;

int LCS[3003][3003];

int main()
{
	string str1 = {};
	string str2 = {};

	cin >> str1;
	cin >> str2;

	int n = str1.size();
	int m = str2.size();

	//UTF-8: 한글/3byte
	int offset = 3;

	//한글이므로 3칸씩 이동
	for (int i = 3; i <= n; i += offset)
	{
		for (int j = 3; j <= m; j += offset)
		{
			if (str1.substr(i - 3, offset) == str2.substr(j - 3, offset))
			{
				LCS[i][j] = LCS[i - 3][j - 3] + 1;
			}

			else
			{
				LCS[i][j] = max(LCS[i - 3][j], LCS[i][j - 3]);
			}
		}
	}

	cout << LCS[n][m] << endl;
}

//결과
//LCS 문제에서 한글이 들어올 경우 3byte씩 이동하자!
