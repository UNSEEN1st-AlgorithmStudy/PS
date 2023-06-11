//17:16
#include<iostream>
#include<vector>
#include<limits>
#include<queue>
using namespace std;
int V, E, K;
int MAX = numeric_limits<int>::max();
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>V>>E>>K;
    vector<vector<pair<int, int>>>graph(V+1, vector<pair<int, int>>()); //시작점 = 도착점, weight
    int Dijkstra[V+1];

    for(int i = 0; i<E; ++i){
        int start, end, w;
        cin>>start>>end>>w;
        graph[start].push_back({end, w});
    }
    for(int i = 0; i<=V; ++i){
        Dijkstra[i] = MAX;
    }

    priority_queue<pair<int, int>> q; //시간 순으로 정렬, 시간, 출발지
    Dijkstra[K] = 0;
    q.push({0, K});
    while(!q.empty()){
        int nowNode = q.top().second;
        int nowTime = -q.top().first;
        q.pop();

        if(nowTime>Dijkstra[nowNode]) continue;

        for(auto a: graph[nowNode]){
            int nextNode = a.first;
            int nextTime = a.second;
            if(nextTime+nowTime<Dijkstra[nextNode]){
                Dijkstra[nextNode] = nextTime+nowTime;
                q.push({-Dijkstra[nextNode], nextNode});
            }
        }
    }
    for(int i = 1; i<=V; ++i){
        if(Dijkstra[i]==MAX){
            cout<<"INF\n";
        }
        else{
            cout<<Dijkstra[i]<<'\n';
        }
    }

}
//17:35
