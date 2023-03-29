#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int STEP_MAX = 3;
const int NODE_MAX = 100000;
int startNode, endNode;
bool visited[NODE_MAX + 1];


int FindTheFastestWay()
{
    queue<pair<int, int>> q;
    q.push({startNode, 0});
    
    while(q.empty() == false)
    {
        int curNode = q.front().first;
        int curCount = q.front().second;
        q.pop();

        if (curNode == endNode) return curCount;
        
        vector<int> steps = {curNode - 1, curNode + 1, curNode * 2};
        
        for (int i = 0; i < STEP_MAX; i++)
        {
            if (steps[i] < 0 || steps[i] > NODE_MAX || visited[steps[i]] == true) continue;
            
            visited[steps[i]] = true;
            q.push({steps[i], curCount + 1});
        }
    }
    
    return -1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> startNode >> endNode;
    
    cout << FindTheFastestWay();
}
