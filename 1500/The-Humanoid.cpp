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

// the humanoid
ll checkPermutations(vector<ll>& arr, vector<ll>& prefix, vector<ll>& permutation, ll h)
{
    ll prev = 0;
    ll max = 0;
    ll firstGreater = 0;
    ll i = 0;
    while(i < 4)
    {
        do
        {
            prev = firstGreater;
            firstGreater = std::upper_bound(arr.begin(), arr.end(), h-1)-arr.begin()-1;
            h += prefix[firstGreater]-prefix[prev];
            max = std::max(max, firstGreater);
        } while (firstGreater != prev);
        if(i < 3)
        {
            h *= permutation[i];
        }
        i++;
    }
    return max;
}

int main()
{
    ll t, n, h;
    cin >> t;
    while(t--)
    {
        cin >> n >> h;
        vector<ll> arr(n+1);
        vector<ll> prefix(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        std::sort(arr.begin(), arr.end());
        ll sum = 0;
        for(int i = 1; i <= n; i++)
        {
            sum += arr[i]/2;
            prefix[i] = sum;
        }
        vector<vector<ll>> permutations = {{2, 2, 3}, {2, 3, 2}, {3, 2, 2}};
        ll max = 0;
        for(int i = 0; i < 3; i++)
        {
            max = std::max(max, checkPermutations(arr, prefix, permutations[i], h));
        }
        cout << max << endl;
    }
    return 0;
}
