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

// make it alternating
int main()
{
    ll t;
    std::string s;
    vector<ll> factorials(200005, 1);
    ll multi = 1;
    for(ll i = 1; i <= 200000; i++)
    {
        multi = (multi*i)%MODDY2;
        factorials[i] = multi;
    }
    cin >> t;
    while(t--)
    {
        cin >> s;
        ll deletey = 0;
        ll comby = 1;
        ll prev = -1;
        ll count = 0;
        vector<ll> consecutive;
        for(int i = 0; i < s.length()-1; i++)
        {
            if(s[i] == s[i+1])
            {
                deletey++;
            }
        }
        for(int i = 0; i < s.length(); i++)
        {
            if(s[i] == prev)
            {
                if(!count)
                {
                    count += 2;
                }
                else
                {
                    count++;
                }
            }
            else
            {
                if(count > 1)
                {
                    consecutive.pb(count);
                }
                prev = s[i];
                count = 0;
            }
        }
        if(count > 1)
        {
            consecutive.pb(count);
        } 
        if(consecutive.size() == 0)
        {
            comby = 1;
        }
        else if(consecutive.size() == 1)
        {
            comby = factorials[consecutive[0]];
        }
        else
        {   
            for(int i = 0; i < consecutive.size(); i++)
            {
                comby = (comby*consecutive[i])%MODDY2;
            }
            comby = (comby*(factorials[deletey]))%MODDY2;
        }
        cout << deletey << ' ' << comby%MODDY2 << endl;
    }
    return 0;
}
