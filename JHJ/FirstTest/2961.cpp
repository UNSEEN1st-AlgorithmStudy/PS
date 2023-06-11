#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
pair<int, int> foods[11];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> foods[i].first >> foods[i].second;
    
    int answer = INT32_MAX;
    for(int i = 1; i < (1 << n); i++){
        int sin = 1, ssun = 0;

        for(int j = 0; j < n; j++){
            if(i & (1 << j)){
                sin *= foods[j].first;
                ssun += foods[j].second;
            }
        }
        answer = min(answer, abs(sin - ssun));
    }

    cout << answer << '\n';
}