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

// new year and the christmas ornament
int main()
{
    int y, b, r;
    cin >> y >> b >> r;
    int tempy = y;
    int tempb = tempy+1;
    int tempr = tempb+1;
    while(tempy > y || tempb > b || tempr > r)
    {
        tempy--;
        tempb--;
        tempr--;
    }
    cout << (tempy+tempb+tempr);
    return 0;
}
