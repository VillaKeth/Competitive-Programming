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

// slay the dragon
int main()
{
	ll n, m, x, y;
	cin >> n;
	ll sum = 0;
	vector<ll> heroes(n);
	for(int i = 0; i < n; i++)
	{
		cin >> heroes[i];
		sum += heroes[i];
	}
	std::sort(heroes.begin(), heroes.end());
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> x >> y;
		auto hero = std::lower_bound(heroes.begin(), heroes.end(), x);
		if(hero == heroes.end())
		{
			hero--;
		}
		ll count1 = 0;
		ll count2 = LLONG_MAX;
		sum -= heroes[hero-heroes.begin()];
		if(heroes[hero-heroes.begin()] < x)
		{
			count1 += x-heroes[hero-heroes.begin()];
		}
		if(sum < y)
		{
			count1 += y-sum;
		}
		sum += heroes[hero-heroes.begin()];
		if(hero != heroes.begin())
		{
			hero--;
			count2 = 0;
			sum -= heroes[hero-heroes.begin()];
			if(heroes[hero-heroes.begin()] < x)
			{	
				count2 += x-heroes[hero-heroes.begin()];
			}
			if(sum < y)
			{
				count2 += y-sum;
			}
			sum += heroes[hero-heroes.begin()];
		}
		cout << std::min(count1, count2) << endl;
	}
	return 0;
}
