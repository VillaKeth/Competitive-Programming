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

// game of ball passing
int main() // get all values as close to each other as possible then max-min
{
    ll t, n, temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll max = INT_MIN;
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            max = std::max(max, temp);
            sum += temp;
        }
        if(!sum)
        {
            cout << 0 << endl;
        }
        else if(2*max <= sum)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << (2*max)-sum << endl;
        }
    }
    return 0;
}
