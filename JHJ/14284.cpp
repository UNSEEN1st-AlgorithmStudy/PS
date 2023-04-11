#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX_DISTANCE = 2100000000;
const int MAX = 5001;
int nodeCount, edgeCount;
int start, target;
vector<pair<int, int>> edge[MAX];
int distanceFromStart[MAX];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodeCount >> edgeCount;
    for(int i = 0; i < edgeCount; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        edge[from].push_back({to, cost});
        edge[to].push_back({from, cost});
    }
    cin >> start >> target;

    for(int i = 0; i <= nodeCount; i++)
        distanceFromStart[i] = MAX_DISTANCE;

    priority_queue<pair<int, int>> q;
    q.push({0, start});
    distanceFromStart[start] = 0;

    while(!q.empty()){
        int curDistance = -q.top().first;
        int curPosition = q.top().second;
        q.pop();

        if(curPosition == target){
            cout << curDistance << '\n';
            return 0;
        }

        for(auto edgeInfo : edge[curPosition]){
            int nextPosition = edgeInfo.first;
            int nextDistance = edgeInfo.second + curDistance;

            if(distanceFromStart[nextPosition] <= nextDistance)
                continue;

            distanceFromStart[nextPosition] = nextDistance;
            q.push({-nextDistance, nextPosition});
        }
    }
}