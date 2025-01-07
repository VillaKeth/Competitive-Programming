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

// bazoka and mocha's array 
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        ll min = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
            min = std::min(min, bruh[i]);
        }
        bool flag = true;
        ll stop = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(bruh[i] > bruh[i+1])
            {
                stop = i+1;
                break;
            }
        }
        for(int i = stop; i < n+stop-1; i++)
        {
            if(bruh[i%n] > bruh[(i+1)%n])
            {
                flag = false;
                break;
            }
        }
        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
