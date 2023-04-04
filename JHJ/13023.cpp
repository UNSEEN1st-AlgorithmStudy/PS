#include <iostream>
#include <vector>
using namespace std;

const int MAX = 2001;
int n, m;
vector<int> friendship[2001];
bool visit[MAX];
bool haveAnswer = false;

void SearchFriend(int cur, int friendCount){
    visit[cur] = true;
    if(friendCount == 4){
        haveAnswer = true;
        return;
    }
    for(auto nextPos : friendship[cur]){
        if(visit[nextPos])  continue;
        SearchFriend(nextPos, friendCount + 1);
    }
    visit[cur] = false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    while(m--){
        int a, b;
        cin >> a >> b;
        friendship[a].push_back(b);
        friendship[b].push_back(a);
    }

    for(int i = 1; i <= n; i++){
        SearchFriend(i, 0);
        if(haveAnswer){
            cout << "1\n";
            return 0;
        }
    }   
    cout << "0\n";
}