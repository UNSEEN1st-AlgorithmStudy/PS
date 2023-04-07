#include <iostream>
#include <algorithm>
using namespace std;

const int moveX[] = { 0, 0, 1, -1 };
const int moveY[] = { 1, -1, 0, 0 };
const int MAX = 501;
int n, m;
int map[MAX][MAX];
bool visit[MAX][MAX];
int answer = -1;

bool IsOut(int y, int x){
    return (y < 0 || x < 0 || y >= n || x >= m);
}

void GetSumFrom(int y, int x, int count, int sum){
    if(count == 4){
        answer = max(answer, sum);
        return;
    }

    for(int i = 0; i < 4; i++){
        int nextY = y + moveY[i];
        int nextX = x + moveX[i];

        if(IsOut(nextY, nextX) || visit[nextY][nextX]) continue;

        visit[nextY][nextX] = true;
        GetSumFrom(nextY, nextX, count + 1, sum + map[nextY][nextX]);
        GetSumFrom(y, x, count + 1, sum + map[nextY][nextX]);
        visit[nextY][nextX] = false;
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            cin >> map[y][x];
        }
    }

    for(int y = 0; y < n; y++){
        for(int x = 0; x < m; x++){
            visit[y][x] = true;
            GetSumFrom(y, x, 1, map[y][x]);
            visit[y][x] = false;
        }
    }

    cout << answer << '\n';
}