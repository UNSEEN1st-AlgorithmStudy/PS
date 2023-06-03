//���� Ǭ �ڵ�.
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
//			//�� ��û��, �̰� DP��?
//			Result = max((arr[i].value + arr[i + 1].value), Result);
//		}
//	}
//
//	cout << Result << '\n';
//
//	return 0;
//}

//���� ���� ������ �ڵ�
#include <iostream>

using namespace std;

int w[101] = {};
int v[101] = {};

//ó������ i��°���� ������ ���캸��, �賶�� �뷮�� j���� �� �賶�� �� ������ ��ġ���� �ִ�
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
			// i��° ������ ���� �� �ִٸ�?
			if (j - w[i] >= 0)
			{
				// ���� ���� ���� �־��� ��, �� �� �� ū ������ �ʱ�ȭ
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
			}

			// i��° ������ ���� �� ���ٸ�
			else
			{
				// �賶 �뷮�� ���� ���� �ʾ��� ���� ������ �ʱ�ȭ
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	cout << dp[N][K];

	return 0;
}

//���
//ó�� Ǯ���� �� �׽�Ʈ ���̽��� ���鼭 Ǯ���ٺ��� �׽�Ʈ ���̽����� �´� �ڵ尡 �Ǿ����ϴ�.
//�� �� ���� �ٸ� �׽�Ʈ ���̽��� ������ �̻��� �ڵ��� ���� ���޾ҽ��ϴ�.

//����� ��.
//�̹� ������ ��ȭ���� ����� �� �������.
//->���� ���� �� �ð��� ���� ��Ǯ���ڴ� �;���.

//������ ��.
//�˻��ϸ鼭 ���� ������ DP�� ���� Ǫ�� ��Ŀ� ���� �˰� �Ǿ���.
