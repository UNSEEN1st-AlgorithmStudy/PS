#include <iostream>

using namespace std;

int main()
{
	//입출력 
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	bool arr[26][26] = {};

	int n = 0;
	cin >> n;

	//전제
	for (size_t i = 0; i < n; ++i)
	{
		string str = {};
		cin >> str;
		int a = str[0] - 'a';
		cin >> str; //is
		cin >> str;
		int b = str[0] - 'a';

		arr[a][b] = true;
	}

	//어떻게 해야 위에서 집어넣은 요소만 돌리나 고민했는데
	//그냥 다 돌려버리면 되는 것이였다..!
	for (size_t via = 0; via < 26; ++via)
	{
		for (size_t from = 0; from < 26; ++from)
		{
			for (size_t to = 0; to < 26; ++to)
			{
				if (arr[from][via] && arr[via][to])
				{
					arr[from][to] = true;
				}
			}
		}
	}

	int m = 0;
	cin >> m;

	string result = {};

	//결론
	for (size_t i = 0; i < m; i++)
	{
		string str = {};
		cin >> str;
		int a = str[0] - 'a';
		cin >> str; //is
		cin >> str;
		int b = str[0] - 'a';

		if (true == arr[a][b])
		{
			result += "T";
		}

		else
		{
			result += "F";
		}
	}

	for (size_t i = 0; i < result.size(); i++)
	{
		cout << result[i] << '\n';
	}

	return 0;
}

//결과
//입출력 부분이 머릿속에 안그려져서 블로그를 슬쩍 보았습니다. 하하.
//그나마 DP보단 감이 오는데 아마 내일이면 아니게 될 거 같습니다. 하하!
