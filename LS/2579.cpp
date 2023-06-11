//���� Ǭ �ڵ�
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

//���� ���� ������ �ڵ�
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

	//�̰� ���� �����س��ٶ�... ���� ����������?
	for (int i = 3; i < n; i++)
	{
		dp[i] = max(dp[i - 2] + stair[i], stair[i - 1] + stair[i] + dp[i - 3]);
	}

	cout << dp[n - 1] << '\n';

	return 0;
}

// ���
//���õ� ȥ�� 1�ð� ���� Ǯ�ٰ� ���� ���Ұ� �ڱ����� �۽ο����ϴ�. �����.

//����� ��.
//���� ���������� ���� ���� "�� �̷��� �����ϸ� �Ǵ� �ű���"��� ���������� �̹� ���� ���� ���� �� ���� ���� ������.
//��ȭ�ı����� ���� �¾����� �װ��� DP�� �����س��� ���ߴ�. (�� �ΰ�~)

//������ ��
//�̰� �����ø��ǾƵ� �ʵ�� ������� �Ϳ� ���� ���� �˰� �Ǿ���. (����Դϴ�.)
//DP�� �ϴ� ��ȭ���� ����� �� ���� �޼�����.
