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

// robert hood and mrs hood
int main()
{
    ll t, n, d, k, l, r;
    cin >> t;
    while(t--)
    {
        cin >> n >> d >> k;
        vector<ll> overlap(n-d+2, 0); // extra for past r and 0
        for(int i = 0; i < k; i++)
        {
            cin >> l >> r;
            l = std::max(1LL, l-d+1);
            r = std::min(r, n-d+1);
            overlap[l]++;
            if(r+1 <= n-d+1)
            {
                overlap[r+1]--;
            }        
        }
        ll momMin = INT_MAX;
        ll momDay = -1;
        ll broMax = INT_MIN;
        ll broDay = -1;
        ll curJobs = 0;
        for(int i = 1; i <= n-d+1; i++)
        {
            curJobs += overlap[i];
            if(curJobs > broMax)
            {
                broMax = curJobs;
                broDay = i;
            }
            if(curJobs < momMin)
            {
                momMin = curJobs;
                momDay = i;
            }
        }
        cout << broDay << ' ' << momDay << endl;
    }
    return 0;
}
