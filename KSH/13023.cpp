#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int FRIEND_MAX = 5;
const int PERSON_MAX = 2000;

int personNum, connectionNum, friendOne, friendTwo;
bool answer = false;

vector<int> friends[PERSON_MAX];
bool visited[PERSON_MAX];


void DFS(int startFriend, int friendCount)
{
    if (friendCount >= FRIEND_MAX)
    {
        answer = true;
        return;
    }
    
    visited[startFriend] = true;
    
    for (auto curFriend : friends[startFriend])
    {
        if (visited[curFriend] == true) continue;
    
        DFS(curFriend, friendCount + 1);
    }
    
    visited[startFriend] = false;
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> personNum >> connectionNum;
    
    for (int i = 0; i < connectionNum; i++)
    {
        cin >> friendOne >> friendTwo;
        friends[friendOne].push_back(friendTwo);
        friends[friendTwo].push_back(friendOne);
    }
    
    for (int i = 0; i < personNum; i++)
    {
        DFS(i, 1);
        
        if (answer == true)
        {
            cout << 1;
            return 0;
        }
        memset(visited, false, personNum * sizeof(bool));
    }
    cout << 0;
}
