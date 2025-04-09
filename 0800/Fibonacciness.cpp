#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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

// fibonacciness
int main()
{
    ll t;
    cin >> t;
    while(t--)
    {
        vector<ll> bruh(5);
        cin >> bruh[0] >> bruh[1] >> bruh[3] >> bruh[4];
        bruh[2] = bruh[0]+bruh[1];
        ll max = 0;
        for(int i = 0; i < 3; i++)
        {
            if(bruh[i]+bruh[i+1] == bruh[i+2])
            {
                max++;
            }
        }
        bruh[2] = bruh[3]-bruh[1];
        ll max2 = 0;
        for(int i = 0; i < 3; i++)
        {
            if(bruh[i]+bruh[i+1] == bruh[i+2])
            {
                max2++;
            }
        }
        cout << std::max(max, max2) << endl;
    }
    return 0;
}
