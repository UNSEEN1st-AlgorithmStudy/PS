#include <iostream>
#include <vector>
using namespace std;

const int MAX_NUM = 500;
const int MAX_STEP = 3;
const int MAX_ROT = 4;

int rowNum, colNum, maxSum;
int paper[MAX_NUM][MAX_NUM];

vector<pair<int, int>> steps =
{
    {0, 1}, {0, 2}, {0, 3}, // poly 1
    {1, 0}, {0, 1}, {1, 1}, // poly 2
    {1, 0}, {2, 0}, {2, 1}, // poly 3
    {1, 0}, {1, 1}, {2, 1}, // poly 4
    {0, 1}, {0, 2}, {1, 1}, // poly 5
    
    // flip poly 3, 4
    {1, 0}, {2, 0}, {2, -1},
    {1, 0}, {1, -1}, {2, -1},
};

bool CanGo(int row, int col)
{
    return row >= 0 && col >= 0 && row < rowNum && col < colNum;
}

void Rotate90Right()
{
    for (pair<int, int>& step : steps)
    {
        int temp = step.first;
        step.first = step.second;
        step.second = temp;

        step.first = -step.first;
    }
}

void CheckAllPolys(int row, int col)
{
    for (int rot = 0; rot < MAX_ROT; rot++)
    {
        int curSum = paper[row][col];

        for (int i = 0; i < steps.size(); i++)
        {
            int r = row + steps[i].first;
            int c = col + steps[i].second;

            if (CanGo(r, c) == false)
            {
                i = ((i / MAX_STEP) + 1) * MAX_STEP - 1;
                curSum = paper[row][col];
                continue;
            }

            curSum += paper[r][c];

            if ((i + 1) % MAX_STEP == 0)
            {
                maxSum = (maxSum < curSum) ? curSum : maxSum;
                curSum = paper[row][col];
            }
        }

        Rotate90Right();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> rowNum >> colNum;
  
    for (int r = 0; r < rowNum; r++)
        for (int c = 0; c < colNum; c++)
            cin >> paper[r][c];

    
    for (int r = 0; r < rowNum; r++)
        for (int c = 0; c < colNum; c++)
            CheckAllPolys(r, c);

    cout << maxSum << '\n';
}
