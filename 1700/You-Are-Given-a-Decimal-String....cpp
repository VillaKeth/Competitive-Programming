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

// you are given a decimal string...
vector<vector<ll>> zeroToNine(ll x, ll y)
{
    vector<vector<ll>> fw(10, vector<ll>(10));
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            if((i <= j && (j-i == x || j-i == y)) || (i > j && ((j+10)-i == x || (j+10)-i == y)))
            {
                fw[i][j] = 1;
            }
            else
            {
                fw[i][j] = INT_MAX;
            }
        }
    }
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            for(int k = 0; k < 10; k++)
            {
                fw[j][k] = std::min(fw[j][k], fw[j][i]+fw[i][k]);
            }
        }
    }
    return fw;
}

int main()
{
    std::string s;
    cin >> s;
    vector<vector<ll>> tempfw;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            tempfw = zeroToNine(i, j);
            bool flag = true;
            int total = 0;
            for(int k = 0; k < s.length()-1; k++)
            {
                if(tempfw[s[k]-'0'][s[k+1]-'0'] == INT_MAX)
                {
                    flag = false;
                    break;
                }
                total += tempfw[s[k]-'0'][s[k+1]-'0'];
            }
            total -= s.length()-1;
            cout << (flag ? total : -1) << ' ';
        }
        cout << endl;
    }
    return 0;
}
