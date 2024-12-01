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

// road to zero
int main()
{
    int testCases;
    long long x, y, a, b;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> x >> y >> a >> b;
        long long xzero = std::abs(x);
        long long yzero = std::abs(y);
        long long temp1 = (xzero + yzero) * a;
        long long temp2 = (std::abs(x-y)*a) + std::min(xzero, yzero)*b;
        cout << std::min(temp1, temp2) << endl;
    }
    return 0;
}
