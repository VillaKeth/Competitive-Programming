#include <bits/stdc++.h>
#define ll long long
#define pb push_back
 
using namespace std;

// maximum white subtree
void dfs1(vector<vector<ll>>& adj, vector<ll>& color, vector<ll>& dp, ll cur, ll par)
{
    dp[cur] = color[cur] ? 1ll: -1ll;
    for(auto i : adj[cur])
    {
        if(i == par)
        {
            continue;
        }
        dfs1(adj, color, dp, i, cur);
        dp[cur] += max(dp[i], 0ll);
    }
}

void dfs2(vector<ll>& ans, vector<vector<ll>>& adj, vector<ll>& color, vector<ll>& dp, ll cur, ll par)
{
    ans[cur] = dp[cur];
    for(auto i : adj[cur])
    {
        if(i == par)
        {
            continue;
        }
        dp[cur] -= max(dp[i], 0ll);
        dp[i] += max(dp[cur], 0ll);
        dfs2(ans, adj, color, dp, i, cur);
        dp[i] -= max(dp[cur], 0ll);    
        dp[cur] += max(dp[i], 0ll);
    }
}

int main()
{
    ll n, u, v;
    cin >> n;
    vector<ll> color(n);
    vector<vector<ll>> adj(n);
    vector<ll> dp(n);
    vector<ll> ans(n);
    for(int i = 0; i < n; i++)
    {
        cin >> color[i];
    }
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    dfs1(adj, color, dp, 0, 0);
    dfs2(ans, adj, color, dp, 0, 0);
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}
