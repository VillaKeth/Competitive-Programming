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
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// kuriyama mirai's stones
int main()
{
	ll n, m, q, l, r, sum(0);
	cin >> n;
	vector<ll> bruh(n);
	vector<ll> prefix(n+1);
	prefix[0] = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> bruh[i];
		sum += bruh[i];
		prefix[i+1] = sum;
	}
	std::sort(bruh.begin(), bruh.end());
	vector<ll> sprefix(n+1);
	sprefix[0] = 0;
	sum = 0;
	for(int i = 1; i <= n; i++)
	{
		sum += bruh[i-1];
		sprefix[i] = sum;
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> q >> l >> r;
		if(q == 1)
		{
			cout << prefix[r]-prefix[l-1] << endl;
		}
		else
		{
			cout << sprefix[r]-sprefix[l-1] << endl;
		}
	}
	return 0;
}
