#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int moveY[] = { 0, 0, 1, -1 };
const int moveX[] = { 1, -1, 0, 0 };
const int MAX = 26;
int map[MAX][MAX];
bool visit[MAX][MAX];
int mapSize;

bool IsOut(int y, int x){
    return (x < 0 || y < 0 || x >= mapSize || y >= mapSize);
}

int SearchNearbyHouse(int startY, int startX){
    int houseCount = 1;
    queue<pair<int, int>> q;
    q.push({startY, startX});
    visit[startY][startX] = true;

    while (!q.empty()){
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
            int nextY = curY + moveY[i];
            int nextX = curX + moveX[i];
            if(IsOut(nextY, nextX)) continue;
            if(visit[nextY][nextX] || map[nextY][nextX] != 1)   continue;

            visit[nextY][nextX] = true;
            q.push({nextY, nextX});
            houseCount++;
        }
    }
    return houseCount;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> mapSize;
    for(int y = 0; y < mapSize; y++){
        string row;
        cin >> row;
        for(int x = 0; x < row.size(); x++){
            map[y][x] = row[x] - '0';
        }
    }

    vector<int> houses;
    for(int y = 0; y < mapSize; y++){
        for(int x = 0; x < mapSize; x++){
            if(visit[y][x] || map[y][x] != 1)   continue;
            auto houseCount = SearchNearbyHouse(y, x);
            houses.push_back(houseCount);
        }
    }

    sort(houses.begin(), houses.end());
    cout << houses.size() << '\n';
    for(int i = 0; i < houses.size(); i++){
        cout << houses[i] << '\n';
    }
}