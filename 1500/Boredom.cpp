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

// boredom
int main()
{
    ll n, temp;
    cin >> n;
    vector<ll> arr(1e5+1, 0);
    vector<ll> dp(2);
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        arr[temp]++;
    }
    dp[0] = 0;
    dp[1] = arr[1];
    for(ll i = 2; i <= 1e5; i++)
    {
        dp[i%2] = std::max(i*arr[i]+dp[i%2], dp[(i-1)%2]);
    }
    cout << dp[0];
    return 0;
}
