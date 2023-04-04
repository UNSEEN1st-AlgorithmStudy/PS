#include <iostream>
#include <cstring>
using namespace std;

const int N_MAX = 101;
int arrNum, countNum = 0;

int arr[N_MAX];
int visited[N_MAX];
bool picked[N_MAX];


void DFS(int curNum)
{
    visited[curNum]++;
    int nextNum = arr[curNum];
    
    if (visited[nextNum] > 1) return;
    
    DFS(nextNum);
    
    if (visited[nextNum] > 1 && picked[nextNum] == false)
    {
        countNum++;
        picked[nextNum] = true;
    }
}

void CheckClosedSet()
{
    for (int curNum = 1; curNum <= arrNum; curNum++)
    {
        DFS(curNum);
        memset(visited, 0, N_MAX * sizeof(int));
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> arrNum;
    for (int i = 1; i <= arrNum; i++)
        cin >> arr[i];
    
    CheckClosedSet();
    
    cout << countNum << "\n";
    for (int i = 1; i <= arrNum; i++)
    {
        if (picked[i] == false) continue;
        cout << i << "\n";
    }
}

