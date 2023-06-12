#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int LCS[1001][1001] = {};

	string s1 = {};
	string s2 = {};

	cin >> s1 >> s2;

	int size1 = s1.size();
	int size2 = s2.size();

	for (int i = 1; i <= size1; ++i)
	{
		for (int j = 1; j <= size2; ++j)
		{
			LCS[i][j] = (s1[i - 1] == s2[j - 1]) ? LCS[i - 1][j - 1] + 1 : max(LCS[i - 1][j], LCS[i][j - 1]);
		}
	}

	cout << LCS[size1][size2];

	return 0;
}
