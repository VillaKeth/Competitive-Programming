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

// queries about less or equal elements
int main()
{
	long long n, m;
	std::cin >> n >> m;
	std::vector<long long> a(n);
	std::vector<long long> b(m);
	for(int i = 0; i < n; i++)
	{
		std::cin >> a[i];
	}
	for(int i = 0; i < m; i++)
	{
		std::cin >> b[i];
	}
	std::vector<long long> sortb = b;
	std::sort(a.begin(), a.end());
	std::sort(sortb.begin(), sortb.end());
	std::map<long long, long long> mp;
	long long apoint = 0;
	long long bpoint = 0;
	while(bpoint < m)
	{
		if(mp[sortb[bpoint]])
		{
			bpoint++;
			continue;
		}
		if(sortb[bpoint] >= a[apoint] && apoint < n)
		{
			apoint++;
		}
		else
		{
			mp[sortb[bpoint]] = apoint;
			bpoint++;
		}
	}	
	for(auto i : b)
	{
		std::cout << mp[i] << ' ';
	}
	return 0;
}
