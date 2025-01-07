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
const ll MODDY = 1000000007;
const ll MODDY2 = 998244353;

// constanze's machine
ll dfs(std::string& s, vector<vector<vector<ll>>>& dp, ll index, ll n, ll u)
{
    if(index == s.length())
    {
        return 0;
    }
    if(dp[index][n][u] != -1)
    {
        return dp[index][n][u];
    }
    ll skip = 0;
    ll taken = 0;
    ll takeu = 0;
    ll tempn = n;
    ll tempu = u;
    if(s[index] != 'n')
    {
        tempn = 0;
    }
    else
    {
        tempn++;
        if(tempn == 2)
        {
            taken = (1+dfs(s, dp, index+1, 0, u))%MODDY;
            tempn--;
        }
    }
    if(s[index] != 'u')
    {
        tempu = 0;
    }
    else
    {
        tempu++;
        if(tempu == 2)
        {
            taken = (1+dfs(s, dp, index+1, n, 0))%MODDY;
            tempu--;
        }
    }
    skip = dfs(s, dp, index+1, tempn, tempu);
    dp[index][n][u] = (skip+taken+takeu)%MODDY;
    return dp[index][n][u];
}

int main()
{
    std::string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
            cout << 0;
            return 0;
        }
    }
    vector<vector<vector<ll>>> dp(s.length(), vector<vector<ll>>(2, vector<ll>(2, -1)));
    cout << (dfs(s, dp, 0, 0, 0)+1)%MODDY;
    return 0;
}
