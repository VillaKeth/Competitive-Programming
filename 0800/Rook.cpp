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

// rook
int main()
{
    ll t;
    std::string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        for(char i = 'a'; i <= 'h'; i++)
        {
            if(i != s[0])
            {
                cout << i << s[1] << endl;
            }
        }
        for(int i = 1; i <= 8; i++)
        {
            if(i != s[1]-'0')
            {
                cout << s[0] << i << endl;
            }
        }
    }
    return 0;
}
