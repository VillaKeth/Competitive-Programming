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

// block sequence
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        vector<ll> dp(n+1, 0);
        for(int i = n-1; i >= 0; i--)
        {
            dp[i] = 1+dp[i+1];
            if(i+bruh[i]+1 <= n) // can take
            {
                dp[i] = std::min(dp[i], dp[i+bruh[i]+1]);
            }
        }
        cout << dp[0] << endl;
    }
    return 0;
}
