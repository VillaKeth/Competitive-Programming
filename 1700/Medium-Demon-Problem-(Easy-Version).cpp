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

// medium demon problem (easy version)
void dfs(vector<vector<ll>>& adj, vector<ll>& visited, vector<ll>& output, ll cur)
{
    visited[cur] = 1;
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            dfs(adj, visited, output, i);
        }
    }
    output.pb(cur);
}

void topSort(vector<std::set<ll>>& adj, vector<ll>& visited, vector<ll>& toppy, ll cur)
{
    visited[cur] = 1;
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            topSort(adj, visited, toppy, i);
        }
    }
    visited[cur] = 2;
    toppy.pb(cur);
}

// dfs below only works because nodes are guaranteed to not branch off
ll dfs2(vector<std::set<ll>>& adj, vector<ll>& visited, vector<ll>& length, ll cur)
{
    visited[cur] = 1;
    ll count = 0;
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            count += dfs2(adj, visited, length, i);
        }
        else
        {
            length[cur] = length[i]+1;
            return length[i]+1;
        }
    }
    length[cur] = count+1;
    return count+1;
}

int main()
{
    ll t, n, u;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<ll>> adj(n);
        vector<vector<ll>> reversedAdj(n);
        vector<std::set<ll>> condensedAdj(n);
        vector<ll> roots(n, -1);
        vector<vector<ll>> components;
        for(int i = 0; i < n; i++)
        {
            cin >> u;
            u--;
            adj[i].pb(u);
            reversedAdj[u].pb(i);
        }
        vector<ll> order;
        vector<ll> visited(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(adj, visited, order, i);
            }
        }
        visited.assign(n, 0);
        std::reverse(order.begin(), order.end());
        for(auto i : order)
        {
            if(!visited[i])
            {
                vector<ll> component;
                dfs(reversedAdj, visited, component, i);
                components.pb(component);
                ll root = INT_MAX;
                for(auto j : component)
                {
                    root = std::min(root, j);
                }
                for(auto j : component)
                {
                    roots[j] = root;
                }
            }
        }
        for(int i = 0; i < n; i++)
        {
            for(auto j : adj[i])
            {
                if(roots[i] != roots[j])
                {
                    condensedAdj[roots[i]].insert(roots[j]);
                }
            }
        }
        vector<ll> toppy;
        visited.assign(n, 0);
        for(int i = 0; i < n; i++)
        {
            if(!visited[roots[i]])
            {
                topSort(condensedAdj, visited, toppy, roots[i]);
            }
        }
        std::reverse(toppy.begin(), toppy.end());
        visited.assign(n, 0);
        vector<ll> length(n, 0);
        ll max = 1;
        for(int i = 0; i < toppy.size(); i++)
        {
            if(!visited[toppy[i]])
            {
                max = std::max(max, dfs2(condensedAdj, visited, length, toppy[i]));
            }
        }
        cout << max+1 << endl;
    }
    return 0;
}
