#include <iostream>
#include <string>
using namespace std;
const int MAX = 30;
const int INF = 1000001;
int graph[MAX][MAX];
int N, M;

void Init()
{
    for(int i = 0; i < MAX; i++)
    {
        for(int j = 0; j < MAX; j++)
        {
            if( i == j ) graph[i][j] = 0;
            else graph[i][j] = INF;
        }
    }
}

int main()
{
    cin >> N;
    cin.ignore();
    Init();

    for(int i = 0; i < N; i++)
    {
        string thesis;
        getline(cin, thesis);
        graph[thesis[0] - 'a'][thesis[thesis.size() - 1] - 'a'] = 1; // -'a' 를 해주면 각 알파벳 순서상의 숫자값을 반환 받을 수 있다. 마지막은 널값이므로 -1 을 진행해준다.
    }

    for(int via = 0; via < MAX; via++)
    {
        for(int from = 0; from < MAX; from++)
        {
            for(int to = 0; to < MAX; to++)
            {
                if(graph[from][to] > graph[from][via] + graph[via][to])
                    graph[from][to] = graph[from][via] + graph[via][to];
            }
        }
    }

    cin >> M;
    cin.ignore();
    
    for(int i = 0; i < M; i++)
    {
        string ans;
        getline(cin, ans);

        if(graph[ans[0] - 'a'][ans[ans.size()-1]-'a'] != INF) cout << "T" << '\n';
        else cout << "F" << '\n';
    }
    return 0;
}