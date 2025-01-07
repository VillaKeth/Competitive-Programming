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

// canine poetry
int main()
{
    ll t;
    std::string s;
    cin >> t;
    vector<char> alpha = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    while(t--)
    {
        cin >> s;
        ll count = 0;
        for(int i = 0; i < s.length(); i++)
        {
            char prev = '~';
            char prevprev = '~';
            char next = '~';
            char nextnext = '~';
            if(i-1 >= 0)
            {
                prev = s[i-1];
            }
            if(i-2 >= 0)
            {
                prevprev = s[i-2];
            }
            if(i+1 < s.length())
            {
                next = s[i+1];
            }
            if(i+2 < s.length())
            {
                nextnext = s[i+2];
            }
            if(s[i] == prev || s[i] == prevprev) 
            {
                for(int j = 0; j < 26; j++)
                {
                    if(alpha[j] != prev && alpha[j] != prevprev && alpha[j] != next && alpha[j] != nextnext) 
                    {
                        s[i] = alpha[j];
                        break;
                    }
                }
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
