#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int MAX_DISTANCE = 999999999;
const int MAX = 20001;
vector<pair<int, int>> edge[MAX];
int distanceFromStart[MAX];
int nodeCount, edgeCount;
int startNode;

void Djikstra(int start){
    priority_queue<pair<int, int>> q;
    q.push({0, start});
    distanceFromStart[start] = 0;

    while(!q.empty()){
        int curDistance = -q.top().first;
        int curPosition = q.top().second;
        q.pop();

        for(auto nextInfo : edge[curPosition]){
            auto nextPos = nextInfo.first;
            auto nextDistnace = nextInfo.second;

            if(distanceFromStart[nextPos] > curDistance + nextDistnace){
                distanceFromStart[nextPos] = curDistance + nextDistnace;
                q.push({-distanceFromStart[nextPos], nextPos});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodeCount >> edgeCount;
    cin >> startNode;
    for(int i = 0; i < edgeCount; i++){
        int from, to, cost;
        cin >> from >> to >> cost;
        edge[from].push_back({to, cost});
    }
    for(int i = 0; i <= nodeCount; i++){
        distanceFromStart[i] = MAX_DISTANCE;
    }

    Djikstra(startNode);

    for(int i = 1; i <= nodeCount; i++){
        if(distanceFromStart[i] == MAX_DISTANCE){
            cout << "INF\n";
            continue;
        }
        cout << distanceFromStart[i] << '\n';
    }
}