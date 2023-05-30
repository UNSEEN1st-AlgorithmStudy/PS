#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n = 0, answer = 0;
	cin >> n;

	// 2차원 배열, 초깃 값 지정
	vector<vector<int>> arr(n + 1 , vector<int>(n + 1, -1));
	cin >> arr[1][1];

	// 상단의 값들 중 가장 큰 값과 합산
	for (int i = 2; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cin >> arr[i][j];
			arr[i][j] += max(arr[i-1][j-1], arr[i-1][j]);
		}
	}

	// 최하단에서 가장 큰 수 찾기
	for (int i = 1; i <= n; i++)
	{
		answer = max(answer,arr[n][i]);
	}
	cout << answer;
}