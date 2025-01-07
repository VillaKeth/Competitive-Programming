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

// seraphim the owl
int main()
{
    ll t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<ll> a(n), b(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        vector<ll> dp(n, 0);
        for(int i = n-1; i >= 0; i--) 
        {
            if(i == n-1)
            {
                dp[i] = a[i];
            }
            else
            {
                dp[i] = std::min(a[i]+dp[i+1]-a[i+1]+b[i+1], a[i]+dp[i+1]);
            }
        }
        ll ans = LLONG_MAX;
        for(int i = 0; i < m; i++)
        {
            ans = std::min(ans, dp[i]);
        }
        cout << ans << endl;
    }
    return 0;
}
