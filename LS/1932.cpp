//내가 푼 코드
//#include <iostream>
//#include <vector>
//
//using namespace std;
//
//std::vector<std::vector<int>> Vec = {};
//std::vector<int> Dp               = {};
//
//int Func(int a, int b, int layer)
//{
//	if (Vec.size() - 1 <= layer)
//	{
//		return 0;
//	}
//
//	int num       = max(a, b);
//	int nextLayer = layer + 1;
//
//	//풀다가 어? 이러면 걍 그리디 아닌가?
//	return num + Func(Vec[nextLayer][0], Vec[nextLayer][1], nextLayer);
//}
//
//int main()
//{
//	int n = 0;
//
//	std::cin >> n;
//
//	Vec.resize(n);
//
//	for (size_t i = 0; i < n; ++i)
//	{
//		Vec[i].resize(i + 1);
//
//		for (size_t j = 0; j <= i; ++j)
//		{
//			std::cin >> Vec[i][j];
//		}
//	}
//
//	int result = Func(Vec[1][0], Vec[1][1], 1);
//
//	return 0;
//}

//답을 보고 수정한 코드
#include <iostream>
#include <vector>

using namespace std;

//입력값
std::vector<std::vector<int>> Vec = {};

int main()
{
	int n = 0;

	std::cin >> n;

	Vec.resize(n);

	for (size_t i = 0; i < n; ++i)
	{
		Vec[i].resize(i + 1);

		for (size_t j = 0; j <= i; ++j)
		{
			std::cin >> Vec[i][j];
		}
	}

	//거꾸로 순회
	for (int i = n - 1; i >= 1; --i)
	{
		for (int j = 0; j < i; ++j)
		{
			Vec[i - 1][j] += max(Vec[i][j], Vec[i][j + 1]);
		}
	}

	std::cout << Vec[0][0] << std::endl;
}

//결과
//혼자 1시간 정도 풀다가 더 이상 시간 쓰는 게 의미없을 거 같아서 답을 보았고 자괴감을 느꼈습니다.

//어려운 점.
//1. 노드들을 다 거치면서 큰 수를 찾는 게 머릿속에서 잘 안그려짐.
//2. 거꾸로 순회해서 최상위 노드에 값을 둔다는 아이디어를 생각해내지 못함.
//-> 풀면서 Vector Dp에 순회한 값을 다 넣어둔 뒤 Sort 함수로 정렬하려고 했음... 

//깨달은 점.
//1. 풀면서 입력 받을 때 들어오는 입력 양만큼 배열의 크기를 잡아야 된다고 생각함.
//->사실 그냥 크기를 많이 잡아두고 넣어둔 인덱스로만 접근하면 됨.
//2. '위와 같은 방식으로 풀어도 DP구나'라고 알게 됨.
