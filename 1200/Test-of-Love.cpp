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

// test of love 
int main()
{
	long long t, n, m, k;
	std::string s;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n >> m >> k >> s;
		long long curSum = m;
		bool flag = 1;
		for(int i = 0; i < n; i++)
		{
			curSum--;
			if(s[i] == 'L')
			{
				curSum = m;
			}
			else if(s[i] == 'W')
			{
				if(curSum <= 0)
				{
					k--;
				}
				if(k < 0)
				{
					flag = 0;
					break;
				}
			}
			else
			{
				if(curSum <= 0)
				{
					flag = 0;
					break;
				}
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
