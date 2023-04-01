#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

const int MAX = 1001;
int row, col;
int box[MAX][MAX];
queue<pair<int, int>> q;

const int moveY[] = { 0, 0, 1, -1 };
const int moveX[] = { 1, -1, 0, 0 };

bool IsOut(int y, int x){
    return (y < 0 || x < 0 || x >= row || y >= col);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> row >> col;
    for(int y = 0; y < col; y++){
        for(int x = 0; x < row; x++){
            cin >> box[y][x];
            if(box[y][x] == 1)
                q.push({y, x});
        }
    }

    while(!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        int curDay = box[curY][curX];
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];
            if(IsOut(nextY, nextX)) continue;
            if(box[nextY][nextX] != 0)  continue;

            box[nextY][nextX] = curDay + 1;
            q.push({nextY, nextX});
        }
    }

    int answer = 1;
    for(int y = 0; y < col; y++){
        for(int x = 0; x < row; x++){
            if(box[y][x] == 0){
                cout << "-1\n";
                return 0;
            }
            answer = max(answer, box[y][x]);
        }
    }

    cout << answer - 1 << '\n';

}