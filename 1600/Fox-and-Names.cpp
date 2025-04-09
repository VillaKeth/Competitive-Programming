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

// fox and names
bool hasCycle(vector<vector<ll>>& adj, vector<ll>& visited, ll cur)
{
    visited[cur] = 1;
    for(auto i : adj[cur])
    {
        if(!visited[i] && hasCycle(adj, visited, i))
        {
            return true;
        }
        else if(visited[i] == 1)
        {
            return true;
        }
    }
    visited[cur] = 2;
    return false;
}

void topSort(vector<vector<ll>>& adj, vector<ll>& visited, vector<ll>& toppy, ll cur)
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

int main()
{
    ll n;
    cin >> n;
    vector<std::string> names(n);
    for(int i = 0; i < n; i++)
    {
        cin >> names[i];
    }
    bool prefixCheck = true;
    for(int i = 1; i < n; i++)
    {
        for(int j = 0; j < i; j++)
        {
            if(names[j].length() <= names[i].length())
            {
                continue;
            }
            std::string compare = names[j].substr(0, names[i].length());
            bool equal = true;
            for(int k = 0; k < names[i].length(); k++)
            {
                if(names[i][k] != compare[k])
                {
                    equal = false;
                    break;
                }
            }
            if(equal)
            {
                prefixCheck = false;
                i = n;
                break;
            }
        }
    }
    if(!prefixCheck)
    {
        cout << "Impossible";
        return 0;
    }
    vector<vector<ll>> adj(26);
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < std::min(names[i].length(), names[i+1].length()); j++)
        {
            if(names[i][j] != names[i+1][j])
            {
                adj[names[i][j]-'a'].pb(names[i+1][j]-'a');
                // cout << "Edge from " << names[i][j] << " to " << names[i+1][j] << endl;
                break;
            }
        }
    }
    vector<ll> visited(26, 0);
    bool cycle = false;
    for(int i = 0; i < 26; i++)
    {
        if(!visited[i])
        {
            cycle = cycle | hasCycle(adj, visited, i);
        }
    }
    if(cycle)
    {
        cout << "Impossible";
        return 0;
    }
    visited.assign(26, 0);
    vector<ll> toppy;
    for(int i = 0; i < 26; i++)
    {
        if(!visited[i])
        {
            topSort(adj, visited, toppy, i);
        }
    }
    std::reverse(toppy.begin(), toppy.end());
    for(auto i : toppy)
    {
        cout << (char)(i+'a');
    }
    return 0;
}
