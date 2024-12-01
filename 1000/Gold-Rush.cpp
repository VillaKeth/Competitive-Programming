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

// gold rush
bool recurBruh(std::map<int, bool>& mp, int n, int m)
{
    if(n == m)
    {
        return true;
    }
    if(n % 3 != 0 || m > n)
    {
        return false;
    }
    if(!mp[n])
    {
        mp[n] = true;
        return recurBruh(mp, n/3, m) || recurBruh(mp, ((2*n)/3), m); 
    }
    else
    {
        return false;
    }
}
 
int main()
{
    int testCases, n, m;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n >> m;
        std::map<int, bool> mp;
        if(recurBruh(mp, n, m))
        {
            cout << "YES" << endl;
        }
        else
        {
            cout <<"NO" << endl;
        }
    }
    return 0;
}
