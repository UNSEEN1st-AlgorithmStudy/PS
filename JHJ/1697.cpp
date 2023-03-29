#include <iostream>
#include <queue>
using namespace std;

int subinPosition, brotherPosition;
const int MAX_DISTANCE = 100001;
bool visit[MAX_DISTANCE];

int HideAndSeek(){
    queue<int> q;
    q.push(subinPosition);
    visit[subinPosition] = true;
    int moveCount = 0;

    while(true){
        int qSize = q.size();
        while(qSize--){
            int curPosition = q.front();
            q.pop();

            if(curPosition == brotherPosition)  return moveCount;

            if(curPosition - 1 > -1 && visit[curPosition - 1] == false){
                q.push(curPosition - 1);
                visit[curPosition - 1] = true;
            }     
            if(curPosition + 1 < MAX_DISTANCE && visit[curPosition + 1] == false){
                q.push(curPosition + 1);
                visit[curPosition + 1] = true;
            }            
            if(curPosition * 2 < MAX_DISTANCE && visit[curPosition * 2] == false){
                q.push(curPosition * 2);
                visit[curPosition * 2] = true;
            }
        }
        moveCount++;
    }
    return moveCount;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> subinPosition >> brotherPosition;

    cout << HideAndSeek() << '\n';
}