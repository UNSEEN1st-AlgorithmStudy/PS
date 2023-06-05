#include <iostream>
using namespace std;


const int INF = 1e9;
const int CITY_COUNT_MAX = 101;
int cityCount, busCount;
int from, to, cost;
int costs[CITY_COUNT_MAX][CITY_COUNT_MAX];


void printCostTable()
{
    for (int i = 1; i <= cityCount; i++)
    {
        for (int j = 1; j <= cityCount; j++)
        {
            if (costs[i][j] == INF) cout << 0 << ' ';
            else                    cout << costs[i][j] << ' ';
        }
        cout << endl;
    }
}

void findMinCosts()
{
    for (int k = 1; k <= cityCount; k++)
    {
        for (int a = 1; a <= cityCount; a++)
        {
            if (costs[a][k] == INF) continue;
            
            for (int b = 1; b <= cityCount; b++)
                costs[a][b] = min(costs[a][b], costs[a][k] + costs[k][b]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> cityCount >> busCount;
    
    for (int i = 1; i <= cityCount; i++)
        for (int j = 1; j <= cityCount; j++)
            costs[i][j] = (i == j) ? 0 : INF;
    
    for (int i = 0; i < busCount; i++)
    {
        cin >> from >> to >> cost;
        costs[from][to] = min(costs[from][to], cost);
    }
    
    findMinCosts();
    printCostTable();
}
