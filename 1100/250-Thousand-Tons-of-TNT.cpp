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

// 250 thousand tons of tnt
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        vector<ll> factors;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        factors.pb(1);
        for(int i = 2; i*i <= n; i++)
        {
            if(n%i == 0)
            {
                factors.pb(i);
                if(n/i != i)
                {
                    factors.pb(n/i);
                }
            }
        }
        ll ans = 0;
        for(int i = 0; i < factors.size(); i++)
        {
            ll min = LLONG_MAX;
            ll max = LLONG_MIN;
            for(int j = 0; j < n/factors[i]; j++)
            {
                ll sum = 0;
                for(int k = j*factors[i]; k < (j+1)*factors[i]; k++)
                {
                    sum += bruh[k];
                }
                min = std::min(min, sum);
                max = std::max(max, sum);
            }
            ans = std::max(ans, max-min);
        }
        cout << ans << endl;
    }
    return 0;
}
