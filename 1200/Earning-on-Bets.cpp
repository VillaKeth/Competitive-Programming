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
#define endl std::endl
#define vector std::vector
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// earning on bets 
ll gcd(ll a, ll b)
{
	while(a % b != 0)
	{
		ll temp = b;
		b = a%b;
		a = temp;
	}
	return b;
}

ll lcm(ll a, ll b)
{
	return (a*b)/gcd(a, b);
}

int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> bruh(n);
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
		}
		ll cur = bruh[0];
		ll sum = 0;
		for(int i = 1; i < n; i++)
		{
			cur = lcm(cur, bruh[i]);
		}
		for(int i = 0; i < n; i++)
		{
			sum += cur/bruh[i];
		}
		if(cur > sum)
		{
			for(auto i : bruh)
			{
				cout << cur/i << ' ';
			}
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
