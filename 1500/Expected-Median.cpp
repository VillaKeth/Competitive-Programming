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
#define hewwo std::cout << "hewwo" << std::endl;
#define cin std::cin
#define cout std::cout
#define endl std::endl
#define vector std::vector
const ll MODDY = 1000000007;

// expected median 
vector<ll> inv;
vector<ll> fact;
vector<ll> fact_inv;

ll comb(ll n, ll k)
{
	if (n < 0 || k < 0) return 0;
	if (n < k) return 0;
	return fact[n]* fact_inv[n-k]%MODDY * fact_inv[k]%MODDY;
}

int main()
{
	ll t, n, k;
	cin >> t;
	inv.resize(200002);
	fact.resize(200002);
	fact_inv.resize(200002);
	inv[1] = 1;
	for(int i = 2; i < 200002; i++)
	{
		inv[i] = MODDY-(MODDY/i)*inv[MODDY%i]%MODDY;
	}
	fact[0] = 1; 
	fact_inv[0] = 1; 
	for(int i = 1; i < 200002; i++)
	{
		fact[i] = fact[i-1]*i%MODDY;
		fact_inv[i] = fact_inv[i-1]*inv[i]%MODDY;
	}
	while(t-- > 0)
	{
		cin >> n >> k;
		vector<ll> bruh(n);
		ll zeros = 0;
		ll ones = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
			if(!bruh[i])
			{
				zeros++;
			}
			else
			{
				ones++;
			}
		}
		ll med = (k+1)/2;
		ll count = 0;
		for(int i = med; i <= k; i++)
		{
			count = (count + (comb(ones, i)*comb(zeros, (k-i)))%MODDY)%MODDY;
		}
		cout << count << endl;
	}
	return 0;
}
