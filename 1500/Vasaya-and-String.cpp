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

// vasaya and string 
int main()
{
    long long n, k;
	std::string s;
	std::cin >> n >> k >> s;
	long long start = 0;
	long long mover = 0;
	long long aCount = 0;
	long long bCount = 0;
	long long max = 0;
	while(mover < n)
	{
		if(s[mover] == 'a')
		{
			aCount++;
		}
		else
		{
			bCount++;
		}
		while(aCount > k && bCount > k)
		{
			if(s[start] == 'a')
			{
				aCount--;
			}
			else
			{
				bCount--;
			}
			start++;
		}
		max = std::max(max, mover-start+1);
		mover++;
	}
	std::cout << max;
    return 0;
}
