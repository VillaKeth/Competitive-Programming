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

// ball in berland
int main()
{
    ll t, a, b, k;
    cin >> t;
    while(t--)
    {
        cin >> a >> b >> k;
        vector<pair<ll, ll>> edges(k);
        for(int i = 0; i < k; i++)
        {
            cin >> edges[i].first;
            edges[i].first--;
        }
        for(int i = 0; i < k; i++)
        {
            cin >> edges[i].second;
            edges[i].second--;
            edges[i].second += std::max({a, b, k});
        }
        vector<std::set<ll>> bruh(2*std::max({a, b, k}));
        for(int i = 0; i < k; i++)
        {
            bruh[edges[i].first].insert(edges[i].second);
            bruh[edges[i].second].insert(edges[i].first);
        }
        ll ans = 0;
        ll kCounty = k;
        for(int i = 0; i < k; i++)
        {
            ans += (kCounty-(bruh[edges[i].first].size()+bruh[edges[i].second].size()-1));
            bruh[edges[i].first].erase(edges[i].second);
            bruh[edges[i].second].erase(edges[i].first);
            kCounty--;
        }
        cout << ans << endl;
    }
    return 0;
}
