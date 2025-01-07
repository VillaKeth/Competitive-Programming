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

// sleeping schedule
ll n, h, l, r, ans(0);
vector<ll> hours;
ll dfs(vector<vector<ll>>& dp, ll index, ll hour)
{
    if(index == n)
    {
        return 0;
    }
    if(dp[index][hour] != -1)
    {
        return dp[index][hour];
    }
    ll take1 = 0;
    ll take2 = 0;
    if((hour+hours[index])%h >= l && (hour+hours[index])%h <= r)
    {
        take1 = 1+dfs(dp, index+1, (hour+hours[index])%h);
    }
    else
    {
        take1 = dfs(dp, index+1, (hour+hours[index])%h);
    }
    if((hour+hours[index]-1)%h >= l && (hour+hours[index]-1)%h <= r)
    {
        take2 = 1+dfs(dp, index+1, (hour+hours[index]-1)%h);
    }   
    else
    {
        take2 = dfs(dp, index+1, (hour+hours[index]-1)%h);
    }
    dp[index][hour] = std::max(take1, take2);
    return dp[index][hour];
}

int main()
{
    cin >> n >> h >> l >> r;
    hours.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> hours[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(h+1, -1));
    cout << dfs(dp, 0, 0);;
    return 0;
}
