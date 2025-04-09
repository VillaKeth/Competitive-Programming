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

// tenzing and balls
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> arr(n+1);
        vector<ll> dp(n+1);
        vector<ll> dp2(n+1, INT_MAX);
        for(ll i = 1; i <= n; i++)
        {
            cin >> arr[i];
            dp[i] = std::min(dp[i-1]+1, dp2[arr[i]]);
            dp2[arr[i]] = std::min(dp2[arr[i]], dp[i-1]);
        }
        cout << n-dp[n] << endl;
    }
    return 0;
}
