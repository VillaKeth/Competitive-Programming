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

// pair of topics
int main()
{
	long long n;
	std::cin >> n;
	std::vector<long long> bruh(n);
	std::vector<long long> bruh2(n);
	for(int i = 0; i < 2*n; i++)
	{
		if(i < n)
		{
			std::cin >> bruh[i];
		}
		else
		{
			std::cin >> bruh2[i-n];
		}
	}
	for(int i = 0; i < n; i++)
	{
		bruh[i] = bruh[i]-bruh2[i];
	}
	std::sort(bruh.begin(), bruh.end());
	// need to figure out how to count with two pointers
	long long start = 0;
	long long end = n-1;
	long long counter = 0;
	while(start < end)
	{
		long long sum = bruh[start]+bruh[end];
		if(sum > 0)
		{
			counter += end-start; 
			end--;
		}
		else
		{
			start++;
		}
	}
	std::cout << counter;
}
