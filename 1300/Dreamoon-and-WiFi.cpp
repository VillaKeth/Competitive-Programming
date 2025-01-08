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

// dreamoon and wifi
int main()
{
	std::string drazil, dream;
	std::cin >> drazil >> dream;
	std::vector<ll> dra(2, 0);
	std::vector<ll> dre(2, 0);
	for(int i = 0; i < drazil.size(); i++)
	{
		if(drazil[i] == '+')
		{
			dra[0]++;
		}
		else
		{
			dra[1]++;
		}
		if(dream[i] != '?')
		{
			if(dream[i] == '+')
			{
				dre[0]++;
			}
			else
			{
				dre[1]++;
			}
		}
	}
	ll free = dream.length()-dre[0]-dre[1];
	// free choose max whatever, impossible for both to be negative
	ll whatever1 = dra[0]-dre[0];
	ll whatever2 = dra[1]-dre[1];
	ll max = std::max(whatever1, whatever2); 
	ll n = 1;
	ll k = 1;
	ll nk = 1;
	ll total = pow(2, free);
	for(int i = 1; i <= free; i++)
	{
		n *= i;
	}
	for(int i = 1; i <= max; i++)
	{
		k *= i;
	}
	for(int i = 1; i <= (free-max); i++)
	{
		nk *= i;
	}
	ll choosey = n/(k*nk); // should be integer casted
	long double ans = (long double)choosey / (long double)total;
	if(!free && (dra[0] != dre[0] || dra[1] != dre[1]))
	{
		std::cout << std::setprecision(9) << 0;
	}
	else
	{
		std::cout << std::setprecision(9) << ans;
	}
	return 0;
}
