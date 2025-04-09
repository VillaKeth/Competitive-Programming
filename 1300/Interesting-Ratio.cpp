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

// interesting ratio
int main()
{   
    ll t, n;
    cin >> t;
    vector<ll> sieve(1e7+1, 0);
    vector<ll> prefix(1e7+1, 0);
    for(int i = 2; i <= 1e7; i++)
    {
        if(sieve[i])
        {
            continue;
        }
        sieve[i]++;
        for(int j = 2*i; j <= 1e7; j+=i)
        {
            sieve[j]++;
        }
    }
    for(int i = 2; i <= 1e7; i++)
    {
        prefix[i] = sieve[i]+prefix[i-1];
    }
    while(t--)
    {
        cin >> n;
        cout << prefix[n] << endl;
    }
    return 0;
}
