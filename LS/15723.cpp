#include <iostream>

using namespace std;

int main()
{
	//����� 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool arr[26][26] = {};

	int n = 0;
	cin >> n;

	//����
	for (size_t i = 0; i < n; ++i)
	{
		string str = {};
		cin >> str;
		int a = str[0] - 'a';
		cin >> str; //is
		cin >> str;
		int b = str[0] - 'a';

		arr[a][b] = true;
	}

	//��� �ؾ� ������ ������� ��Ҹ� ������ ����ߴµ�
	//�׳� �� ���������� �Ǵ� ���̿���..!
	for (size_t via = 0; via < 26; ++via)
	{
		for (size_t from = 0; from < 26; ++from)
		{
			for (size_t to = 0; to < 26; ++to)
			{
				if (arr[from][via] && arr[via][to])
				{
					arr[from][to] = true;
				}
			}
		}
	}

	int m = 0;
	cin >> m;

	string result = {};

	//���
	for (size_t i = 0; i < m; i++)
	{
		string str = {};
		cin >> str;
		int a = str[0] - 'a';
		cin >> str; //is
		cin >> str;
		int b = str[0] - 'a';

		if (true == arr[a][b])
		{
			result += "T";
		}

		else
		{
			result += "F";
		}
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}

//���
//����� �κ��� �Ӹ��ӿ� �ȱ׷����� ��α׸� ��½ ���ҽ��ϴ�. ����.
//�׳��� DP���� ���� ���µ� �Ƹ� �����̸� �ƴϰ� �� �� �����ϴ�. ����!
