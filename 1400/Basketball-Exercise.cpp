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

// basketball exercise
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr1(n+1);
    vector<ll> arr2(n+1);
    vector<vector<ll>> dp(3, vector<ll>(2));
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr1[i];
    }
    for(int i = 1; i <= n; i++)
    {
        cin >> arr2[i];
    }
    for(int i = 1; i <= n; i++)
    {
        dp[0][i%2] = std::max(dp[1][(i-1)%2], dp[2][(i-1)%2]);
        dp[1][i%2] = arr1[i]+std::max(dp[0][(i-1)%2], dp[2][(i-1)%2]);
        dp[2][i%2] = arr2[i]+std::max(dp[0][(i-1)%2], dp[1][(i-1)%2]);
    }
    cout << std::max({dp[0][n%2], dp[1][n%2], dp[2][n%2]});
    return 0;
}
