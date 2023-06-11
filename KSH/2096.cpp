#include <iostream>
using namespace std;

const int ROW_COUNT_MAX = 100001;
int rowCount;
int points[3];
int dpMax[3];
int dpMin[3];
int maxPoint, minPoint;
int tmp0, tmp1, tmp2;


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> rowCount;

    dpMax[0] = dpMax[1] = dpMax[2] = 0;
    dpMin[0] = dpMin[1] = dpMin[2] = 0;
    
    for (int i = 0; i < rowCount; i++)
    {
        cin >> points[0] >> points[1] >> points[2];
        
        tmp0 = dpMax[0];
        tmp1 = dpMax[1];
        tmp2 = dpMax[2];
 
        dpMax[0] = max(tmp0, tmp1) + points[0]; 
        dpMax[1] = max(max(tmp0, tmp1), tmp2) + points[1];
        dpMax[2] = max(tmp1, tmp2) + points[2];
 
        tmp0 = dpMin[0];
        tmp1 = dpMin[1];
        tmp2 = dpMin[2];
 
        dpMin[0] = min(tmp0, tmp1) + points[0]; 
        dpMin[1] = min(min(tmp0, tmp1), tmp2) + points[1];
        dpMin[2] = min(tmp1, tmp2) + points[2];
    }

    cout << max(max(dpMax[0], dpMax[1]), dpMax[2]) << ' ' << min(min(dpMin[0], dpMin[1]), dpMin[2]) << '\n';
}