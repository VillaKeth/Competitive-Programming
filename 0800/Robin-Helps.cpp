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

// robin helps
int main()
{
    ll t, n, k, temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ll gold = 0;
        ll given = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(temp >= k)
            {
                gold += temp;
            }
            if(!temp)
            {
                if(gold > 0)
                {
                    gold--;
                    given++;
                }
            }
        }
        cout << given << endl;
    }
    return 0;
}
