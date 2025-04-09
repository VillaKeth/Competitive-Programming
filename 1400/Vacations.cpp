#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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

// vacations
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n+1);
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    vector<vector<ll>> dp(n+1, vector<ll>(3, INT_MAX));
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[0][2] = 0;
    for(int i = 1; i <= n; i++)
    {
        dp[i][0] = std::min({dp[i-1][0], dp[i-1][1], dp[i-1][2]})+1;
        if(arr[i] == 1 || arr[i] == 3)
        {
            dp[i][1] = std::min(dp[i-1][0], dp[i-1][2]);
        }
        if (arr[i] == 2 || arr[i] == 3) 
        {
            dp[i][2] = std::min(dp[i-1][0], dp[i-1][1]);
        }
    }
    cout << std::min({dp[n][0], dp[n][1], dp[n][2]});
    return 0;
}
