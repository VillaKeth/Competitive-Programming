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

// beautiful array
int main()
{
	ll t, n, k;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		vector<ll> bruh(n);
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
		}
		std::sort(bruh.begin(), bruh.end());
		std::map<ll, vector<ll>> mp;
		for(int i = 0; i < n; i++)
		{
			ll temp = bruh[i]%k;
			mp[temp].pb(bruh[i]);
		}
		ll odds = 0;
		ll count = 0;
		for(auto i : mp)
		{
			if(i.second.size()&1)
			{
				odds++;
				ll min = INT_MAX;
				ll cur = 0;
				for(int j = 1; j < i.second.size(); j+=2) // sliding window with each odd (technically even) index value!!!
				{
					cur += (i.second[j]-i.second[j-1])/k;
				}
				min = std::min(min, cur);
				for(int j = i.second.size()-1; j > 0; j-=2)
				{
					cur += (i.second[j]-i.second[j-1])/k;
					cur -= (i.second[j-1]-i.second[j-2])/k;
					min = std::min(min, cur);
				}
				count += min;
			}
			else
			{
				for(int j = 0; j < i.second.size(); j+=2)
				{
					count += (i.second[j+1]-i.second[j])/k;
				}

			}
		}
		if(odds > 1)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << count << endl;
		}
	}
	return 0;
}
