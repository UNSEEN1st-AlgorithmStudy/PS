#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX_NUM 100'000

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[51][51] = {};

	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (i == j)
			{
				continue;
			}

			else
			{
				arr[i][j] = MAX_NUM;
			}
		}
	}

	//왜 굳이 -1이 들어올까?
	while (true)
	{
		int a = 0;
		int b = 0;

		cin >> a >> b;

		if (-2 == a + b)
		{
			break;
		}

		arr[a][b] = 1;
		arr[b][a] = 1;
	}

	for (size_t via = 1; via <= n; ++via)
	{
		for (size_t from = 1; from <= n; ++from)
		{
			for (size_t to = 1; to <= n; ++to)
			{
				if (arr[from][to] > arr[from][via] + arr[via][to])
				{
					arr[from][to] = arr[from][via] + arr[via][to];
				}
			}
		}
	}

	int result = MAX_NUM;

	//회장 후보들
	vector<int> v = {};

	for (int i = 1; i <= n; i++)
	{
		int temp = 0;

		for (int j = 1; j <= n; j++)
		{
			temp = max(temp, arr[i][j]);
		}

		if (temp < result)
		{
			v.clear();
			result = temp;
			v.push_back(i);
		}

		else if (temp == result)
		{
			v.push_back(i);
		}
	}

	sort(v.begin(), v.end());

	cout << result << " " << v.size() << '\n';

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}

	return 0;
}

//결과
//플로이드 와샬 문제들이 전부 한준님의 템플릿 코드를 벗어나지 않아서 의외였습니다. 한번 꼰 문제 있을 줄 알았네요.
//마지막 후보 출력 부분이 감이 안와서 블로그를 봐버렸습니다. 하하.
