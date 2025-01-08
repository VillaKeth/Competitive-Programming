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

// equalize 
int main()
{
    long long t, n;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n;
		std::vector<long long> bruh(n);
		for(int i = 0; i < n; i++)
		{
			std::cin >> bruh[i];
		}
		std::sort(bruh.begin(), bruh.end());
		long long start = 0;
		long long mover = 0;
		long long prevDiff = -1;
		long long diff = 0;
		long long curCount = 0;
		long long max = 0;
		while(mover < n)
		{
			diff = bruh[mover]-bruh[start];
			while(diff > n-1)
			{
				if(diff != prevDiff)
				{
					curCount--;
				}
				start++;
				prevDiff = diff;
				diff = bruh[mover]-bruh[start];
			}
			if(diff != prevDiff)
			{
				curCount++;
			}
			prevDiff = diff;
			max = std::max(max, curCount);
			mover++;
		}
		std::cout << max << std::endl;
	}
    return 0;
}
