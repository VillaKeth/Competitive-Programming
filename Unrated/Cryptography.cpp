#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream> 
#include <numeric>
#define ll long long
#define ld long double
#define pb push_back
#define cin std::cin
#define cout std::cout
#define endl '\n'
#define vector std::vector
#define pair std::pair
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1e9+7;
const ll MODDY2 = 998244353;
const ll MODDY3 = 1e8;

// crytography
int main()
{
    std::string s, t;
    ll m, c;
    char a, b;
    cin >> s >> t >> m;
    vector<vector<ll>> matrix(128, vector<ll>(128, INT_MAX));
    for(int i = 0; i < 128; i++)
    {
        matrix[i][i] = 0;
    }
    for(int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        matrix[a][b] = std::min(matrix[a][b], c);
    }
    for(int i = 0; i < 128; i++)
    {
        for(int j = 0; j < 128; j++)
        {
            for(int k = 0; k < 128; k++)
            {
                if(matrix[j][i] != INT_MAX && matrix[i][k] != INT_MAX && matrix[j][i]+matrix[i][k] < matrix[j][k])
                {
                    matrix[j][k] = matrix[j][i]+matrix[i][k];
                }
            }
        }
    }
    bool possible = true;
    ll total = 0;
    for(int i = 0; i < s.length(); i++)
    {
        if(matrix[s[i]][t[i]] != INT_MAX)
        {
            total += matrix[s[i]][t[i]];
        }
        else
        {
            possible = false;
            break;
        }
    }
    cout << (possible ? total : -1);
    return 0;
}
