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

// the morning star 
int main()
{
    long long t, n, coord1, coord2;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n;
		long long count = 0;
		std::map<long long, long long> mpx;
		std::map<long long, long long> mpy;
		std::map<long long, long long> mpsp; // positive slope
		std::map<long long, long long> mpsn; // negative slope
		for(int i = 0; i < n; i++)
		{
			std::cin >> coord1 >> coord2;
			mpx[coord1]++;
			mpy[coord2]++;
			mpsp[coord2-coord1]++;
			mpsn[coord2+coord1]++;
		}
		for(auto i : mpx)
		{
			count += (i.second)*(i.second-1);
		}
		for(auto i : mpy)
		{
			count += (i.second)*(i.second-1);
		}
		for(auto i : mpsp)
		{
			count += (i.second)*(i.second-1);
		}
		for(auto i : mpsn)
		{
			count += (i.second)*(i.second-1);
		}
		std::cout << count << std::endl;
	}
    return 0;
}
