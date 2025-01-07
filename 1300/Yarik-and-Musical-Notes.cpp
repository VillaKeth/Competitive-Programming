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

// yarik and musical notes
int main()
{
    ll t, n, temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        std::map<ll, ll> mp;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp == 1 || temp == 2)
            {
                mp[2]++;
            }
            else
            {
                mp[temp]++;
            }
        }
        ll sum = 0;
        for(auto i : mp)
        {
            sum += (i.second*(i.second-1))/2;
        }
        cout << sum << endl;
    }
    return 0;
}
