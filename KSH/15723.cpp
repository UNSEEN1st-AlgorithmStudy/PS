#include <iostream>
using namespace std;


const int ALPHABET_MAX = 27;
int n, a, b;
string input;
bool table[ALPHABET_MAX][ALPHABET_MAX];


void floyd()
{
    for (int k = 0; k < ALPHABET_MAX; k++)
    {
        for (int a = 0; a < ALPHABET_MAX; a++)
        {
            if (table[a][k] == false) continue;
            
            for (int b = 0; b < ALPHABET_MAX; b++)
                if (table[a][k] == true && table[k][b] == true)
                    table[a][b] = true;
        }
    }
}


int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    for (int i = 0; i < ALPHABET_MAX; i++)
    {
        for (int j = 0; j < ALPHABET_MAX; j++)
        {
            if (i == j) table[i][j] = true;
            else        table[i][j] = false;
        }
    }
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a = input[0] - 'a';
        
        cin >> input;
        cin >> input;
        b = input[0] - 'a';
        
        table[a][b] = true;
    }
    
    floyd();
    
    cin >> n;
    
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        a = input[0] - 'a';
        
        cin >> input;
        cin >> input;
        b = input[0] - 'a';
        
        if (table[a][b] == true) cout << 'T' << '\n';
        else                     cout << 'F' << '\n';
    }
}
