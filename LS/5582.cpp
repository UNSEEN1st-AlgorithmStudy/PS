#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// 최장 공통 문자열을 저장할 배열
	int LCS[4001][4001] = {};

	string s1 = {};
	string s2 = {};

	cin >> s1;
	cin >> s2;

	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			LCS[i][j] = (s1[i - 1] == s2[j - 1]) ? LCS[i - 1][j - 1] + 1 : 0;
		}
	}

	int result = 0;

	for (int i = 1; i <= s1.size(); ++i)
	{
		for (int j = 1; j <= s2.size(); ++j)
		{
			result = max(result, LCS[i][j]);
		}
	}

	cout << result;

	return 0;
}

//결과
//전에 엔픽셀 코테를 봤을 때 처음 봤던 문제가 두 문자열이 들어오고
//두 문자열의 겹치는 부분을 붙여서 만들 수 있는 문자열 중 가장 작은 문자열을 찾아라.
//라는 문제가 나왔었습니다. 그때 풀어내지 못했었는데 LCS 문제라는 걸 이제 알게 됐네요. 하하
