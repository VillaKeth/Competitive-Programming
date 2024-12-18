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

// jzzhu and cities
struct compare
{
    bool operator()(const std::tuple<ll, ll, ll>& l, const std::tuple<ll, ll, ll>& r)
    {
        if(std::get<0>(l) == std::get<0>(r))
        {
            return std::get<2>(l) > std::get<2>(r);
        }
        return std::get<0>(l) > std::get<0>(r);
    }
};


int main()
{
    ll n, m, k, u, v, x;
    cin >> n >> m >> k;
    vector<vector<std::tuple<ll, ll, ll>>> adj(n); // {weight, node, road/rail}
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> x;
        u--;
        v--;
        adj[u].pb({x, v, 0});
        adj[v].pb({x, u, 0});
    }
    for(int i = 0; i < k; i++)
    {
        cin >> u >> x;
        u--;
        adj[0].pb({x, u, 1});
        adj[u].pb({x, 0, 1});
    }
    ll count = 0;
    std::priority_queue<std::tuple<ll, ll, ll>, vector<std::tuple<ll, ll, ll>>, compare> pq;
    vector<bool> visited(n, false);
    pq.push({0, 0, 0});
    while(!pq.empty())
    {
        ll weight = std::get<0>(pq.top());
        ll city = std::get<1>(pq.top());
        ll trans = std::get<2>(pq.top());
        pq.pop();
        if(visited[city])
        {
            continue;
        }
        visited[city] = true;
        if(trans)
        {
            count++;
        }
        for(int i = 0; i < adj[city].size(); i++)
        {
            ll nextWeight = std::get<0>(adj[city][i]);
            ll nextCity = std::get<1>(adj[city][i]);
            ll nextTrans = std::get<2>(adj[city][i]);
            if(!visited[nextCity])
            {
                pq.push({weight+nextWeight, nextCity, nextTrans});
            }
        }
    }
    cout << k-count;
    return 0;
}
