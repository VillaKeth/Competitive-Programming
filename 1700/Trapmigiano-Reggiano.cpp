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

// trapmigiano reggiano
bool dfs1(vector<vector<ll>>& adj, vector<ll>& visited, vector<ll>& ans, vector<ll>& added, ll& end, ll cur)
{
    visited[cur] = 1;
    bool hasEnd = false;
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            if(i != end)
            {
                hasEnd = hasEnd | dfs1(adj, visited, ans, added, end, i);   
            }
            else
            {
                hasEnd = true;
            }
        }
    }
    if(!hasEnd)
    {
        added[cur] = 1;
        ans.pb(cur);
    }
    return hasEnd;
}

void dfs2(vector<vector<ll>>& adj, vector<ll>& ans, vector<ll>& added, ll& end, ll cur)
{
    ans.pb(cur);
    added[cur] = 1;
    for(auto i : adj[cur])
    {
        if(!added[i] && i != end)
        {
            dfs2(adj, ans, added, end, i);
        }
    }
}

void dfs3(vector<vector<ll>>& adj, vector<ll>& visited, vector<ll>& ans, ll cur)
{
    visited[cur] = 1;
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            dfs3(adj, visited, ans, i);
        }
    }
    ans.pb(cur);
}

int main()
{
    ll t, n, start, end, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n >> start >> end;
        start--;
        end--;
        vector<vector<ll>> adj(n);
        vector<ll> visited(n, 0);
        vector<ll> added(n, 0);
        vector<ll> ans;
        for(int i = 0; i < n-1; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        dfs1(adj, visited, ans, added, end, start);
        if(ans.size() != n)
        {
            dfs2(adj, ans, added, end, start);
            dfs3(adj, visited, ans, end);
        }
        for(auto i : ans) 
        {
            cout << i+1 << ' ';
        }
        cout << endl;
    }
    return 0;
}
