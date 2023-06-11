#include <iostream>
using namespace std;

const int INF = 1e9;
const int BUILDING_MAX = 251;
int buildingNum, wayNum, questionNum;
int from, to;
bool isTwoWay;
int table[BUILDING_MAX][BUILDING_MAX];


void floyd()
{
    for (int k = 1; k <= buildingNum; k++)
    {
        for (int a = 1; a <= buildingNum; a++)
        {
            if (table[a][k] == INF) continue;
            
            for (int b = 1; b <= buildingNum; b++)
               table[a][b] = min(table[a][b], table[a][k] + table[k][b]);
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> buildingNum >> wayNum;
    
    for (int a = 1; a <= buildingNum; a++)
    {
        for (int b = 1; b <= buildingNum; b++)
        {
            if (a == b) table[a][b] = 0;
            else        table[a][b] = INF;
        }
    }
    
    for (int i = 0; i < wayNum; i++)
    {
        cin >> from >> to >> isTwoWay;
        
        table[from][to] = 0;
        table[to][from] = (isTwoWay == true) ? 0 : 1;
    }
    
    floyd();
    
    cin >> questionNum;
    
    for (int i = 0; i < questionNum; i++)
    {
        cin >> from >> to;
        cout << table[from][to] << '\n';
    }
}
