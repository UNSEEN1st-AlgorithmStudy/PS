#include <queue>
#include <iostream>
#include <cstring>
using namespace std;
const int MAX_PC = 100, MAX_PATH = 50;
bool wormed[MAX_PC], path[MAX_PATH][MAX_PATH]; // 바이러스에 걸린 컴퓨터, 확인된 경로
int pcCount, connectCount, totalWormedPC;             

void DFS(int node){
    // 해당 노드에 대한 방문 처리
    wormed[node] = true;
    // 이곳과 연결된 노드들 중 방문하지 않은 노드 탐색하기
    for(int i = 1; i <= connectCount; i++)
    {
        if(!wormed[i] && path[node][i])
        {
            totalWormedPC++;
            DFS(i);   // 재귀 호출로 구현
        }
    }
}

int main()
{
    memset(wormed, false, sizeof(wormed)); // false로 초기화
    memset(path, false, sizeof(path));     // false로 초기화
    
    cin >> pcCount; // 컴퓨터의 수
    cin >> connectCount; // 네트워크 상에서 연결된 쌍의 수
    for(int i = 1; i <= connectCount; i++)
    {
        int a,b;
        cin >> a >> b;
        path[a][b] = path[b][a] = true;
    }

    DFS(1);
    cout << totalWormedPC << '\n';
    return 0;
}