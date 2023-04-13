#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 126;
const int moveY[] = { 0, 0, 1, -1 };
const int moveX[] = { 1, -1, 0, 0 };
int map[MAX][MAX];
int rupeeMap[MAX][MAX];
int problemNum = 1;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true){
        int n;
        cin >> n;
        if(n == 0)  return 0;

        for(int y = 0; y < n; y++){
            for(int x = 0; x < n; x++){
                cin >> map[y][x];
                rupeeMap[y][x] = INT32_MAX;
            }
        }

        priority_queue<pair<int, pair<int, int>>> q;
        rupeeMap[0][0] = map[0][0];
        q.push({-map[0][0], {0, 0}});

        while(!q.empty()){
            int curRupee = -q.top().first;
            int curY = q.top().second.first;
            int curX = q.top().second.second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nextY = curY + moveY[i];
                int nextX = curX + moveX[i];
                if(nextX < 0 || nextY < 0 || nextX >= n || nextY >= n)  continue;

                int nextRupee = curRupee + map[nextY][nextX];
                if(rupeeMap[nextY][nextX] <= nextRupee) continue;

                rupeeMap[nextY][nextX] = nextRupee;
                q.push({-nextRupee, {nextY, nextX}});
            }
        }
        
        cout << "Problem "<< problemNum << ": " << rupeeMap[n-1][n-1] << '\n';
        ++problemNum;
    }
}