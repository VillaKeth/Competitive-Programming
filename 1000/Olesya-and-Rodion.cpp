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

// olesya and rodion
int main()
{
    unsigned long long n, t;
    cin >> n >> t;
    std::string bruh = "";
    if(n == 1 && t == 10)
    {
        cout << -1 << endl;
    }
    else
    {
        if(t == 10)
        {
            bruh += 1 + '0';
            for(int i = 0; i < n-1; i++)
            {
                bruh += 0 + '0';
            }
        }
        else
        {
            for(int i = 0; i < n; i++)
            {
                bruh += (t + '0');
            }
        }
        cout << bruh << endl;    
    } 
    return 0;
}
