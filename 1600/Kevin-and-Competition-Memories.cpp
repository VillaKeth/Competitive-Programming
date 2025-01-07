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

// kevin and competition memories
int main()
{
    ll t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<ll> a(n);
        vector<ll> b(m);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for(int i = 0; i < m; i++)
        {
            cin >> b[i];
        }
        ll kevin = a[0];
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end());
        ll fg = std::upper_bound(b.begin(), b.end(), kevin)-b.begin();
        vector<ll> prefix(m, 0);
        ll count = n;
        ll county = 0;
        for(int i = fg; i < m; i++)
        {
            while(county < n && b[i] > a[county])
            {
                county++;
                count--;
            }
            prefix[i] = count;
        }
        for(int k = 1; k <= m; k++)
        {
            ll sum = 0;
            if(k <= fg)
            {
                sum += fg/k;
            }
            for(int i = m-(k-(fg%k)); i >= fg; i-=k)
            {
                sum += prefix[i]+1;
            }
            cout << sum << ' ';
        }
        cout << endl;
    }
    return 0;
}
