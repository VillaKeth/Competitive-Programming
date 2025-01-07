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

// just eat it!
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        ll sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
            sum += bruh[i];
        }
        ll max = 0;
        ll cur = 0;
        ll taken = 0;
        ll left = 0;
        ll right = 0;
        while(right < n)
        {
            cur += bruh[right];
            taken++;
            while(left <= right && cur <= 0 || taken == n) 
            {
                cur -= bruh[left];
                left++;
                taken--;
            }
            max = std::max(max, cur);
            right++;
        }
        sum > max ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
