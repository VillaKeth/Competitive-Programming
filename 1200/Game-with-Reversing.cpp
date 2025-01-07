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

// game with reversing 
int main()
{
    ll test, n;
    std::string s, t;
    cin >> test;
    while(test--)
    {
        cin >> n >> s >> t;
        ll forward = 0;
        ll back = 0;
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[i])
            {
                forward++;
            }
        }
        for(int i = 0; i < n; i++)
        {
            if(s[i] != t[n-1-i])
            {
                back++;
            }
        }
        if(!back)
        {
            cout << std::min(2LL, (2*forward)-(-forward%2)) << endl;
        }
        else
        {
            cout << std::min((2*forward)-(forward%2), (2*back)-(1-(back%2))) << endl;
        }
    }
    return 0;
}
