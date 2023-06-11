//내가 푼 코드
//#include <iostream>
//using namespace std;
//
//int stairs[301] = {};
//int answer      = 0;
//
//void Func(bool isCompare, int idx)
//{
//	if (0 >= idx)
//	{
//		return;
//	}
//
//	if (false == isCompare)
//	{
//		answer += stairs[idx - 1];
//	}
//
//	else
//	{
//		answer += stairs[idx - 2];
//	}
//
//	isCompare = !isCompare;
//	isCompare ? Func(isCompare, idx - 1) : Func(isCompare, idx - 2);
//}
//
//int main()
//{
//	int count = 0;
//	cin >> count;
//
//	for (size_t i = 1; i < count; ++i)
//	{
//		int number = 0;
//		cin >> number;
//
//		stairs[i] = number;
//	}
//
//	bool isCompare = stairs[count - 1] < stairs[count - 2] ? true : false;
//	answer += max(stairs[count - 1], stairs[count - 2]);
//	Func(isCompare, count);
//
//	cout << answer << endl;
//}

//답을 보고 수정한 코드
#include <iostream>

using namespace std;

int stair[301] = {};
int dp[301] = {};

int main()
{
	int n = 0;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cin >> stair[i];
	}

	dp[0] = stair[0];
	dp[1] = max(stair[0] + stair[1], stair[1]);
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	//이걸 내가 생각해낸다라... 조금 무리일지도?
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
	}

	cout << dp[n - 1] << '\n';

	return 0;
}

// 결과
//오늘도 혼자 1시간 정도 풀다가 답을 보았고 자괴감에 휩싸였습니다. 제기랄.

//어려운 점.
//이전 문제에서는 답을 보고 "아 이렇게 생각하면 되는 거구나"라고 생각했지만 이번 문제 답을 보고 더 높은 벽을 느꼈다.
//점화식까지는 얼추 맞았지만 그것을 DP로 적용해내지 못했다. (응 핑계~)

//깨달은 점
//이게 정보올림피아드 초등부 문제라는 것에 대해 새로 알게 되었다. (농답입니다.)
//DP는 일단 점화식을 세우는 게 가장 급선무다.
