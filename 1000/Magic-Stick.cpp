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

// magic stick
int main()
{
    int testCases;
    long long x, y;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> x >> y;
        std::unordered_map<int, int> mp;
        int flag = 1;
        while(x < y)
        {
            mp[x]++;
            if(x % 2 == 0)
            {
                x = (3*x)/2;
            }
            else if(x != 1)
            {
                x--;
            }
            if(mp[x] > 0)
            {
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
