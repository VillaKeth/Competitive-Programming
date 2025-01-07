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

// ahahahahahahahaha
int main()
{
    ll t, n, temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll zeros = 0;
        ll ones = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(!temp)
            {
                zeros++;
            }
            else
            {
                ones++;
            }
        }
        if(zeros >= ones)
        {
            cout << n/2 << endl;
            for(int i = 0; i < n/2; i++)
            {
                cout << 0 << ' '; 
            }
            cout << endl;
        }
        else
        {
            if((n/2)&1)
            {
                cout << (n/2)+1 << endl;
                for(int i = 0; i < (n/2)+1; i++) // must be true if reaches here that there are (n/2)+1 ones
                {
                    cout << 1 << ' ';
                }
                cout << endl;
            }
            else
            {
                cout << n/2 << endl;
                for(int i = 0; i < n/2; i++)
                {
                    cout << 1 << ' ';
                }
                cout << endl;
            }
        }
    }
    return 0;
}
