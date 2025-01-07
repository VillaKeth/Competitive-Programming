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

// zhan's blender
int main()
{
    ll t, n, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> x >> y;
        ll min = std::min(x, y);
        ll ans = n/min;
        if(n%min != 0)
        {
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
