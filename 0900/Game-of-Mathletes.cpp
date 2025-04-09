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

// game of mathletes
int main()
{
    ll t, n, k, temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<ll> freq((2*n)+1);
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            freq[temp]++; 
        }
        ll ans = 0;
        for(int i = 1; i <= k/2; i++)
        {
            if(i == k-i)
            {
                ans += freq[i]/2;
            }
            else
            {
                ans += std::min(freq[i], freq[k-i]);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
