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

// the way to home
int main()
{
    int n, d;
    std::string s;
    cin >> n >> d >> s;
    vector<int> bruh(n, INT_MAX);
    bruh[n-1] = 0;
    for(int i = n-2; i >= 0; i--)
    {
        if(s[i] == '1')
        {
            int min = INT_MAX;
            for(int j = i; j < i+d+1 && j < n; j++)
            {
                min = std::min(min, bruh[j]);
            }
            if(min == INT_MAX)
            {
                continue;
            }
            bruh[i] = min+1;
        }
    }
    if(bruh[0] == INT_MAX)
    {
        cout << -1;
    }
    else
    {
        cout << bruh[0];
    }
    return 0; 
}
