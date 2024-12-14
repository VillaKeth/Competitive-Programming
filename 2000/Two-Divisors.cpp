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

// two divisors
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
 
int main()
{
    ll n;
    cin >> n;
    vector<ll> arr(n);
    vector<pair<ll, ll>> sieve(1e7+2, {-1, -1});
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for(int i = 2; i < 1e7+2; i++)
    {
        if(sieve[i].first != -1)
        {
            continue;
        }
        for(int j = 2*i; j < 1e7+2; j+=i)
        {
            if(j/i != 1 && sieve[j].first == -1 && gcd(i, j/i) == 1)
            {
                sieve[j].first = i;
                sieve[j].second = j/i;
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout << sieve[arr[i]].first << ' ';
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << sieve[arr[i]].second << ' ';
    }
    return 0;
}
