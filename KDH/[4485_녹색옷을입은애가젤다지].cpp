#include <iostream>
#include <vector>
#include <queue>
#include <climits>
#define endl "\n"
using namespace std;

struct Pos
{
	int r, c;
	bool IsValid(int n) const { return  (r >= 0 && c >= 0 && r < n && c < n); }
};
struct Path
{
	Pos To;
	int Cost;
};
struct PathComp
{
	bool operator() (const Path& A, const Path& B) { return (A.Cost > B.Cost); }
};

const int dr[4] = {-1, 1, 0, 0};
const int dc[4] = {0, 0, -1, 1};

int SizeOfCave;
int Cave[128][128];
int Rupee[128][128];
priority_queue< Path, vector<Path>, PathComp > MinHeap;


static void InitCave(const int Size);
static void Zelda(const int Level, const int Size);
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	for(int level = 1 ; cin >> SizeOfCave && SizeOfCave != 0 ; level++)
		Zelda(level, SizeOfCave);
	return 0;
}


void InitCave(int Size)
{
	for (int r = 0 ; r < Size ; r++)
	{
		for (int c = 0 ; c < Size ; c++)
		{
			cin >> Cave[r][c];
			Rupee[r][c] = INT_MAX;
		}
	}
}

void Zelda(const int Level, const int Size)
{
	InitCave(Size);
	
	MinHeap.push({{0, 0}, Cave[0][0]});
	while (MinHeap.size())
	{
		int CurrCost = MinHeap.top().Cost;
		Pos CurrPos = MinHeap.top().To;
		MinHeap.pop();

		for (int i = 0 ; i < 4 ; i++)
		{
			Pos NextPos = {CurrPos.r + dr[i], CurrPos.c + dc[i]};
			if (NextPos.IsValid(Size) == false)
				continue;

			int NextCost = Cave[NextPos.r][NextPos.c] + CurrCost;
			if (Rupee[NextPos.r][NextPos.c] <= NextCost)
				continue;
			
			Rupee[NextPos.r][NextPos.c] = NextCost;
			MinHeap.push({NextPos, NextCost});
		}
	}
	cout << "Problem " << Level << ": " << Rupee[Size-1][Size-1] << endl;
}
