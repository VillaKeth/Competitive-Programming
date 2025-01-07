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

// max plus size
int main()
{
    ll t, n, temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll first = 0;
        ll second = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(i&1)
            {
                second = std::max(second, temp);
            }
            else
            {
                first = std::max(first, temp);
            }
        }
        first += (n&1)+n/2;
        second += n/2;
        cout << std::max(first, second) << endl;
    }
    return 0;
}
