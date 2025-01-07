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

// polycarp's practice
int main()
{
    ll n, k, sum(0);
    cin >> n >> k;
    vector<pair<ll, ll>> bruh(n);
    for(int i = 0; i < n; i++)
    {
        cin >> bruh[i].first;
        bruh[i].second = i+1;
    }
    std::sort(bruh.begin(), bruh.end());
    vector<ll> indices;
    for(int i = n-1; i > n-1-k; i--)
    {
       indices.pb(bruh[i].second); 
       sum += bruh[i].first;
    }
    std::sort(indices.begin(), indices.end());
    vector<ll> ans;
    if(indices.size() == 1)
    {
        ans.pb(n);
    }
    else
    {
        for(int i = 0; i < indices.size(); i++)
        {
            if(!i)
            {
                ans.pb(indices[i]);
            }
            else if(i == indices.size()-1)
            {
                ans.pb(n-indices[i-1]);
            }
            else
            {
                ans.pb(indices[i]-indices[i-1]);
            }
        }
    }
    cout << sum << endl;
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}
