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

// farmer john's card game
int main()
{
    ll t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<vector<ll>> bruh(n, vector<ll>(m));
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                cin >> bruh[i][j];
            }
        }
        for(int i = 0; i < n; i++)
        {
            std::sort(bruh[i].begin(), bruh[i].end());
        }
        vector<pair<ll, ll>> order(n);
        for(int i = 0; i < n; i++)
        {
            order[i].first = bruh[i][0];
            order[i].second = i;
        }
        std::sort(order.begin(), order.end());
        bool can = true;
        ll cur = -1;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(bruh[order[j].second][i] < cur)
                {
                    can = false;
                    i = m;
                    break;
                }
                cur = bruh[order[j].second][i];
            }
        }
        if(can)
        {
            for(auto i : order)
            {
                cout << i.second+1 << ' ';
            }
            cout << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
