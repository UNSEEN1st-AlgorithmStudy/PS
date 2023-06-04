#include <iostream>

using namespace std;

int[101][101] bag = {};

int main()
{
	int n = 0;
	int k = 0;

	cin >> n << k;

	for(int i = 1; i <= n; ++i)
	{
		int w = 0;
		int v = 0;

		cin >> w >> v;

		bag[i] = w;
		bag[i][i] = v;
	}

	int a = 0;

	return 0;
}
