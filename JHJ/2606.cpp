#include <iostream>
#include <vector>
using namespace std;

const int MAX = 101;
int numberofComputer = 0;
int virusedComputerCount = 0;
vector<int> edge[MAX];
bool visit[MAX];

void SearchByDfs(int currentPositon){
    visit[currentPositon] = true;
    ++virusedComputerCount;
    for(auto nextPositoin : edge[currentPositon]){
        if(visit[nextPositoin]) continue;
        SearchByDfs(nextPositoin);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> numberofComputer;
    int edgeCount;
    cin >> edgeCount;
    while (edgeCount--){
        int from, to;
        cin >> from >> to;
        edge[from].push_back(to);
        edge[to].push_back(from);
    }
    
    SearchByDfs(1);

    cout << virusedComputerCount - 1 << '\n';
}