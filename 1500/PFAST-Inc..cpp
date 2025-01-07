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

// pfast inc.
int main()
{
    int n, m;
    std::string u, v;
    cin >> n >> m;
    std::map<std::string, int> people;
    vector<std::string> people2(n);
    for(int i = 0; i < n; i++)
    {
        cin >> people2[i];
        people[people2[i]] = i;
    }
    std::set<pair<ll, ll>> bad;
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        bad.insert({people[u], people[v]}); // order doesn't matter thanks to input constraints
    }
    vector<std::string> ans;
    int end = std::pow(2, n);
    for(int i = 1; i < end; i++)
    {
        bool flag = true;
        for(auto j : bad)
        {
            if(((i >> j.first)&1) & ((i >> j.second)&1))
            {
                flag = false;
                break;
            }
        }
        if(flag && __builtin_popcount(i) > (int)ans.size())
        {
            ans.clear();
            for(int j = 0; j < n; j++)
            {
                if((i >> j)&1)
                {
                    ans.pb(people2[j]);
                }
            }
        }
    }
    std::sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
