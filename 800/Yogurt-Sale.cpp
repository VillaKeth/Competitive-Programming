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

// yogurt sale
int main()
{
    int testCases, n, a, b;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n >> a >> b;
        if(n % 2 == 0)
        {
            cout << std::min(n*a, (n/2)*b) << endl;
        }
        else if(n == 1)
        {
            cout << a << endl;
        }
        else
        {
            cout << std::min(n*a, ((n-1)/2)*b + a) << endl;
        } 
    }
    return 0;
}
