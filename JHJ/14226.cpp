#include <iostream>
#include <queue>
using namespace std;

const int MAX = 1001;
bool visit[MAX][MAX];

int SearchEmojiCount(int start){
    queue<pair<pair<int, int>, int> > q;
    q.push({{1, 0}, 0});
    visit[1][0] = true;

    while(!q.empty()){
        int screen = q.front().first.first;
        int clipboard = q.front().first.second;
        int time = q.front().second;
        q.pop();

        if(screen == start){
            return time;
        }

        if(screen > 0 && screen < MAX){
            if(visit[screen][screen] == false){
                visit[screen][screen] = true;
                q.push({{screen, screen}, time + 1});
            }
            if(visit[screen - 1][clipboard] == false){
                visit[screen - 1][clipboard] = true;
                q.push({{screen - 1, clipboard}, time + 1});
            }
        }
        if(clipboard > 0 && screen + clipboard < MAX){
            if(visit[screen + clipboard][clipboard] == false){
                visit[screen + clipboard][clipboard] = true;
                q.push({{screen + clipboard, clipboard}, time + 1});
            }
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int input;
    cin >> input;
    cout << SearchEmojiCount(input) << '\n';
}