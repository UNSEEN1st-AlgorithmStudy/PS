﻿#include <iostream>
#include <vector>
using namespace std;
vector<int> DP;
int N;

    // 가로 막대인 2x1 타일은 항상 가로 세로 두칸을 차지한다. (2x2 즉, 4칸을 차지한다.)
    // 세로 막대인 1X2 타일은 유동적이게 놓을 수 있다. 모든 직사각형 크기를 세로 막대로 채울 수 있다.
    // N-1 에서 N 으로 1 증가하면 세로 긴타일을 하나를 놓을 수 있다.
    // N-2 에서 N 으로 2 증가하면 가로로 긴타일 두개를 놓을 수 있다. (세로 긴 타일 두개는 N-1에서 이미 진행하였다.)
    // 어렵게 생각할거없다. 늘어난 칸에 대한 경우의 수는 미리 계산된 경우의 수에서 더하기만 하면된다.
    // 2x1 은 2x1 단 1개, 2x2는 2x1 * 2 혹은 2x1 * 2 해서 2개, 2x3 은 다시 2x1 1개 추가되어서 앞쪽 경우의수 2개에서 1개만 더하면 3개가 된다!

int main()
{
    cin >> N; // 직사각형 가로 크기
    DP.push_back(1);
    DP.push_back(2);
    for(int i = 2; i < N; i++)
    {
        DP.push_back((DP[i-2]+DP[i-1])%10007);
    }
    cout << DP[N-1];
}