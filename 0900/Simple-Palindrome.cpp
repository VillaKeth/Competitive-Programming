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

// simple palindrome
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<char> s;
        vector<char> bruh = {'a', 'e', 'i', 'o', 'u'};
        if(n <= 5)
        {
            for(int i = 0; i < n; i++)
            {   
                s.pb(bruh[i]);
            }
        }
        else
        {
            ll remainder = n%5;
            for(int i = 0; i < 5; i++)
            {
                for(int j = 0; j < n/5; j++)
                {
                    s.pb(bruh[i]);
                }
                if(remainder > 0)
                {
                    s.pb(bruh[i]);
                    remainder--;
                }
            }
        }   
        for(auto i : s)
        {
            cout << i;
        }
        cout << endl;
    }
    return 0;
}
