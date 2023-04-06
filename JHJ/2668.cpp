#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 101;
vector<int> answer;
bool visit[MAX];
int arr[MAX];

void DoSearchCycle(int start, int cur){
    if(visit[cur]){
        if(start == cur)
            answer.push_back(start);
    }
    else {
        visit[cur] = true;
        DoSearchCycle(start, arr[cur]);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    for(int i = 1; i <= n; i++){
        memset(visit, false, sizeof(visit));
        DoSearchCycle(i, i);
    }

    cout << answer.size() << '\n';
    for(auto num : answer){
        cout << num << '\n';
    }
}