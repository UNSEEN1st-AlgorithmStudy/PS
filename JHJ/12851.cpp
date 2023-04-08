#include <iostream>
#include <queue>

using namespace std;

const int MAX = 100001;
bool isVisited[MAX];
int N, K;
int result = 0;

int search(int N, int K) {
    int count = 0, minCount = 0;
    queue<int> q;
    q.push(N);
    isVisited[N] = true;
    
    while(!q.empty()){
        int queueSize = q.size();
        for(int i = 0; i < queueSize; i++){

            int cur = q.front();
            q.pop();
            isVisited[cur] = true;

            if(minCount > 0 && count == minCount && cur == K){
                result++;
            }
            if(minCount == 0 && cur == K){
                minCount = count;
                result++;
            }
            
            if (cur > 0 && isVisited[cur - 1] == false){
                q.push(cur - 1);
            }
            if (cur < MAX && isVisited[cur + 1] == false){
                q.push(cur + 1);
            }
            if (2 * cur < MAX && isVisited[cur * 2] == false){
                q.push(cur * 2);
            }
        }
        count++;
    }
    return minCount;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> K;
    cout << search(N, K) << '\n';
    cout << result << '\n';
}