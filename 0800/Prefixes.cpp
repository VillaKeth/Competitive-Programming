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

// prefixes
int main()
{
    ll n;
    std::string s;
    cin >> n >> s;
    ll count = 0;
    for(int i = 1; i < n; i+=2)
    {
        if(s[i] == s[i-1])
        {
            count++;
            if(s[i] == 'a')
            {
                s[i-1] = 'b';
            }
            else
            {
                s[i-1] = 'a';
            }
        }
    }
    cout << count << endl;
    cout << s;
    return 0;
}
