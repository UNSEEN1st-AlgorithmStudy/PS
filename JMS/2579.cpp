#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = 0;
	cin >> n;

	vector<int> arr(n + 1);			// 계산 크기
	vector<int> dp(n + 1);			// 최대 크기
	for (int i = 1; i <= n; i++) cin >> arr[i];

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);

	for (int i = 4; i <= n; i++)
	{
		int one = arr[i - 1] + dp[i - 3];		// 1칸 이동
		int two = dp[i - 2];					// 2칸 이동
		dp[i] = max(one, two) + arr[i];
	}

	cout << dp[n];
}