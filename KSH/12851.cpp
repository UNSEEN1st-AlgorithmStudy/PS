#include <iostream>
#include <queue>
using namespace std;

const int MAX_POS = 100000;
int from, to, resultTime = MAX_POS, resultWays = 0;
bool visited[MAX_POS + 1];


void BFS()
{
    // position, time
    queue<pair<int, int>> q;
    q.push({from, 0});
    
    while(q.empty() == false)
    {
        int pos = q.front().first;
        int time = q.front().second;
        q.pop();
        
        visited[pos] = true;
        
        if (time > resultTime) return;
        if (pos == to)
        {
            resultWays++;
            resultTime = time;
            continue;
        }
        
        if (pos - 1 >= 0 && visited[pos - 1] == false)
        {
            q.push({pos - 1, time + 1});
        }
        if (pos + 1 <= MAX_POS && visited[pos + 1] == false)
        {
            q.push({pos + 1, time + 1});
        }
        if (pos * 2 <= MAX_POS && visited[pos * 2] == false)
        {
            q.push({pos * 2, time + 1});
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> from >> to;
    
    BFS();
    
    cout << resultTime << '\n';
    cout << resultWays << '\n';
}
