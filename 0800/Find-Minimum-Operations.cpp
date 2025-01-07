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

// find minimum operations
int main()
{
    ll t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ll count = 0;
        if(k == 1)
        {
            cout << n << endl;
        }
        else
        {
            ll newK = 1;
            while(newK < n)
            {
                newK *= k;
            }
            while(n != 0)
            {
                while(newK > n)
                {
                    newK /= k;
                }
                count += (n/newK);
                n -= newK*(n/newK);
            }
            cout << count << endl;
        }
    }
    return 0;
}
