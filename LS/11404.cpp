#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	int m = 0;
	cin >> m;

	//초반에 범위를 설정하는 데서 애를 먹었다보니
	// long long에다가 INT32_MAX까지 때려넣었네요. 하하
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
		long long a = 0; //시작
		long long b = 0; //도착
		long long c = 0; //비용

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

//결과
//플로이드 와샬이란 이런 것이구나, 또 알게 되었습니다.
//코딩테스트 문제를 푸는 것뿐만 아니라 알고리즘 개념을 새로 알고 이해하는 것도 너무 유익한 거 같습니다.
