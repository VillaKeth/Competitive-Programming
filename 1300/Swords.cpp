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

// swords
ll gcd(ll a, ll b)
{
	while(b != 0)
	{
		ll temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a, b);
}

int main()
{
    ll n;
    cin >> n;
    vector<ll> bruh(n);
    ll max = INT_MIN;
    ll maxCount = 0;
    
    for(int i = 0; i < n; i++)
    {
        cin >> bruh[i];
        max = std::max(max, bruh[i]);

    }
   
    ll GCD = 0;
    for(int i = 0; i < n; i++)
    {
        if (max != bruh[i])
        {
            GCD = gcd(GCD, (max-bruh[i]));
        }
    }
    ll sum = 0;
    for(int i = 0; i < n; i++)
    {
        sum += (max-bruh[i])/GCD;
    }
    if(!GCD) 
    {
        cout << 0 << ' ' << 0;
    }
    else
    {
        cout << sum << ' ' << GCD;
    }
    return 0;
}
