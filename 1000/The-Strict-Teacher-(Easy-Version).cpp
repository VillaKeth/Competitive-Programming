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

// the strict teacher (easy version)
int main()
{
    ll t, n, m, quer, t1, t2, q;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> quer;
        cin >> t1 >> t2 >> q;
        if(q > t1 && q > t2) // greater than both
        {
            cout << n-std::max(t1, t2) << endl;
        }
        else if(q < t1 && q < t2) // less than both
        {
            cout << std::min(t1, t2)-1 << endl;
        }
        else // in between
        {
            cout << (std::abs(t1-t2))/2 << endl;
        }
    }
    return 0;
}
