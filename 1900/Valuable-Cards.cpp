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

// valuable cards
int main()
{
    ll t, n, x, temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        std::set<ll> factors;
        for(int i = 2; i*i <= x; i++)
        {
            if(!(x%i))
            {
                factors.insert(i);
                factors.insert(x/i);
            }
        }
        factors.insert(x);
        ll ans = 1;
        std::set<ll> curFactors;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(factors.find(temp) == factors.end())
            {
                continue;
            }
            vector<ll> toAdd;
            for(auto j : curFactors)
            {
                if(factors.find(j*temp) != factors.end())
                {
                    toAdd.pb(j*temp);
                }
            }
            curFactors.insert(temp);
            for(int j = 0; j < toAdd.size(); j++)
            {
                curFactors.insert(toAdd[j]);
            }
            if(curFactors.find(x) != curFactors.end())
            {
                ans++;
                curFactors.clear();
                curFactors.insert(temp);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
