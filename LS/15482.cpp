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

	//UTF-8: �ѱ�/3byte
	int offset = 3;

	//�ѱ��̹Ƿ� 3ĭ�� �̵�
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

//���
//LCS �������� �ѱ��� ���� ��� 3byte�� �̵�����!
