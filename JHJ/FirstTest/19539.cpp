#include <iostream>
using namespace std;

int n;
int wantedHeight[100001];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int total = 0;
    int total2 = 0;

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> wantedHeight[i];

        total2 += wantedHeight[i] / 2;
        total += wantedHeight[i];
    }

    bool isSuccessful = (total % 3 == 0) && (total / 3 <= total2);
    
    if(isSuccessful){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}