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

// fox and jumping
ll gcd(ll a, ll b)
{
    while(b != 0)
    {
        ll temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

ll dfs(std::map<ll, vector<ll>>& adj, std::map<pair<ll, ll>, ll>& dp, std::map<ll, ll>& cost, std::map<ll, std::set<ll>>& factors, ll cur, ll curGCD)
{
    curGCD = gcd(cur, curGCD);
    if(curGCD == 1)
    {
        return cost[cur];
    }
    if(dp.find({cur, curGCD}) != dp.end())
    {
        return dp[{cur, curGCD}];
    }
    ll min = INT_MAX;
    for(auto i : adj[cur])
    {
        min = std::min(min, cost[cur]+dfs(adj, dp, cost, factors, i, curGCD));
    }
    dp[{cur, curGCD}] = min;
    return dp[{cur, curGCD}];
}

int main()
{
    ll n, temp;
    cin >> n;
    std::map<ll, ll> cost;
    std::map<ll, std::set<ll>> factors;
    std::map<ll, vector<ll>> adj;
    std::map<pair<ll, ll>, ll> dp;
    vector<ll> arr(n);
    vector<ll> numbers;
    ll one = INT_MAX;
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        if(cost.find(arr[i]) != cost.end())
        {
            cost[arr[i]] = std::min(temp, cost[arr[i]]);
        }
        else
        {
            cost[arr[i]] = temp;
        }
    }
    for(auto i : cost)
    {
        if(i.first == 1)
        {
            one = std::min(cost[i.first], one);
        }
        else
        {
            numbers.pb(i.first);
        }
    }
    for(int i = 0; i < numbers.size(); i++)
    {
        temp = numbers[i];
        for(int j = 2; j*j <= numbers[i]; j++)
        {
            while(!(temp%j))
            {
                factors[numbers[i]].insert(j);
                temp /= j;
            }
        }
        if(temp != 1)
        {
            factors[numbers[i]].insert(temp);
        }
    }
    ll min = INT_MAX;
    for(int i = 0; i < numbers.size(); i++)
    {
        ll u = numbers[i];
        for(int j = i+1; j < numbers.size(); j++)
        {
            ll v = numbers[j];
            bool share = true;
            for(auto k : factors[u])
            {
                if(factors[v].find(k) == factors[v].end())
                {
                    share = false;
                    break;
                }
            }
            for(auto k : factors[v])
            {
                if(factors[u].find(k) == factors[u].end())
                {
                    share = false;
                    break;
                }
            }
            if(!share)
            {
                adj[u].pb(v);
            }
        }
    }
    for(int i = 0; i < numbers.size(); i++)
    {
        min = std::min(min, dfs(adj, dp, cost, factors, numbers[i], numbers[i]));
    }
    cout << (std::min(one, min) == INT_MAX ? -1 : std::min(one, min));
    
    return 0;
}
