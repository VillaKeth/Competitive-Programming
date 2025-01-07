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

// queue sort
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        ll min = INT_MAX;
        ll start = 0;
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
            min = std::min(min, bruh[i]);
        }
        for(int i = 0; i < n; i++)
        {
            if(min == bruh[i])
            {
                start = i;
                break;
            }
        }
        for(int i = start; i < n-1; i++)
        {
            if(bruh[i] > bruh[i+1])
            {
                flag = false;
                break;
            }
        }
        flag ? cout << start << endl : cout << -1 << endl;
    }
    return 0;
}
