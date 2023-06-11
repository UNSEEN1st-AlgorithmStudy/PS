
#include <iostream>

int arr[10001] = {};

int main()
{
	int n = 0;
	int m = 0;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		cin >> arr[i];
	}

	int Result = 0;

	for (int i = 1; i < n; ++i)
	{
		if (m == arr[i])
		{
			++Result;
		}

		int number = arr[i];

		for (int j = i; j <= n; ++j)
		{
			number += arr[i + j];

			if (m == number)
			{
				++Result;
				break;
			}
		}
	}

	cout << Result << '\n';
}