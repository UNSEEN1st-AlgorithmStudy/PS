#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int arr[50][50] = {};

	int n = 0;
	cin >> n;

	for (size_t i = 0; i < n; ++i)
	{
		int u = 0;
		int v = 0;

		cin >> u >> v;

		arr[u][v] = 1;
	}

	for (size_t via = 0; via < n; ++via)
	{
		for (size_t from = 0; from < n; ++from)
		{
			for (size_t to = 0; to < n; ++to)
			{
				if (arr[from][to] > arr[from][via] + arr[via][to])
				{
					arr[from][to] = arr[from][via] + arr[via][to];
				}
			}
		}
	}

	return 0;
}
