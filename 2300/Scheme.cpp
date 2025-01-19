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

// scheme
vector<ll> link1(1e5+5);
vector<ll> size1(1e5+5, 1);
vector<ll> link2(1e5+5);
vector<ll> size2(1e5+5, 1);
 
ll find1(ll x)
{
    if(link1[x] != x)
    {
        link1[x] = find1(link1[x]);
    }
    return link1[x];
}
 
void unite1(ll a, ll b)
{
    a = find1(a);
    b = find1(b);
    if(size1[a] < size1[b])
    {
        std::swap(a, b);
    }
    size1[a] += size1[b];
    link1[b] = a;
}
 
ll find2(ll x)
{
    if(link2[x] != x)
    {
        link2[x] = find2(link2[x]);
    }
    return link2[x];
}
 
void unite2(ll a, ll b)
{
    a = find2(a);
    b = find2(b);
    if(size2[a] < size2[b])
    {
        std::swap(a, b);
    }
    size2[a] += size2[b];
    link2[b] = a;
}
 
void dfs1(vector<vector<ll>>& adj, vector<bool>& visited, vector<ll>& finishTime, ll cur)
{
    visited[cur] = true;
    for(int i : adj[cur])
    {
        if(!visited[i])
        {
            dfs1(adj, visited, finishTime, i);
        }
    }
    finishTime.pb(cur);
}
 
void dfs2(vector<vector<ll>>& adj, vector<bool>& visited, ll& start, ll cur)
{
    visited[cur] = true;
    if(find1(start) != find1(cur))
    {
        unite1(start, cur);
    }
    for(int i : adj[cur])
    {
        if(!visited[i])
        {
            dfs2(adj, visited, start, i);
        }
    }
}
 
void topSort(vector<std::set<ll>>& adj, vector<bool>& visited, vector<ll>& toppy, ll cur)
{
    visited[cur] = true;
    for(auto i : adj[cur])
    {
        if(!visited[i])
        {
            topSort(adj, visited, toppy, i);
        }
    }
    toppy.pb(cur);
}
 
void dfs3(vector<std::set<ll>>& adj, vector<bool>& visited, std::map<ll, ll>& mp, vector<pair<ll, ll>>& frontsAndBacks, ll& start, ll cur)
{
    visited[cur] = true;
    bool isLeaf = true;
    for(auto i : adj[cur])
    {
        isLeaf = false;
        if(find2(cur) != find2(i))
        {
            if(mp.find(find2(i)) != mp.end())
            {
                mp[find2(cur)] = mp[find2(i)];
            }
            unite2(cur, i);
        }
        if(!visited[i])
        {
            dfs3(adj, visited, mp, frontsAndBacks, start, i);   
        }
    }
    if(isLeaf)
    {
        mp[find2(start)] = cur;
    }
}
 
int main()
{
    ll n, u;
    cin >> n;
    vector<vector<ll>> originalAdj(n);
    vector<vector<ll>> reversedAdj(n);
    vector<std::set<ll>> newAdj(n);
    vector<bool> visited1(n, false);
    vector<bool> visited2(n, false);
    vector<bool> visited3(n, false);
    vector<bool> visited4(n, false);
    vector<ll> finishTime;
    for(int i = 0; i < n; i++)
    {
        cin >> u;
        u--;
        originalAdj[i].pb(u);
        reversedAdj[u].pb(i);
    }
    for(int i = 0; i < n; i++)
    {
        link1[i] = i;
        link2[i] = i;
    }
    ll curTime = 0;
    for(int i = 0; i < n; i++)
    {
        if(!visited1[i])
        {
            dfs1(originalAdj, visited1, finishTime, i);
        }
    }
    for(int i = n-1; i >= 0; i--)
    {
        if(!visited2[finishTime[i]])
        {
            ll start = finishTime[i];
            dfs2(reversedAdj, visited2, start, finishTime[i]);
        }
    }
    std::set<ll> in;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < originalAdj[i].size(); j++)
        {
            ll temp1 = find1(i);
            in.insert(temp1);
            ll temp2 = find1(originalAdj[i][j]);
            if(temp1 != temp2)
            {
                newAdj[temp1].insert(temp2);
            }
        }
    }
    vector<ll> toppy;
    for(int i = 0; i < n; i++)
    {
        if(!visited3[i] && in.find(i) != in.end()) 
        {
            topSort(newAdj, visited3, toppy, i);
        }
    }
    ll count = 0;
    vector<pair<ll, ll>> frontsAndBacks;
    std::map<ll, ll> mp;
    for(int i = toppy.size()-1; i >= 0; i--) 
    {
        if(!visited4[toppy[i]])
        {
            count++;
            dfs3(newAdj, visited4, mp, frontsAndBacks, toppy[i], toppy[i]);
        }
    }
    if(toppy.size() == 1) 
    {
        cout << 0;
        return 0;
    }
    for(auto i : mp)
    {
        frontsAndBacks.pb({i.first, i.second});
    }
    cout << count << endl;
    for(int i = 0; i < frontsAndBacks.size(); i++)
    {
        cout << frontsAndBacks[i].second+1 << ' ' << frontsAndBacks[(i+1)%frontsAndBacks.size()].first+1 << endl;
    }
    return 0;
}
