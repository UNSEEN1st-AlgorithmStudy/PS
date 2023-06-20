#include<iostream>
#include<vector>
#include <tuple>
#include<algorithm>
// #include<string>
using namespace std;
struct DisjointSet{
    vector<int>parent;
    DisjointSet(int N):parent(N){
        for(int i =0; i<N; ++i){
            parent[i] = i;
        }
    }
    int find(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u]=find(parent[u]);
    }
    void merge(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return;
        parent[u] = v;
    }
    bool isSameTree(int u, int v){
        u = find(u);
        v = find(v);
        if(u==v) return true;
        else return false;
    }
};
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    cin>>V>>E;
    DisjointSet d(V+1);
    vector<pair<int, pair<int, int> > > Vs;
    //start, end, cost
    for(int i =0; i<E; ++i){
        int start, end, cost;
        cin>>start>>end>>cost;
        Vs.push_back(make_pair(cost, make_pair(start, end)));
    }
    //Vs cost를 기준으로 정렬하기
    sort(Vs.begin(), Vs.end());
    long long result = 0;
    int mergeCount = 0;
    for(int i =0; i<Vs.size(); ++i){
        int start= Vs[i].second.first;
        int end = Vs[i].second.second;
        if(!d.isSameTree(start ,end )){
            d.merge(start, end);
            result+=Vs[i].first;
            mergeCount +=1;
        }
        if(mergeCount==(V-1)) break;
    }
    cout<<result;
}
