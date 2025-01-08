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

// black circles
int main()
{
	ll t, n, x, y, xi, yi;
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool flag = true;
		vector<std::pair<ll, ll>> bruh(n);
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			bruh[i] = {x, y};
		}
		cin >> x >> y >> xi >> yi;
		ll dist = (std::abs(xi-x)*std::abs(xi-x))+(std::abs(yi-y)*std::abs(yi-y));
		for(int i = 0; i < n; i++)
		{
			ll tempD = (std::abs(xi-bruh[i].first)*std::abs(xi-bruh[i].first))+(std::abs(yi-bruh[i].second)*std::abs(yi-bruh[i].second));
			if(tempD <= dist)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
