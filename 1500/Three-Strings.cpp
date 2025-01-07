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

// three strings
ll t;
std::string a, b, c;

ll dfs(vector<vector<ll>>& dp, ll aIndex, ll bIndex, ll cIndex)
{
    if(cIndex == c.length())
    {
        return 0;
    }
    
    if(dp[aIndex][bIndex] != -1)
    {
        return dp[aIndex][bIndex];
    }

    ll takeA = INT_MAX, takeB = INT_MAX;
    if(aIndex < a.length())
    {
        takeA = dfs(dp, aIndex+1, bIndex, cIndex+1);
        if(a[aIndex] != c[cIndex])
        {
            takeA++;
        }
    }

    if(bIndex < b.length())
    {
        takeB = dfs(dp, aIndex, bIndex+1, cIndex+1);
        if(b[bIndex] != c[cIndex])
        {
            takeB++;
        }
    }
  
    dp[aIndex][bIndex] = std::min(takeA, takeB);

    return dp[aIndex][bIndex];
}

int main()
{
   
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> c;
        vector<vector<ll>> dp(a.length()+1, vector<ll>(b.length()+1, -1));
        cout << dfs(dp, 0, 0, 0) << endl;
    }
    return 0;
}

