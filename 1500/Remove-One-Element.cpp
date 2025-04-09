#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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

// remove one element
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n+2);
    vector<ll> dp1(n+2, 1);
    vector<ll> dp2(n+2, 0);
    dp1[0] = 0;
    dp1[n+1] = 0;
    arr[0] = INT_MAX;
    arr[n+1] = INT_MIN;
    for(int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    ll max = 1;
    for(int i = 2; i <= n; i++)
    {
        if(arr[i] > arr[i-1])
        {
            dp1[i] = dp1[i-1]+1;
        }
        max = std::max(max, dp1[i]);
    }
    int i = n;
    while(i >= 1)
    {
        for(int j = i; j > i-dp1[i]; j--)
        {
            dp2[j] = dp1[i];
        }
        i -= dp1[i];
    }
    for(int i = 1; i <= n; i++)
    {
        if(dp2[i] == 1 && arr[i+1] > arr[i-1])
        {
            max = std::max(max, dp2[i-1]+dp2[i+1]);
        }
        else if(dp2[i] > 1 && arr[i+1] > arr[i-1])
        {
            if(dp1[i] == 1)
            {
                max = std::max(max, dp2[i]-1+dp2[i-1]);
            }
            else if(dp1[i] == dp2[i])
            {
                max = std::max(max, dp2[i]-1+dp2[i+1]);
            }
        }
    }
    cout << max << endl;
    return 0;
}
