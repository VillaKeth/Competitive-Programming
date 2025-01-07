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

// maximum modulo equality
vector<ll> tree(4*1e5+5);
ll t, n, q;

ll gcd(ll a, ll b)
{
    while(b != 0)
    {
        int temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

void build(vector<ll> arr)
{
    for(int i = 0; i < n-1; i++) // leaf nodes
    {
        tree[(n-1)+i] = arr[i];
    }
    for(int i = n-2; i > 0; i--) // parent nodes
    {
        tree[i] = gcd(tree[2*i], tree[(2*i)+1]);
    }
}

ll gcdQuery(ll l, ll r)
{
    l += n-2;
    r += n-2;
    ll temp = 0;
    while(l <= r)
    {
        if(l&1)
        {
            temp = gcd(temp, tree[l]);
            l++;
        }
        if(!(r&1))
        {
            temp =gcd(temp, tree[r]);
            r--;
        }
        l /= 2;
        r /= 2;
    }
    return temp;
}

int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> q;
        vector<ll> arr(n), diff(n-1);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for(int i = 0; i < n-1; i++)
        {
            diff[i] = std::abs(arr[i]-arr[i+1]);
        }
        build(diff);
        ll l, r;
        for(int i = 0; i < q; i++)
        {
            cin >> l >> r;
            if(l == r)
            {
                cout << 0 << ' ';
            }
            else if(l == r-1)
            {
                cout << diff[l-1] << ' ';
            }
            else
            {
                cout << gcdQuery(l, r-1) << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}
