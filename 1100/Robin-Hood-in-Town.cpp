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

// robin hood in town
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        ll majority = (n/2)+1;
        ll wealth = 0;
        ll max = -1;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
            wealth += bruh[i];
            max = std::max(max, bruh[i]);
        }
        std::sort(bruh.begin(), bruh.end());
        if(n <= 2)
        {
            cout << -1 << endl;
        }
        else
        {
            ll count = 0;
            for(int i = 0; i < n; i++)
            {
                if(bruh[i]*2*n < wealth)
                {
                    count++;
                }
            }
            if(count >= majority)
            {
                cout << 0 << endl;
            }
            else
            {
                ll start = 0;
                ll end = LLONG_MAX;
                ll mid = start + (end-start)/2;
                wealth -= max;
                max = mid;
                wealth += max;
                count = 0;
                for(int i = 0; i < n; i++)
                {
                    if(bruh[i]*2*n < wealth)
                    {
                        count++;
                    }
                }
                while(start < end)
                {
                    if(count < majority)
                    {
                        start = mid+1;
                    }
                    else
                    {
                        end = mid;
                    }
                    mid = start + (end-start)/2;
                    wealth -= max;
                    max = mid;
                    wealth += max;
                    count = 0;
                    for(int i = 0; i < n; i++)
                    {
                        if(bruh[i]*2*n < wealth)
                        {
                            count++;
                        }
                    }
                }
                for(int i = 0; i < n; i++)
                {
                    wealth -= bruh[i];
                }
                cout << wealth << endl;
            }   
        }
    }
    return 0;
}
