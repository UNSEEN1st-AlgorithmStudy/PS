//내가 푼 코드.
//#include <iostream>
//
//using namespace std;
//
//struct thing
//{
//	int weight;
//	int value;
//};
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//
//	thing arr[101] = {};
//
//	cin >> n >> k;
//
//	for (int i = 1; i <= n; ++i)
//	{
//		int w = 0;
//		int v = 0;
//
//		cin >> w >> v;
//
//		arr[i].weight = w;
//		arr[i].value  = v;
//	}
//
//	int Result = 0;
//
//	for (int i = 1; i < n; ++i)
//	{
//		int w = arr[i].weight + arr[i + 1].weight;
//
//		if (k >= w)
//		{
//			//이 멍청아, 이게 DP냐?
//			Result = max((arr[i].value + arr[i + 1].value), Result);
//		}
//	}
//
//	cout << Result << '\n';
//
//	return 0;
//}

//답을 보고 수정한 코드
#include <iostream>

using namespace std;

int w[101] = {};
int v[101] = {};

//처음부터 i번째까지 물건을 살펴보고, 배낭의 용량이 j였을 때 배낭에 들어간 물건의 가치합의 최댓값
int dp[101][100001] = {};

int main()
{
	int N = 0;
	int K = 0;

	cin >> N >> K;

	for (int i = 1; i <= N; ++i)
	{
		cin >> w[i] >> v[i];
	}

	for (int i = 1; i <= N; ++i)
	{
		for (int j = 1; j <= K; ++j)
		{
			// i번째 물건을 넣을 수 있다면?
			if (j - w[i] >= 0)
			{
				// 넣지 않을 때와 넣었을 때, 둘 중 더 큰 것으로 초기화
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}

			// i번째 물건을 넣을 수 없다면
			else
			{
				// 배낭 용량은 같고 넣지 않았을 때의 값으로 초기화
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];

	return 0;
}

//결과
//처음 풀었을 때 테스트 케이스를 보면서 풀었다보니 테스트 케이스에만 맞는 코드가 되었습니다.
//그 후 제가 다른 테스트 케이스를 만들어보니 이상한 코드라는 것을 깨달았습니다.

//어려운 점.
//이번 문제도 점화식을 세우는 게 어려웠다.
//->답을 보고 몇 시간을 쓰든 못풀었겠다 싶었다.

//깨달은 점.
//검색하면서 냅색 문제를 DP를 통해 푸는 방식에 대해 알게 되었다.
