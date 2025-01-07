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

// longest strike
int main()
{
    ll t, n, k, temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ll l = INT_MAX, r = INT_MIN;
        std::map<ll, ll> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            mp[temp]++;
        }
        vector<ll> newBruh;
        for(auto i : mp)
        {
            if(i.second >= k)
            {
                newBruh.pb(i.first);
            }
        }
        ll maxDiff = -1, left = 0, right = 0;
        while(left < newBruh.size())
        {
            if(left && newBruh[left]-newBruh[left-1] != 1)
            {
                while(right < left)
                {
                    right++;
                }
            }
            if(newBruh[left]-newBruh[right] > maxDiff)
            {
                maxDiff = newBruh[left]-newBruh[right];
                l = newBruh[right];
                r = newBruh[left];
            }
            left++;
        }
        l == INT_MAX ? cout << -1 << endl : cout << l << ' ' << r << endl;
    }
    return 0;
}
