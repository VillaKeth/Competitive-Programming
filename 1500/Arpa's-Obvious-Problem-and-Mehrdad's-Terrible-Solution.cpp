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

// arpa’s obvious problem and mehrdad’s terrible solution
int main()
{
	long long n, x, temp;
	std::cin >> n >> x;
	std::map<long long, long long> mp;
	for(int i = 0; i < n; i++)
	{	
		std::cin >> temp;
		mp[temp]++;
	}
	long long count = 0;
	for(auto i : mp)
	{
		if(i.first == (i.first^x))
		{
			count += ((i.second)*(i.second-1))/2;
		}
		else
		{
			count += i.second*mp[(i.first^x)];
			mp.erase((i.first^x));
		}
	}
	std::cout << count << std::endl;
	return 0;
}
