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

// saraga
int main()
{
    std::string s, t, ans;
    cin >> s >> t;
    vector<ll> furthest(26, -1);
    for(int i = 0; i < t.length()-1; i++)
    {
        furthest[t[i]-'a'] = i;
    }
    ll shortest = INT_MAX;
    ll start = -1, end = -1;
    for(int i = 1; i < s.length(); i++)
    {
        if(furthest[s[i]-'a'] != -1 && i+(t.length()-furthest[s[i]-'a']) < shortest)
        {
            shortest = i+(t.length()-furthest[s[i]-'a']);
            start = i;
            end = furthest[s[i]-'a'];
        }
    }
    for(int i = 0; i < start; i++)
    {
        ans += s[i];
    }
    for(int i = end; i < t.length(); i++)
    {
        ans += t[i];
    }
    shortest == INT_MAX ? cout << -1 : cout << ans;
    return 0;
}
