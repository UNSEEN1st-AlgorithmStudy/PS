#include <iostream>
using namespace std;


const int STUFF_COUNT_MAX = 101;
const int WEIGHT_LIMIT_MAX = 100000;

int stuffCount, weightLimit;
int values[STUFF_COUNT_MAX];
int weights[STUFF_COUNT_MAX];
int dp[STUFF_COUNT_MAX][WEIGHT_LIMIT_MAX]; // dp[물건 번호][제한 무게] = 최대 가치


int getMaxValue()
{
    // 제한 무게가 0일 때 초기화
    for (int limit = 0; limit <= weightLimit; limit++)
        dp[0][limit] = 0;

    // 물건 번호가 0일 때 초기화
    for (int i = 0; i <= stuffCount; i++)
        dp[i][0] = 0;

    
    for (int limit = 1; limit <= weightLimit; limit++)
    {
        for (int i = 1; i <= stuffCount; i++)
        {
            int prevMaxValue = dp[i - 1][limit];
            
            if (limit < weights[i]) // 담을 수 없을 경우
            {
                dp[i][limit] = prevMaxValue;
            }
            else // 담을 수 있는 경우
            {
                int curValue = dp[i - 1][limit - weights[i]] + values[i];
                
                dp[i][limit] = max(prevMaxValue, curValue);
            }
        }
    }
    
    return dp[stuffCount][weightLimit];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> stuffCount >> weightLimit;
    
    for (int i = 1; i <= stuffCount; i++)
        cin >> weights[i] >> values[i];
    
    cout << getMaxValue() << '\n';
}
