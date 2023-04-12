#include <iostream>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

const int MAX = 50001;
int nodeCount, edgeCount;
vector<pair<int, int>> edge[MAX];
int DistnaceFromStart[MAX];

void Djikstra(int start){
    for(int i = 0; i <= nodeCount; i++){
        DistnaceFromStart[i] = INT32_MAX;
    }

    priority_queue<pair<int, int>> q;
    q.push({0, start});
    DistnaceFromStart[start] = 0;

    while(!q.empty()){
        int curDistance = -q.top().first;
        int curPosition = q.top().second;
        q.pop();

        for(auto edgeInfo : edge[curPosition]){
            int nextPosition = edgeInfo.first;
            int nextDistance = edgeInfo.second + curDistance;
            if(nextDistance >= DistnaceFromStart[nextPosition])  continue;

            DistnaceFromStart[nextPosition] = nextDistance;
            q.push({-nextDistance, nextPosition});
        }
    }
}

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

    Djikstra(1);

    cout << DistnaceFromStart[nodeCount] << '\n';
}