#include <algorithm>
#include <iostream>
using namespace std;


const int HOUSE_MAX = 200001;
const int ROAD_MAX = 200001;
int houseNum, roadNum, from, to, cost, costMax = 0, resultCost = 0;
pair<int, pair<int, int>> roads[ROAD_MAX];
int parents[HOUSE_MAX];


int findParent(int x)
{
    if (x == parents[x]) return x;
    return parents[x] = findParent(parents[x]);
}

void merge(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a > b) parents[a] = parents[b];
    else       parents[b] = parents[a];
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    while(true)
    {
        costMax = 0;
        resultCost = 0;
        
        cin >> houseNum >> roadNum;

        if (houseNum == 0 && roadNum == 0) break;
    
        for (int i = 1; i <= houseNum; i++)
            parents[i] = i;

        for (int i = 0; i < roadNum; i++)
        {
            cin >> from >> to >> cost;
            roads[i] = {cost, {from, to}};

            costMax += cost;
        }

        sort(roads, roads + roadNum);

        for (int i = 0; i < roadNum; i++)
        {
            if (findParent(roads[i].second.first) == findParent(roads[i].second.second)) continue;

            merge(roads[i].second.first, roads[i].second.second);
        
            resultCost += roads[i].first;
        }
    
        cout << costMax - resultCost << '\n';
    }
}
