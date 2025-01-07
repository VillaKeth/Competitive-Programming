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

// binary numbers and sum
int main()
{
    ll n, m;
    std::string a, b;
    cin >> n >> m >> a >> b;
    if(m >= n)
    {
        vector<ll> onesPrefix(n, 0);
        ll ones = 0;
        ll mBegin = m-n;
        for(int i = 0; i < mBegin; i++)
        {
            if(b[i] == '1')
            {
                ones++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(b[mBegin] == '1')
            {
                ones++;
            }
            if(a[i] == '1')
            {
                onesPrefix[i] = ones;
            }
            mBegin++;
        }
        std::reverse(onesPrefix.begin(), onesPrefix.end());
        vector<ll> twos(n);
        ll county = 1;
        for(int i = 0; i < n; i++)
        {
            twos[i] = county%MODDY2;
            county = (county*2)%MODDY2;
        }
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = (ans%MODDY2)+((twos[i]*onesPrefix[i])%MODDY2);
        }
        cout << ans%MODDY2 << endl;
    }
    else
    {
        vector<ll> onesPrefix(m, 0);
        ll ones = 0;
        ll nBegin = n-m;
        for(int i = 0; i < m; i++)
        {
            if(b[i] == '1')
            {
                ones++;
            }
            if(a[nBegin] == '1')
            {
                onesPrefix[i] = ones;
            }
            nBegin++;
        }
        std::reverse(onesPrefix.begin(), onesPrefix.end());
        vector<ll> twos(n);
        ll county = 1;
        for(int i = 0; i < m; i++)
        {
            twos[i] = county % MODDY2;
            county = (county*2)%MODDY2;
        }
        ll ans = 0;
        for(int i = 0; i < m; i++)
        {
            ans = (ans%MODDY2)+((twos[i]*onesPrefix[i])%MODDY2);
        }
        cout << ans%MODDY2 << endl;
    }
    return 0;
}
