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

// boxes packing 
int main()
{
	ll n, m, k;
	cin >> n >> m >> k;
    vector<ll> bruh(n);
    ll start = 0;
    for(int i = 0; i < n; i++)
    {
        cin >> bruh[i];
        if(bruh[i] > k)
        {
            start = i;
        }
    }
    ll end = n;
    ll curBox = 0;
    ll usedBoxes = 0;
    for(int i = n-1; i >= start; i--)
    {
        curBox += bruh[i];
        if(curBox > k)
        {
            curBox = bruh[i];
            usedBoxes++;
        }
        if(usedBoxes == m)
        {
            break;
        }
        end = i;
    }
    cout << n-end;
	return 0;
}
