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
const ll MODDY = 1e9+7;
const ll MODDY2 = 998244353;
const ll MODDY3 = 1e8;

// board moves
int main()
{
    int testCases, n;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n;
        long long ans = 0;
        long long county = 8;
        long long count = 1;
        while(n != 1)
        {
            ans += (county * count);
            county += 8;
            count++;
            n -= 2;
        }
 
        cout << ans << endl;
    }
    return 0;
}
