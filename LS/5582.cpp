#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	// ���� ���� ���ڿ��� ������ �迭
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

//���
//���� ���ȼ� ���׸� ���� �� ó�� �ô� ������ �� ���ڿ��� ������
//�� ���ڿ��� ��ġ�� �κ��� �ٿ��� ���� �� �ִ� ���ڿ� �� ���� ���� ���ڿ��� ã�ƶ�.
//��� ������ ���Ծ����ϴ�. �׶� Ǯ��� ���߾��µ� LCS ������� �� ���� �˰� �Ƴ׿�. ����
