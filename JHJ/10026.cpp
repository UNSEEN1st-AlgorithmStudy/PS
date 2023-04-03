#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int MAX = 101;
const int moveX[] = { 0, 0, 1, -1 };
const int moveY[] = { 1, -1, 0, 0 };
const char R = 'R', G = 'G';

int n;
char map[MAX][MAX];
bool visit[MAX][MAX];

bool IsOut(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= n);
}

void SearchArea(int startY, int startX, bool isRG){
    auto startColor = map[startY][startX];
    bool startRG = (startColor == R || startColor == G);
    queue<pair<int, int>> q;
    q.push({startY, startX});

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];
            if(IsOut(nextY, nextX) || visit[nextY][nextX]) continue;

            if(isRG && startRG){
                if(map[nextY][nextX] != R && map[nextY][nextX] != G)    continue;
                visit[nextY][nextX] = true;
                q.push({nextY, nextX});
                continue;
            }
            if(map[nextY][nextX] == startColor){
                visit[nextY][nextX] = true;
                q.push({nextY, nextX});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int y = 0; y < n; y++)
        for(int x = 0; x < n; x++)
            cin >> map[y][x];
    
    int normalRegionCount = 0;
    int rgRegionCount = 0;

    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(visit[y][x]) continue;
            normalRegionCount++;
            SearchArea(y, x, false);
        }
    }
    memset(visit, false, sizeof(visit));
    for(int y = 0; y < n; y++){
        for(int x = 0; x < n; x++){
            if(visit[y][x]) continue;
            rgRegionCount++;
            SearchArea(y, x, true);
        }
    }

    cout << normalRegionCount << " " << rgRegionCount << '\n';
}