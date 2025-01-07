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
const ll MODDY = 1000000007;
const ll MODDY2 = 998244353;
 
// anton and making potions
int main()
{
    ll n, r, s, m, x;
    cin >> n >> r >> s >> m >> x;
    vector<pair<ll, ll>> repos(r); // {problem speed, money}
    vector<ll> scpProblems(s);
    vector<ll> scpCost(s);
    ll minRepo = LLONG_MAX;
    ll maxSCP = LLONG_MIN;
    for(int i = 0; i < r; i++)
    {
        cin >> repos[i].first;
    }
    for(int i = 0; i < r; i++)
    {
        cin >> repos[i].second;
        if(repos[i].second <= x)
        {
            minRepo = std::min(minRepo, repos[i].first);
        }
    }
    for(int i = 0; i < s; i++)
    {
        cin >> scpProblems[i];
    }
    for(int i = 0; i < s; i++)
    {
        cin >> scpCost[i];
        if(scpCost[i] <= x)
        {
            maxSCP = std::max(maxSCP, scpProblems[i]);
        }
    }
    ll ans = n*m; // problems*minutes
    for(int i = 0; i < r; i++) // must check all values since all values in r are less than m
    {
        if(repos[i].second <= x)
        {
            ll moners = x-repos[i].second;
            ll start = 0;
            auto iter = std::upper_bound(scpCost.begin(), scpCost.end(), moners);
            ll curProblems = n;
            if(iter != scpCost.begin()) // we can actually buy it
            {
                curProblems -= scpProblems[(iter-scpCost.begin())-1];
            }
            ans = std::min(ans, curProblems*repos[i].first);
        }
    }
    if(minRepo != LLONG_MAX)
    {
        minRepo *= n;
    }
    if(maxSCP != LLONG_MIN)
    {
        maxSCP = (n-maxSCP)*m;
    }
    else
    {
        maxSCP = LLONG_MAX;
    }
    ans = std::min({ans, minRepo, maxSCP});
    cout << ans;
    return 0;
}
