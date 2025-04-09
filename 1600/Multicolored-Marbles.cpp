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

// multicolored marbles
int main()
{
    ll n;
    cin >> n;
    vector<ll> fib(n+1);
    fib[0] = 1;
    fib[1] = 1;
    for(int i = 2; i <= n; i++)
    {
        fib[i] = (fib[i-1]+fib[i-2])%MODDY;
    }
    vector<ll> dp(n+1);
    dp[0] = 0;
    dp[1] = 1;
    for(ll i = 2; i <= n; i++)
    {
        dp[i] = (dp[i-1]+fib[i])%MODDY;
    }
    cout << dp[n];
    return 0;
}
