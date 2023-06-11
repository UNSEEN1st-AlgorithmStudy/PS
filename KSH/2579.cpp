#include <iostream>
using namespace std;


const int STEP_COUNT_MAX = 301;
int stepCount;
int stepPoints[STEP_COUNT_MAX];
int dp[STEP_COUNT_MAX];



int getMaxPointOfSteps()
{
    dp[0] = stepPoints[0];
    dp[1] = max(stepPoints[0] + stepPoints[1], stepPoints[1]);
    dp[2] = max(stepPoints[0] + stepPoints[2], stepPoints[1] + stepPoints[2]);
    
    for (int i = 3; i < stepCount; i++)
        dp[i] = max(dp[i - 2] + stepPoints[i], dp[i - 3] + stepPoints[i - 1] + stepPoints[i]);
    
    return dp[stepCount - 1];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> stepCount;
    
    for (int i = 0; i < stepCount; i++)
        cin >> stepPoints[i];
    
    cout << getMaxPointOfSteps() << '\n';
}
