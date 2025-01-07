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

// maximum crossings (easy version)
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        vector<ll> list(n+1, 0);
        ll crossings = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
            list[bruh[i]]++;
        }
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                if(bruh[j] < bruh[i])
                {
                    crossings++;
                }
            }
            crossings += (list[i+1]*(list[i+1]-1))/2;
        }
        cout << crossings << endl;
    }
    return 0;
}
