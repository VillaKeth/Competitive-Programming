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

// maximum crossings (hard version)
ll t, n;
vector<ll> bitTree;

void update(ll index, ll val)
{
    while(index <= n)
    {
        bitTree[index] += val;
        index += index & -index;
    }
}

ll sumToX(ll index)
{
    ll sum = 0;
    while(index > 0)
    {
        sum += bitTree[index];
        index -= index & -index;
    }
    return sum;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        vector<ll> list(n+1, 0);
        bitTree.assign(n+1, 0);
        ll crossings = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
            list[bruh[i]]++;
        }
        // from right to left, find how many are strictly less than bruh[i], then add to crossings, then update bruh[i]
        for(int i = n-1; i >= 0; i--)
        {
            ll temp = sumToX(bruh[i]);
            crossings += temp;
            update(bruh[i], 1);
        }
        cout << crossings << endl;
    }
    return 0;
}
