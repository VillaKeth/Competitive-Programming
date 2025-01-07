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

// add zeroes 
ll dfs(vector<pair<ll, ll>>& zeroesNeeded, std::map<ll, ll>& dp, ll curLength, ll index)
{
    curLength += index;
    ll max = curLength;
    ll firstEqual = std::lower_bound(zeroesNeeded.begin(), zeroesNeeded.end(), std::make_pair(curLength-((ll)zeroesNeeded.size()+1), std::numeric_limits<ll>::min()))-zeroesNeeded.begin();
    while(firstEqual < zeroesNeeded.size() && zeroesNeeded[firstEqual].first == curLength-(zeroesNeeded.size()+1))
    {
        if(dp[index])
        {
            max = std::max(max, dp[index]);
        }
        else
        {
            max = std::max(max, dfs(zeroesNeeded, dp, curLength, zeroesNeeded[firstEqual].second));    
        }
        firstEqual++;
    }
    dp[index] = max;
    return dp[index];
}

int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll max = n;
        vector<ll> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        vector<pair<ll, ll>> zeroesNeeded(n-1, {-1, -1}); 
        for(int i = 1; i < n; i++)
        {
            if(arr[i]+i >= n)
            {
                zeroesNeeded[i-1] = {(arr[i]+i)-n, i};
            }
        }
        std::sort(zeroesNeeded.begin(), zeroesNeeded.end());
        std::map<ll, ll> dp;
        for(int i = 0; i < n-1; i++)
        {
            if(!zeroesNeeded[i].first)
            {
                max = std::max(max, dfs(zeroesNeeded, dp, n, zeroesNeeded[i].second));
            }
        }
        cout << max << endl;
    }
    return 0;
}
