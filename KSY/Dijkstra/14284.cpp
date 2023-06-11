#include<iostream>
#include<vector>
#include<queue>
#include<limits>
using namespace std;
int MAX = numeric_limits<int>::max();
int s, t;
int n, m;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin>>n>>m;
    vector<vector<pair<int, int>>> graph(n+1, vector<pair<int, int>>());
    for(int i = 0; i<m; ++i){
        int a, b, c;
        cin>>a>>b>>c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }
    cin>>s>>t;
    int arr[n+1];
    for(int i = 1; i<=n; ++i){
        arr[i] = MAX;
    }
    priority_queue<pair<int, int>> q; //time, node
    q.push({0, s});
    while(!q.empty()){
        int nowNode = q.top().second;
        int nowCost = -q.top().first;
        q.pop();
        if(nowCost>arr[nowNode]) continue;
        for(auto a : graph[nowNode]){
            int nextNode = a.first;
            int nextCost = a.second;
            if(nextCost+nowCost<arr[nextNode]){
                arr[nextNode] = nextCost+nowCost;
                q.push({-arr[nextNode], nextNode});
            }
        }

    }

    cout<<arr[t];
}
