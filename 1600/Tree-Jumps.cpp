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

// tree jumps
int main()
{
    ll t, n, u;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> parentDepth(n);
        vector<ll> parent(n);
        vector<ll> childrenValue(n, 0);
        vector<ll> childrenCount(n, 0);
        vector<ll> dp(n, 1);
        std::map<ll, vector<ll>> nodesAtDepth;
        std::map<ll, ll> depthValue;
        parent[0] = 0;
        ll bottomLevel = 0;
        parentDepth[0] = 0;
        nodesAtDepth[0].pb(0);
        for(int i = 0; i < n-1; i++)
        {
            cin >> u;
            u--;
            parent[i+1] = u;
            childrenCount[u]++;
            parentDepth[i+1] = parentDepth[u]+1;
            nodesAtDepth[parentDepth[i+1]].pb(i+1);
            bottomLevel = std::max(bottomLevel, parentDepth[i+1]);
        }
        depthValue[bottomLevel] = nodesAtDepth[bottomLevel].size();
        for(int i = 0; i < nodesAtDepth[bottomLevel-1].size(); i++)
        {
            childrenValue[nodesAtDepth[bottomLevel-1][i]] = childrenCount[nodesAtDepth[bottomLevel-1][i]];
        }
        for(int i = bottomLevel-1; i > 0; i--)
        {
            for(int j = 0; j < nodesAtDepth[i].size(); j++)
            {
                dp[nodesAtDepth[i][j]] = (dp[nodesAtDepth[i][j]]+depthValue[i+1]-childrenValue[nodesAtDepth[i][j]])%MODDY2;
                depthValue[i] += dp[nodesAtDepth[i][j]];
                childrenValue[parent[nodesAtDepth[i][j]]] += +dp[nodesAtDepth[i][j]];
            }
        }
        for(int i = 0; i < nodesAtDepth[1].size(); i++)
        {
            dp[0] = (dp[0]+dp[nodesAtDepth[1][i]])%MODDY2;
        }
        cout << dp[0] << endl;
    }
    return 0;
}
