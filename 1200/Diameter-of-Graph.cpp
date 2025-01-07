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

// diameter of graph
int main()
{
    ll t, n, m, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        if(m < n-1 || m > (n*(n-1))/2) // too few or too many edges
        {
            cout << "NO" << endl;
        }
        else
        {
            if(n == 1)
            {
                if(k <= 1)
                {
                    cout << "NO" << endl;
                }
                else
                {
                    cout << "YES" << endl;
                }
            }
            else
            {
                if(m == (n*(n-1))/2) // fully connected, max distance is 1
                {
                    if(k <= 2)
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
                else // star graph, max distance is 2
                {
                    if(k <= 3)
                    {
                        cout << "NO" << endl;
                    }
                    else
                    {
                        cout << "YES" << endl;
                    }
                }
            }
        }
    }
    return 0;
}
