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
const ll MODDY3 = 100000000;

// caesar's legions
ll n1, n2, k1, k2;
ll dfs(vector<vector<vector<vector<ll>>>>& dp, ll curMen, ll curHorse, ll conMen, ll conHorse)
{
    if(curMen+curHorse == n1+n2)
    {
        return 1;
    }
    if(dp[curMen][curHorse][conMen][conHorse] != -1)
    {
        return dp[curMen][curHorse][conMen][conHorse]%MODDY3;
    }
    ll takeMen = 0;
    ll takeHorse = 0;
    if(curMen < n1 && conMen < k1)
    {   
        takeMen = dfs(dp, curMen+1, curHorse, conMen+1, 0)%MODDY3;
    }
    if(curHorse < n2 && conHorse < k2)
    {
        takeHorse = dfs(dp, curMen, curHorse+1, 0, conHorse+1)%MODDY3;
    }
    dp[curMen][curHorse][conMen][conHorse] = (takeMen+takeHorse)%MODDY3;
    return dp[curMen][curHorse][conMen][conHorse]%MODDY3;
}

int main()
{
    cin >> n1 >> n2 >> k1 >> k2;
    vector<vector<vector<vector<ll>>>> dp(n1+1, vector<vector<vector<ll>>>(n2+1, vector<vector<ll>>(k1+1, vector<ll>(k2+1, -1))));
    cout << dfs(dp, 0, 0, 0, 0);
    return 0;
}
