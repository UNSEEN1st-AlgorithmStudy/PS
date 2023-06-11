#include <iostream>
#include <string>
using namespace std;

int LCS[4001][4001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int answer = 0;
	string n, m;

	// 계산
	cin >> n >> m;
	for (size_t i = 1; i <= n.size(); i++)
	{
		for (size_t j = 1; j <= m.size(); j++)
		{
			LCS[i][j] = (n[i - 1] == m[j - 1]) ? LCS[i - 1][j - 1] + 1 : 0;
			answer = max(answer, LCS[i][j]);
		}
	}

	cout << answer;
}