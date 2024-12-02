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

// lazy narek
ll dfs(vector<vector<ll>>& dp, vector<std::string>& bruh, std::string& narek, ll bIndex, ll nIndex)
{
    if(bIndex == bruh.size())
    {
        return -1*nIndex;
    }
    if(dp[bIndex][nIndex] != LLONG_MIN)
    {
        return dp[bIndex][nIndex];
    }
    ll temp = 0;
    ll temp2 = 0;
    ll curNIndex = nIndex;
    for(int i = 0; i < bruh[bIndex].size(); i++)
    {
        if(bruh[bIndex][i] == narek[curNIndex])
        {
            curNIndex++;
            if(curNIndex == 5)
            {
                temp += 5;
                curNIndex = 0;
            }
        }
        else
        {
            if(bruh[bIndex][i] == 'n' || bruh[bIndex][i] == 'a' || bruh[bIndex][i] == 'r' || bruh[bIndex][i] == 'e' || bruh[bIndex][i] == 'k')
            {
                temp2++;
            }
        }
    }
    ll take = (temp-temp2)+dfs(dp, bruh, narek, bIndex+1, curNIndex);
    ll skip = dfs(dp, bruh, narek, bIndex+1, nIndex);
    dp[bIndex][nIndex] = std::max(take, skip);
    return dp[bIndex][nIndex];
}
 
int main()
{
    ll t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<std::string> bruh(n);
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        std::string narek = "narek";
        vector<vector<ll>> dp(n+1, vector<ll>(6, LLONG_MIN));
        cout << dfs(dp, bruh, narek, 0, 0) << endl;
    }
    return 0;
}
