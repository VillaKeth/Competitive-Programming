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

// road construction
int main()
{
    ll n, m, temp1, temp2;
    cin >> n >> m;
    std::set<ll> sp;
    for(int i = 0; i < m; i++)
    {
        cin >> temp1 >> temp2;
        sp.insert(temp1);
        sp.insert(temp2);
    }
    ll notIn = -1;
    for(int i = 1; i <= n; i++)
    {
        if(sp.find(i) == sp.end())
        {
            notIn = i;
            break;
        }
    }
    cout << n-1 << endl;
    for(int i = 1; i <= n; i++)
    {
        if(i == notIn)
        {
            continue;
        }
        cout << notIn << ' ' << i << endl;
    }
    return 0;
}
