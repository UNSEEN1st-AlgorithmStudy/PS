#include <iostream>
using namespace std;

/**
* R을 칠했을 때, 'GB' 참조
* G을 칠했을 때, 'RB' 참조
* B을 칠했을 때, 'RG' 참조
* - 다른 색깔의 인덱스를 위한 배열 (Another Color Index)
* - 0번 인덱스는 무시
*/
pair<int, int> ac_idx[4] = { {0,0}, {2,3}, {1,3}, {1,2} };
int arr[1001][1001];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= 3; j++)
		{
			cin >> arr[i][j];
			arr[i][j] = min(arr[i - 1][ac_idx[j].first], arr[i - 1][ac_idx[j].second]) + arr[i][j];
		}
	}

	// 결과
	cout << min(arr[n][1], min(arr[n][2], arr[n][3]));
}