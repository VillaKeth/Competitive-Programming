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

// blue-red permutation
int main() 
{
    ll t, n;
    std::string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        vector<ll> blue;
        vector<ll> red;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        cin >> s;
        for(int i = 0; i < n; i++)
        {
            if(s[i] == 'B')
            {
                blue.pb(bruh[i]);
            }
            else
            {
                red.pb(bruh[i]);
            }
        }
        std::sort(blue.begin(), blue.end());
        std::sort(red.rbegin(), red.rend());
        std::set<ll> sp;
        ll min = 1;
        ll max = n;
        for(int i = 0; i < blue.size(); i++) // minimize blue as much as possible, maximize red as much as possible
        {
            if(blue[i] >= min)
            {
                sp.insert(min);
            }
            min++;
        }
        for(int i = 0; i < red.size(); i++)
        {
            if(red[i] <= max)
            {
                sp.insert(max);
            }
            max--;
        }
        sp.size() == n ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
