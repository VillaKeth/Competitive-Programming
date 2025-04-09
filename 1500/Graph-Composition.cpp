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

// graph composition
vector<ll> linkf(2e5+5);
vector<ll> sizef(2e5+5);
vector<ll> linkg(2e5+5);
vector<ll> sizeg(2e5+5);

ll findf(ll x)
{
    while(x != linkf[x])
    {
        x = linkf[x];
    }
    return x;
}

void unitef(ll a, ll b)
{
    a = findf(a);
    b = findf(b);
    if(sizef[a] < sizef[b])
    {
        std::swap(a, b);
    }
    sizef[a] += sizef[b];
    linkf[b] = a;
}

ll findg(ll x)
{
    if(linkg[x] != x)
    {
        linkg[x] = findg(linkg[x]);
    }
    return linkg[x];
}
 
void uniteg(ll a, ll b)
{
    a = findg(a);
    b = findg(b);
    if(sizeg[a] < sizeg[b])
    {
        std::swap(a, b);
    }
    sizeg[a] += sizeg[b];
    linkg[b] = a;
}
 
void dfs(vector<vector<ll>>& adj, vector<ll>& visited, ll cur, ll& ans)
{
    visited[cur] = true;
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            if(findg(cur) == findg(i) && findf(cur) != findf(i))
            {
                unitef(cur, i);
                ans++;
            }
            dfs(adj, visited, i, ans);
        }
    }
}

int main()
{
    ll t, n, m1, m2, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n >> m1 >> m2;
        vector<vector<ll>> adjf(n);
        vector<vector<ll>> adjg(n);
        vector<pair<ll, ll>> fedges(m1);
        for(int i = 0; i < n; i++)
        {
            linkf[i] = i;
            linkg[i] = i;
            sizef[i] = 1;
            sizeg[i] = 1;
        }
        for(int i = 0; i < m1; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            fedges[i].first = u;
            fedges[i].second = v;
        }
        for(int i = 0; i < m2; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            adjg[u].pb(v);
            adjg[v].pb(u);
            if(findg(u) != findg(v))
            {
                uniteg(u, v);
            }
        }
        ll ans = 0;
        for(int i = 0; i < m1; i++)
        {
            u = fedges[i].first;
            v = fedges[i].second;
            if(findg(u) != findg(v))
            {
                ans++;
            }
            else
            {
                if(findf(u) != findf(v))
                {
                    unitef(u, v);
                }
            }
        }
        vector<ll> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(adjg, visited, i, ans);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
