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

// path queries
vector<ll> link(200001);
vector<ll> size(200001, 1);
 
ll find(ll x)
{
    while(x != link[x])
    {
        x = link[x];
    }
    return x;
}
 
ll same(ll a, ll b)
{
    return find(a) == find(b);
}
 
void unite(ll a, ll b)
{
    a = find(a);
    b = find(b);
    if(size[a] < size[b])
    {
        std::swap(a, b);
    }
    size[a] += size[b];
    link[b] = a;
}
 
int main()
{
    ll n, q, u, v, w, maxRoad;
    cin >> n >> q;
    vector<std::tuple<ll, ll, ll>> bruh(n-1);
    vector<ll> sums(n+1, -1);
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v >> w;
        u--;
        v--;
        bruh[i] = {w, u, v};
    }
    std::sort(bruh.begin(), bruh.end());
    for(int i = 0; i < n; i++)
    {
        link[i] = i;
    }
    ll cur = 0;
    ll sum = 0;
    std::map<ll, ll> mp;
    for(int i = 0; i < n-1; i++)
    {
        w = std::get<0>(bruh[i]);
        u = std::get<1>(bruh[i]);
        v = std::get<2>(bruh[i]);
        if(w != cur)
        {
            sums[cur] = sum;
            cur = w;
        }
        ll findu = find(u);
        ll findv = find(v);
        if(findu != findv) 
        {
            unite(findu, findv);   
        }
        if(mp[findu])
        {
            sum -= (mp[findu]*(mp[findu]-1))/2;
            mp.erase(findu);
        }
        if(mp[findv])
        {
            sum -= (mp[findv]*(mp[findv]-1))/2;
            mp.erase(findv);
        }
        findu = find(u);
        mp[findu] = size[findu];
        sum += (size[findu]*(size[findu]-1))/2;
    }
    sums[cur] = sum;
    sums[0] = 0;
    for(int i = 1; i <= n; i++)
    {
        if(sums[i] == -1)
        {
            sums[i] = sums[i-1];
        }
    }
    for(int i = 0; i < q; i++)
    {
        cin >> maxRoad;
        if(maxRoad > n)
        {
            cout << sums[n] << ' ';
        }
        else
        {
            cout << sums[maxRoad] << ' ';
        }
    }
    return 0;
}
