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

// best price
int main()
{
    ll t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<ll> a(n);
        vector<ll> b(n);
        std::set<ll> sp;
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
            sp.insert(a[i]);
        }
        for(int i = 0; i < n; i++)
        {
            cin >> b[i];
            sp.insert(b[i]);
        }
        ll ans = 0;
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        for(auto i : sp)
        {
            ll lower = std::lower_bound(a.begin(), a.end(), i)-a.begin();
            ll upper = std::lower_bound(b.begin(), b.end(), i)-b.begin();
            if(n-upper <= (n-lower)+k)
            {
                ans = std::max(ans, i*(n-upper));
            }
        }
        cout << ans << endl; 
    }
    return 0;
}
