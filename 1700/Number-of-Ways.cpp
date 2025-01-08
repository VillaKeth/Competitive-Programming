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

// number of ways 
int main()
{
	ll n, sum(0);
	cin >> n;
	vector<ll> bruh(n);
	for(int i = 0; i < n; i++)
	{
		cin >> bruh[i];
		sum += bruh[i];
	}
	if(sum%3 != 0)
	{
		cout << 0;
	}
	else
	{
		sum /= 3;
		ll pref = 0;
		ll count = 0;
		ll total = 0;
		for(int i = 0; i < n-1; i++)
		{
			pref += bruh[i];
			if(pref == 2*sum)
			{
				total += count;
			}
			if(pref == sum)
			{
				count++;
			}
		}
		cout << total;
	}
	return 0;
}
