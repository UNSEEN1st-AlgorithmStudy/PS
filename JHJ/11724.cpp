#include <iostream>
#include <vector>
using namespace std;
const int MAX = 1001;
bool visit[MAX];
vector<int> edge[MAX];
int nodeCount, edgeCount;

void SearchByDFS(int startPoint){
    visit[startPoint] = true;

    for(auto nextPoisition : edge[startPoint]){
        if(visit[nextPoisition])    continue;
        SearchByDFS(nextPoisition);
    }
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> nodeCount >> edgeCount;
    while (edgeCount--){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    
    int connectedCount = 0;
    for(int i = 1; i <= nodeCount; i++){
        if(visit[i])    continue;
        connectedCount++;
        SearchByDFS(i);
    }

    cout << connectedCount << '\n';
}