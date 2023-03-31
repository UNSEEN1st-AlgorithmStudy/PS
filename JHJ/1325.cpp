#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAX = 10001;
bool hacked[MAX];
vector<int> trustCom[MAX];
vector<int> answerComputer;

int comCount, edgeCount;
int curHackCount = 0;

void HackTrustComputer(int startCom){
    hacked[startCom] = true;
    curHackCount++;

    for(auto nextCom : trustCom[startCom]){
        if(hacked[nextCom]) continue;
        HackTrustComputer(nextCom);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int maxHackCount = -1;
    cin >> comCount >> edgeCount;
    while (edgeCount--){
        int comA, comB;
        cin >> comA >> comB;
        trustCom[comB].push_back(comA);
    }

    for(int i = 1; i <= comCount; i++){
        memset(hacked, false, sizeof(hacked));
        curHackCount = 0;
        HackTrustComputer(i);
        if(curHackCount == maxHackCount){
            answerComputer.push_back(i);
        }
        else if(maxHackCount < curHackCount){
            maxHackCount = curHackCount;
            answerComputer.clear();
            answerComputer.push_back(i);
        }
    }

    for(auto com : answerComputer){
        cout << com << " ";
    }
    cout << '\n';
}