#include <iostream>
#include <vector>
using namespace std;

int n, m;
int lessonLength[100001];
int totalLength = 0;
int minCdLength = INT32_MAX;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> lessonLength[i];
        totalLength += lessonLength[i];
    }

    int left = 1;
    int right = totalLength;

    while (left <= right){
        int curLength = (left + right) / 2;
        int bluerayAmount = curLength;
        int cdCount = 1;
        bool canPossess = true;

        for(int i = 0; i < n; i++){            
            if(lessonLength[i] > curLength){
                canPossess = false;
                break;
            }
            if(bluerayAmount < lessonLength[i]){
                bluerayAmount = curLength;
                bluerayAmount -= lessonLength[i]; // !
                cdCount += 1;
            }
            else{
                bluerayAmount -= lessonLength[i];
            }
        }

        if(canPossess == false || cdCount > m){
            left = curLength + 1;
        }
        else{
            minCdLength = curLength;
            right = curLength - 1;
        }
    }
    
    cout << minCdLength << '\n';
}