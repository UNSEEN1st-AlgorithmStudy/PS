#include <iostream>
#include <queue>
using namespace std;

const int MAX_SCREEN = 2000;
int goalScreen, goaltime;
bool visited[MAX_SCREEN + 1][MAX_SCREEN + 1];


void BFS()
{
    // { time, { screen, clipboard }}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, { 1, 0 }});
    visited[1][0] = true;
    
    while(q.empty() == false)
    {
        int time = q.front().first;
        int screen = q.front().second.first;
        int clipboard = q.front().second.second;
        q.pop();

        if (screen == goalScreen)
        {
            goaltime = time;
            return;
        }
        
        if (screen > 0 && screen < MAX_SCREEN)
        {
            //1번 & 3번 조건
            if (visited[screen][screen] == false)
            {
                visited[screen][screen] = true;
                q.push({time + 1, {screen, screen}});
            }
 
            if (visited[screen - 1][clipboard] == false)
            {
                visited[screen - 1][clipboard] = true;
                q.push({time + 1, {screen - 1, clipboard}});
            }
        }
 
        if (clipboard > 0 && screen+clipboard < MAX_SCREEN)
        {
            if (visited[screen + clipboard][clipboard] == false)
            {
                visited[screen + clipboard][clipboard] = true;
                q.push({time + 1, {screen + clipboard, clipboard}});
            }
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> goalScreen;
    
    BFS();
    
    cout << goaltime << '\n';
}
