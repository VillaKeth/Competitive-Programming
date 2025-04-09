#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

// choosing capital for treeland
ll dfs(vector<vector<pair<ll, ll>>>& adj, vector<ll>& visited, ll cur)
{
    visited[cur] = 1;
    ll ans = 0;
    for(auto [i, j] : adj[cur])
    {
        if(!visited[i])
        {
            ans += dfs(adj, visited, i);
            if(j)
            {
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    ll n, u, v; 
    cin >> n;
    vector<vector<pair<ll, ll>>> adj(n);
    vector<ll> dp(n, 0);
    for(int i = 0; i < n-1; i++)
    {
        cin >> u >> v;
        u--;
        v--;
        adj[u].pb({v, 0});
        adj[v].pb({u, 1});
    }
    vector<ll> visited(n, 0);
    dp[0] = dfs(adj, visited, 0);
    visited.assign(n, 0);
    visited[0] = 1;
    queue<tuple<ll, ll, ll>> q;
    for(auto [i, j] : adj[0])
    {
        q.push({i, j, 0});
    }
    while(!q.empty())
    {
        ll curNode = get<0>(q.front());
        ll direction = get<1>(q.front());
        ll parent = get<2>(q.front());
        q.pop();
        if(visited[curNode])
        {
            continue;
        }
        visited[curNode] = 1;
        if(direction)
        {
            dp[curNode] = std::max(0ll, dp[parent]-1);
        }
        else
        {
            dp[curNode] = dp[parent]+1;
        }
        for(auto [i, j] : adj[curNode])
        {
            if(!visited[i])
            {
                q.push({i, j, curNode});
            }
        }
    }
    ll min = *min_element(dp.begin(), dp.end());
    cout << min << '\n';
    for(int i = 0; i < n; i++)
    {
        if(dp[i] == min)
        {
            cout << i+1 << ' ';   
        }
    }
    return 0;
}
