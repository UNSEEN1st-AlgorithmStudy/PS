#include <iostream>
#include <queue>
using namespace std;
using pair_t = pair<int, int>; // <Position, Seconds>

int SubinPos, BrotherPos;
bool Visited[100001];

bool GetNextPos(const pair_t& InCurrentPosition, pair_t& OutNextPosition);

int main()
{
	queue<pair_t> PathQueue;
	cin >> SubinPos >> BrotherPos;

	if (BrotherPos <= SubinPos)
		cout << SubinPos - BrotherPos << endl;
	else if ( 50000 < SubinPos )
		cout << BrotherPos - SubinPos << endl;
	else {
		pair_t NextPos = make_pair(SubinPos, 0);
		PathQueue.push(NextPos);
		Visited[NextPos.first] = true;
		if (NextPos.first == BrotherPos)
        {
	        std::cout << NextPos.second << std::endl;
            return (0);
        }

		pair_t TargetPos;
		while (PathQueue.size())
		{
			TargetPos = PathQueue.front();
			PathQueue.pop();
			for (int i = 0 ; i < 3 ; i ++)
			{
				if( GetNextPos(TargetPos, NextPos) )
				{
					if (NextPos.first == BrotherPos)
					{
						std::cout << NextPos.second << std::endl;
						return (0);
					}
					PathQueue.push(NextPos);
					Visited[NextPos.first] = true;
				}
			}
		}
	}
}

bool GetNextPos(const pair_t& In, pair_t& Out)
{
	if (0 != In.first && false == Visited[In.first - 1])
	{
		Out.first = In.first - 1;
	}
	else if (100000 != In.first && false == Visited[In.first + 1])
	{
		Out.first = In.first + 1;
	}
	else if (In.first <= 50000 && false == Visited[2 * In.first])
	{
		Out.first = In.first * 2;
	}
	else
		return (false);
	Out.second = In.second + 1;
	return (true);
}
