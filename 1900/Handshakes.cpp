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

// handshakes
int main()
{
    ll n, temp;
    cin >> n;
    vector<vector<ll>> bruh(n+1, vector<ll>({})); 
    vector<ll> ans(n+1);
    bool flag = true;
    for(int i = 1; i <= n; i++)
    {
        cin >> temp;
        bruh[temp].pb(i);
    }
    ll count = 0;
    for(int i = 0; i < n; i++)
    {
        if(bruh[count].empty())
        {
            while(count >= 0 && bruh[count].empty())
            {
                count -= 3;
            }
            if(count < 0)
            {
                flag = false;
                break;
            }
            else
            {
                ans[i+1] = bruh[count].back();
                bruh[count].pop_back();
                count++;
            }
        }
        else
        {
            ans[i+1] = bruh[count].back();
            bruh[count].pop_back();
            count++;
        }
    }
    if(flag)
    {
        cout << "Possible" << endl;
        for(int i = 1; i <= n; i++)
        {
            cout << ans[i] << ' ';
        }
    }
    else
    {
        cout << "Impossible";
    }
    return 0;
}
