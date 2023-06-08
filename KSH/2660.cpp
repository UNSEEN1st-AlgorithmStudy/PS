#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


const int INF = 1e9;
const int MEMBER_COUNT_MAX = 51;
int memberCount, inputA, inputB;
int points[MEMBER_COUNT_MAX][MEMBER_COUNT_MAX];
int captainPoint = INF;
vector<int> captains;


void floyd()
{
    for (int k = 1; k <= memberCount; k++)
    {
        for (int a = 1; a <= memberCount; a++)
        {
            if (points[a][k] == INF) continue;
            
            for (int b = 1; b <= memberCount; b++)
                points[a][b] = min(points[a][b], points[a][k] + points[k][b]);
        }
    }
}

void searchCaptains()
{
    for (int a = 1; a <= memberCount; a++)
    {
        int curMax = 0;        
        for (int b = 1; b <= memberCount; b++)
            curMax = max(curMax, points[a][b]);

        if (curMax < captainPoint)
        {
            captainPoint = curMax;
            captains.clear();
            captains.push_back(a);
        }
        else if (curMax == captainPoint)
        {
            captains.push_back(a); 
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> memberCount;
    
    for (int a = 1; a <= memberCount; a++)
        for (int b = 1; b <= memberCount; b++)
            points[a][b] = (a == b) ?  0 : INF;

    while(cin >> inputA >> inputB)
    {
        if (inputA == -1 && inputB == -1) break;
        
        points[inputA][inputB] = 1;
        points[inputB][inputA] = 1;
    }

    floyd();
    searchCaptains();

    sort(captains.begin(), captains.end());

    cout << captainPoint << ' ' << captains.size() << '\n';
    for (int i = 0; i < captains.size(); i++)
        cout << captains[i] << ' ';
    cout << '\n';
}