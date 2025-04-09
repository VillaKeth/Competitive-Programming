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

// woodcutters 
int main()
{
    ll n;
    cin >> n;
    vector<pair<ll, ll>> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i].first >> arr[i].second;
    }
    ll ans = 0;
    ll cur = INT_MIN;
    for(int i = 0; i < arr.size(); i++)
    {
        if(arr[i].first-arr[i].second > cur)
        {
            cur = arr[i].first;
            ans++;
        }
        else if(arr[i].first+arr[i].second > cur && (i == n-1 || arr[i].first+arr[i].second < arr[i+1].first))
        {
            cur = arr[i].first+arr[i].second;
            ans++;
        }
        else
        {
            cur = arr[i].first;
        }
    }
    cout << ans;
    return 0;
}
