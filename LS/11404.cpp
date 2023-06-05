#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int m = 0;
	cin >> m;

	//�ʹݿ� ������ �����ϴ� ���� �ָ� �Ծ��ٺ���
	// long long���ٰ� INT32_MAX���� �����־��׿�. ����
	long long city[101][101] = {};

	for (size_t i = 0; i < 101; ++i)
	{
		for (size_t j = 0; j < 101; ++j)
		{
			if (i == j)
			{
				city[i][j] = 0;
				continue;
			}

			city[i][j] = INT32_MAX;
		}
	}


	for (size_t i = 0; i < m; ++i)
	{
		long long a = 0; //����
		long long b = 0; //����
		long long c = 0; //���

		cin >> a >> b >> c;

		city[a][b] = min(city[a][b], c);
	}

	for (size_t via = 1; via <= n; ++via)
	{
		for (size_t from = 1; from <= n; ++from)
		{
			for (size_t to = 1; to <= n; ++to)
			{
				long long from_via_to = city[from][via] + city[via][to];
				long long from_to = city[from][to];

				city[from][to] = min(from_to, from_via_to);
			}
		}
	}

	for (size_t from = 1; from <= n; ++from)
	{
		for (size_t to = 1; to <= n; ++to)
		{
			if (city[from][to] >= INT32_MAX)
			{
				city[from][to] = 0;
			}

			cout << city[from][to] << " ";
		}

		cout << '\n';
	}

	return 0;
}

//���
//�÷��̵� �ͼ��̶� �̷� ���̱���, �� �˰� �Ǿ����ϴ�.
//�ڵ��׽�Ʈ ������ Ǫ�� �ͻӸ� �ƴ϶� �˰��� ������ ���� �˰� �����ϴ� �͵� �ʹ� ������ �� �����ϴ�.
