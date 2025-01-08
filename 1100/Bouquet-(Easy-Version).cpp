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

// boquet (easy version)
int main()
{
	long long t, n, m;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n >> m;
		std::vector<long long> bruh(n);
		for(int i = 0; i < n; i++)
		{
			std::cin >> bruh[i];
		}
		std::sort(bruh.begin(), bruh.end());
		long long start = 0;
		long long mover = 0;
		long long curSum = 0;
		long long max = 0;
		while(mover < n)
		{
			long long diff = bruh[mover]-bruh[start];
			curSum += bruh[mover];
			while((diff > 1 || curSum > m) && start <= mover)
			{
				curSum -= bruh[start];
				start++;
				diff = bruh[mover]-bruh[start];
			}
			max = std::max(max, curSum);
			mover++;
		}
		std::cout << max << std::endl;
	}
	return 0;
}
