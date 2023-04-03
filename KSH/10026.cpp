#include <iostream>
#include <cstring>
using namespace std;

const int N_MAX = 100;
const char R = 'R';
const char B = 'B';
const char G = 'G';
const int STEP_MAX = 4;
const int steps[] = { 0, 0, 1, -1 };

int areaNum, areaCount;
bool isRedSameAsGreen;
char area[N_MAX][N_MAX];
bool visited[N_MAX][N_MAX];


bool IsSameColor(char a, char b)
{
    if (isRedSameAsGreen && (a == R || a == G) && (b == R || b == G)) return true;
    return a == b;
}

bool CanGo(int r, int c)
{
    return r >= 0 && c >= 0 && r < areaNum && c < areaNum;
}

void DFS(int row, int col, char color)
{
    visited[row][col] = true;
    
    for (int i = 0; i < STEP_MAX; i++)
    {
        int r = row + steps[i];
        int c = col + steps[STEP_MAX - i - 1];
        
        if (CanGo(r, c) == false || IsSameColor(color, area[r][c]) == false || visited[r][c] == true) continue;
        
        DFS(r, c, area[r][c]);
    }
}

void CountArea()
{
    areaCount = 0;
    
    for (int r = 0; r < areaNum; r++)
    {
        for (int c = 0; c < areaNum; c++)
        {
            if (visited[r][c] == true) continue;
            
            areaCount++;
            DFS(r, c, area[r][c]);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> areaNum;
    
    for (int r = 0; r < areaNum; r++)
        cin >> area[r];
    
    
    isRedSameAsGreen = false;
    CountArea();
    cout << areaCount << " ";
    
    for (int r = 0; r < areaNum; r++)
        memset(visited[r], false, areaNum * sizeof(bool));
    
    
    isRedSameAsGreen = true;
    CountArea();
    cout << areaCount;
}

