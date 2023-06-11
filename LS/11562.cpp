//내가 푼 코드
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//int main()
//{
//	ios_base::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
//
//	int arr[251][251] = {};
//
//	for (size_t i = 0; i < 250; ++i)
//	{
//		for (size_t j = 0; j < 250; ++j)
//		{
//			arr[i][j] = -1;
//		}
//	}
//
//	int m = 0;
//	int n = 0;
//
//	cin >> m >> n;
//
//	for (size_t i = 0; i < m; ++i)
//	{
//		int u = 0;
//		int v = 0;
//		int b = 0;
//
//		cin >> u >> v >> b;
//
//		arr[u][v] = b;
//	}
//
//	int k = 0;
//
//	for (size_t i = 0; i < k; ++i)
//	{
//		int s = 0;
//		int e = 0;
//
//		cin >> s >> e;
//
//		if (-1 == arr[s][e])
//		{
//			//1
//		}
//	}
//
//	return 0;
//}


//답을 보고 수정한 코드
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[251][251] = {};

	for (size_t i = 0; i <= 250; ++i)
	{
		for (size_t j = 0; j <= 250; ++j)
		{
			arr[i][j] = -1;
		}
	}

	int m = 0;
	int n = 0;

	cin >> m >> n;

	for (size_t i = 0; i < m; ++i)
	{
		int u = 0;
		int v = 0;
		int b = 0;

		cin >> u >> v >> b;

		arr[u][v] = 0;

		if (!b) //0
		{
			arr[v][u] = 1;
		}

		if (b) //1
		{
			arr[v][u] = 0;
		}
	}

	for (int t = 1; t <= n; ++t)
	{
		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if (i == j)
				{
					//같은 곳에서 같은 곳은 0.
					arr[i][j] = 0;
				}

				arr[i][j] = min(arr[i][j], arr[i][t] + arr[t][j]);
			}
		}
	}

	int k = 0;
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		int s = 0;
		int e = 0;

		cin >> s >> e;
		cout << arr[s][e] << '\n';
	}

	return 0;
}

//결과
//갈 때 필요한 비용을 만드는 게 어려웠는데 막상 코드를 보니까 어렵지 않았네요. 하하.
