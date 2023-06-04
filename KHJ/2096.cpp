#include <iostream>
#include <algorithm>
using namespace std;
int max_score[3] = {0};
int min_score[3] = {0};
int N;
int main()
{
    cin >> N;


    for (int i = 0; i < N; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        int temp_max[3];
        temp_max[0] = max(max_score[0], max_score[1]) + a;
        temp_max[1] = max(max(max_score[0], max_score[1]), max_score[2]) + b;
        temp_max[2] = max(max_score[1], max_score[2]) + c;

        int temp_min[3];
        temp_min[0] = min(min_score[0], min_score[1]) + a;
        temp_min[1] = min(min(min_score[0], min_score[1]), min_score[2]) + b;
        temp_min[2] = min(min_score[1], min_score[2]) + c;

        for (int j = 0; j < 3; j++) {
            max_score[j] = temp_max[j];
            min_score[j] = temp_min[j];
        }
    }

    cout << max(max(max_score[0], max_score[1]), max_score[2]) << ' ';
    cout << min(min(min_score[0], min_score[1]), min_score[2]) << '\n';

    return 0;
}