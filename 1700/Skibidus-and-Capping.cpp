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

// skibidus and capping
int main()
{
    ll t, n, temp;
    vector<ll> sieve(2e5+1, 0);
    vector<ll> primes;
    for(ll i = 2; i <= 2e5; i++)
    {
        if(sieve[i])
        {
            continue;
        }
        primes.pb(i);
        for(int j = 2*i; j <= 2e5; j+=i)
        {
            ll temp = j;
            while(!(temp%i))
            {
                sieve[j]++;
                temp /= i;
            }
        }
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        std::map<ll, ll> mp;
        ll primeCount = 0;
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            mp[temp]++;
            if(!sieve[temp])
            {
                primeCount++;
            }
        }
        for(auto i : mp)
        {
            if(!sieve[i.first])
            {
                ans += i.second*(primeCount-i.second);
                ll tempCount = 0;
                for(int j = 0; primes[j]*i.first <= n; j++)
                {
                    if(mp.find(primes[j]*i.first) != mp.end())
                    {
                        tempCount += mp[primes[j]*i.first];
                    }
                }
                ans += i.second*tempCount;
                primeCount -= i.second;
            }
            else if(sieve[i.first] == 2)
            {
                ans += (i.second*(i.second+1))/2;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
