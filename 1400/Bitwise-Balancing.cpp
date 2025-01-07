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

// bitwise balancing
int main()
{
    ll t, b, c, d;
    cin >> t;
    while(t--)
    {
        cin >> b >> c >> d;
        ll a = 0;
        bool flag = true;
        ll mask = 1;
        for(int i = 0; i < 62; i++)
        {
            ll bbit = b&mask;
            ll cbit = c&mask;
            ll dbit = d&mask;
            if((!bbit && cbit && dbit) || (bbit && !cbit && !dbit))
            {
                flag = false;
                break;
            }
            if((!bbit && !cbit && dbit) || (bbit && !cbit && dbit) || (bbit && cbit && !dbit))
            {
                a += mask;
            }
            mask<<=1;
        }
        flag ? cout << a << endl : cout << -1 << endl;
    }
    return 0;
}
