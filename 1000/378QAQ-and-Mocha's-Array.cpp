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

// 378QAQ and mocha's array
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        std::sort(bruh.begin(), bruh.end());
        bool flag = true;
        ll first = bruh[0];
        ll second = INT_MAX;
        for(int i = 1; i < n; i++)
        {
            if(bruh[i]%first)
            {
                second = bruh[i];
                break;
            }
        }
        for(int i = 2; i < n; i++)
        {
            if((bruh[i]%first) && (bruh[i]%second))
            {
                flag = false;
                break;
            }
        }
        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
