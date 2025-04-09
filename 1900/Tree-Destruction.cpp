#include <bits/stdc++.h>
#define ll long long
#define pb push_back
 
using namespace std;
 
// tree destruction
void dfs(vector<vector<ll>>& adj, vector<vector<ll>>& dp, vector<ll>& visited, ll cur)
{
    visited[cur] = 1;
    dp[0][cur] = adj[cur].size();
    ll max1(-1), max2(-1);
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            dfs(adj, dp, visited, i);    
        }
        else
        {
            continue;
        }
        dp[0][cur] = max(dp[0][cur], dp[0][i]+(ll)adj[cur].size()-2);
        max2 = max(max2, dp[0][i]);
        if(max1 < max2)
        {
            swap(max1, max2);
        }
    }
    dp[1][cur] = dp[0][cur];
    if(max2 != -1)
    {
        dp[1][cur] = max1+max2+((ll)adj[cur].size())-4;
    }
}
 
int main()
{
    ll t, n, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<ll>> adj(n);
        vector<vector<ll>> dp(2, vector<ll>(n, 0));
        for(int i = 0; i < n-1; i++)
        {
            cin >> u >> v;
            u--;
            v--;
            adj[u].pb(v);
            adj[v].pb(u);
        }
        vector<ll> visited(n, 0);
        dfs(adj, dp, visited, 0);
        ll ans = 0;
        for(int i = 0; i < n; i++)
        {
            ans = max({ans, dp[0][i], dp[1][i]});
        }
        cout << ans << '\n';
    }
    return 0;
}
