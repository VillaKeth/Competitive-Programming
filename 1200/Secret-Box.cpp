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
#define pb push_back
#define hewwo std::cout << "hewwo" << std::endl;

// secret box
int main()
{
	ll t, x, y, z, k;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> x >> y >> z >> k;
		ll max = 0;
		std::vector<std::tuple<ll, ll, ll>> bruh;
		for(ll i = 1; i*i <= k; i++)
		{
			if(k % i == 0)
			{
				if(i <= x)
				{
					for(ll j = 1; j*j <= k/i; j++)
					{
						if((k/i) % j == 0)
						{
							if((j <= y && (k/i)/j <= z))
							{
								bruh.pb({i, j, (k/i)/j});
							}
							if((j <= z && (k/i)/j <= y))
							{
								bruh.pb({i, (k/i)/j, j});
							}
						}
					}
				}
				if(k/i <= x)
				{
					for(ll j = 1; j*j <= i; j++)
					{
						if(i % j == 0)
						{
							if((j <= y && i/j <= z))
							{
								bruh.pb({k/i, j, i/j});
							}
							if((j <= z && i/j <= y))
							{
								bruh.pb({k/i, i/j, j});
							}
						}
					}
				}
			}
		}
		for(auto i : bruh)
		{
			max = std::max(max, (x-std::get<0>(i)+1)*(y-std::get<1>(i)+1)*(z-std::get<2>(i)+1));
			//std::cout << std::get<0>(i) << ' ' << std::get<1>(i) << ' ' << std::get<2>(i) << std::endl;
		}
		std::cout << max << std::endl;
	}
	return 0;
}
