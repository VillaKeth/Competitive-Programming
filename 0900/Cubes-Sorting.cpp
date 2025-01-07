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

// cubes sorting
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n; 
        vector<ll> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        bool flag = true;
        for(int i = n-1; i > 0; i--)
        {
            if(arr[i] >= arr[i-1])
            {
                flag = false;
            }
        }
        flag ? cout << "NO" << endl : cout << "YES" << endl;
    }
    return 0;
}
