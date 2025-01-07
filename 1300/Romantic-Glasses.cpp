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

// romantic glasses 
int main()
{
    ll t, n, temp;
    cin >> t;
    while(t--)
    {
        cin >> n;
        std::set<ll> sp;
        sp.insert(0); // edge case like {5, 5}
        ll sum = 0;
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            if(i&1)
            {
                sum -= temp;
            }
            else
            {
                sum += temp;
            }
            if(sp.find(sum) != sp.end())
            {
                flag = true;
            }
            sp.insert(sum);
        }
        flag ? cout << "YES" << endl : cout << "NO" << endl;
    }
    return 0;
}
