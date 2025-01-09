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

// a balanced problemset?
int main()
{
	long long t, x, n;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> x >> n;
		long long max = 0;
		for(long long i = 1; i*i <= x; i++)
		{
			if(x % i == 0)
			{ 
				if(x/i >= n)
				{
					max = std::max(max, i);
				}
				if(i >= n)
				{
					max = std::max(max, x/i);
				}
			}
		}
		std::cout << max << std::endl;
	}
	return 0;
}
