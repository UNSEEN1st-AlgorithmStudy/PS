#include "iostream"
#include "queue"
using namespace std;
const int MAX_NODE = 100001;
bool visit[MAX_NODE];

int SearchBFS(int N, int K)
{
    queue<int> q;
    visit[N] = true;
    q.push(N);
    int cnt = 0;
    while (!q.empty())
    {
        int qSize = q.size();
        for(int i = 0; i < qSize; i++)
        {
            int cur = q.front();
            q.pop();
            if(cur == K)
            {
                return cnt;
            }
            if(cur+1 <= MAX_NODE && !visit[cur+1])
            {
                q.push(cur + 1);
                visit[cur+1] = true;
            }
            if(cur-1 >= 0 && !visit[cur -1])
            {
                q.push(cur - 1);
                visit[cur-1] = true;
            }
            if(cur*2 <= MAX_NODE && !visit[cur*2])
            {
                q.push(cur*2);
                visit[cur*2] = true;
            }
        }
        cnt++;
    }
}

int main()
{
    int N, K;
    cin >> N >> K;
    cout << SearchBFS(N,K);
    return 0;
}