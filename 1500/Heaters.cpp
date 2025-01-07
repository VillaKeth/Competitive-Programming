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
const ll MODDY2 = 998244353;

// heaters
int main()
{
	ll n, r, count(0);
	cin >> n >> r;
	vector<ll> heaters(n+1);
	vector<ll> heat(n+1, 0);
	vector<pair<ll, ll>> ranges;
	for(int i = 1; i <= n; i++)
	{
		cin >> heaters[i];
		if(heaters[i] == 1)
		{
			count++;
			ranges.pb({std::max(1LL, i-r+1), std::min(n, i+r-1)});
			for(int j = ranges[ranges.size()-1].first; j <= ranges[ranges.size()-1].second; j++)
			{
				heat[j]++;
			}
		}
	}
	bool flag = true;
	for(int i = 0; i < ranges.size(); i++)
	{
		bool temp = true;
		for(int j = ranges[i].first; j <= ranges[i].second; j++)
		{
			heat[j]--;
		}
		for(int j = ranges[i].first; j <= ranges[i].second; j++)
		{
			if(!heat[j])
			{
				temp = false;
			}
		}
		if(temp) // we can turn off this heater
		{
			count--;
		}
		else // cannot turn off this heater
		{
			for(int j = ranges[i].first; j <= ranges[i].second; j++)
			{
				heat[j]++;
			}
		}
	}
    for(int i = 1; i <= n; i++)
	{
		if(!heat[i])
		{
			flag = false;
			break;
		}
	}
	flag ? cout << count : cout << -1;
	return 0;
}
