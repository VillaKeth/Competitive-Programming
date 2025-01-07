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

// big vova
ll gcd(ll a, ll b)
{
    while(b != 0)
    {
        ll temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int main()
{
    ll t, n, temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll max = 0;
        std::map<ll, ll> mp;
        vector<ll> ans(n);
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            mp[temp]++;
            max = std::max(max, temp);
        }
        ans[0] = max;
        mp[max]--;
        ll curGCD = max;
        for(int i = 1; i < n; i++)
        {
            ll maxGCD = 0;
            ll val = 0;
            for(auto j : mp)
            {
                ll testy = gcd(curGCD, j.first);
                if(j.second > 0 && testy > maxGCD)
                {
                    maxGCD = testy;
                    val = j.first;
                }
            }
            curGCD = gcd(curGCD, val);
            mp[val]--;
            ans[i] = val;
        }
        for(auto i : ans)
        {
            cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}
