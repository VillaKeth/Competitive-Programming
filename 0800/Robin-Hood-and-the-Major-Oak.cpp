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

// robin hood and the major oak
int main()
{
    ll t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ll start = n-k+1;
        ll oddCount = 0;
        if(!(start&1) || !(n&1))
        {
            oddCount = (n-start+1)/2;
        }
        else
        {
            oddCount = ((n-start+1)/2)+1;
        }
        if(oddCount&1)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}
