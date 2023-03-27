#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int nodeCount, edgeCount, startPosition;
const int NODE_MAX = 1001;
bool visit[NODE_MAX];
int edge[NODE_MAX][NODE_MAX];

void PrintPathByDFS(int startPosition){
    cout << startPosition << " ";
    visit[startPosition] = true;

    for(int nextPosition = 1; nextPosition <= nodeCount; nextPosition++){
        if(edge[startPosition][nextPosition] == false || visit[nextPosition]) continue;
        visit[nextPosition] = true;
        PrintPathByDFS(nextPosition);
    }
}

void PrintPathByBFS(int startPosition){
    queue<int> q;
    q.push(startPosition);
    visit[startPosition] = true;

    while (!q.empty()){
        int curPosition = q.front();
        q.pop();
        cout << curPosition << " ";
        for(int nextPosition = 1; nextPosition <= nodeCount; nextPosition++){
            if(edge[curPosition][nextPosition] == false || visit[nextPosition]) continue;
            visit[nextPosition] = true;
            q.push(nextPosition);
        }
    }
}

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // input
    cin >> nodeCount >> edgeCount >> startPosition;
    while (edgeCount--){
        int startPosition, endPosition;
        cin >> startPosition >> endPosition;
        edge[startPosition][endPosition] = true;
        edge[endPosition][startPosition] = true;
    }

    // solve
    PrintPathByDFS(startPosition);
    cout << '\n';
    memset(visit, false, sizeof(visit));
    PrintPathByBFS(startPosition);
}