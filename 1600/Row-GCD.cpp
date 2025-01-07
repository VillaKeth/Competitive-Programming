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

// row gcd
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
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    vector<ll> diff(n-1);
    for(int i = 0; i < n-1; i++)
    {
        diff[i] = std::abs(a[i+1]-a[i]);
    }
    ll gcdMod = 0;
    for(int i = 0; i < n-1; i++)
    {
        gcdMod = gcd(gcdMod, diff[i]);
    }
    for(int i = 0; i < m; i++)
    {
        if(!gcdMod)
        {
            cout << a[0]+b[i] << ' ';
        }
        else
        {
            cout << gcd(gcdMod, (a[0]%gcdMod)+b[i]) << ' ';
        }
    }
    return 0;
}
