#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int dx[4] {-1, 1, 0, 0};
int dy[4] {0, 0, -1, 1};
char Arr[26][26];
vector<int> Count;
int N;

int main()
{
	cin >> N;
	for (int i = 0 ; i < N; i++)
		cin >> Arr[i];

	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (Arr[i][j] == '0')
				continue;
			queue<pair<int, int>> BFSQueue;
			int count = 1;
			BFSQueue.push({i, j});
			Arr[i][j] = '0';
			while (BFSQueue.size())
			{
				int n, m;
				n = BFSQueue.front().first;
				m = BFSQueue.front().second;
				BFSQueue.pop();

				for (int k = 0 ; k < 4 ; k++)
				{
					int next_n = n + dx[k];
					int next_m = m + dy[k];
					if (next_n >= 0 && next_n <= N-1 \
						&& next_m >= 0 && next_m <= N-1 \
						&& Arr[next_n][next_m] == '1')
					{
						BFSQueue.push({next_n, next_m});
						Arr[next_n][next_m] = '0';
						count++;
					}
				}
			}
			Count.push_back(count);
		}
	}
	cout << Count.size() << endl;
	sort(Count.begin(), Count.end());
	for (auto elem : Count)
		cout << elem << endl;

	return 0;
}
