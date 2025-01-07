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

// eating queries
int main()
{
    ll t, n, q;
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        vector<ll> bruh(n);
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        std::sort(bruh.rbegin(), bruh.rend());
        vector<ll> prefix(n+1, 0);
        ll sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += bruh[i-1];
            prefix[i] = sum;
        }
        for(int i = 0; i < q; i++)
        {
            ll findy;
            cin >> findy;
            auto iter = std::lower_bound(prefix.begin(), prefix.end(), findy);
            if(iter == prefix.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << iter-prefix.begin() << endl;
            }
        }
    }
    return 0;
}
