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

// yarik and array
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        ll left = 0;
        ll right = 0;
        ll prev = INT_MAX;
        ll max = INT_MIN;
        ll cur = 0;
        while(right < n)
        {
            while((cur < 0) || (prev != INT_MAX && (bruh[right]&1) == (prev&1)) && (left < right))
            {
                cur -= bruh[left];
                left++;
            }  
            cur += bruh[right]; 
            prev = bruh[right];
            max = std::max(max, cur);
            right++;
        }   
        cout << max << endl;
    }
    return 0;
}
