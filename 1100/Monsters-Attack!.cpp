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

// monsters attack!
int main() 
{
	ll t, n, k, temp;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n >> k;
		std::vector<ll> health(n);
		std::priority_queue<std::pair<ll, ll>> pq;
		for(int i = 0; i < n; i++)
		{
			std::cin >> health[i];
		}
		for(int i = 0; i < n; i++)
		{
			std::cin >> temp;
			if(temp > 0)
			{
				temp = -temp;
			}
			pq.push({temp, health[i]});
		}
		ll guy = 0;
		ll boolets = k;
		bool flag = true;
		while(!pq.empty())
		{
			if(boolets >= pq.top().second)
			{
				boolets -= pq.top().second; 
				pq.pop();
			}
			else
			{
				ll tempf = pq.top().first;
				ll temps = pq.top().second-boolets;
				boolets -= pq.top().second;
				pq.pop();
				pq.push({tempf, temps});
				boolets = k;
				guy--;
			}
			if(guy <= pq.top().first)
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
