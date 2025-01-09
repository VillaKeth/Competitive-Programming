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

// new theatre square
int main()
{
	long long t, n, m, y, x;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n >> m >> x >> y;
		std::vector<std::string> bruh(n);
		long long totalWhite = 0;
		for(int i = 0; i < n; i++)
		{
			std::cin >> bruh[i];
			for(int j = 0; j < m; j++)
			{
				if(bruh[i][j] == '.')
				{
					totalWhite++;
				}
			}
			
		}
		long long ones = 0;
		long long twos = 0;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(bruh[i][j] == '.')
				{
					if(j+1 < m && bruh[i][j+1] == '.')
					{
						bruh[i][j+1] = '*';
						twos++;
					}
					else
					{
						ones++;
					}
					bruh[i][j] = '*';
				}
			}
		}
		if((x*2) < y)
		{
			std::cout << totalWhite*x << std::endl;
		}
		else
		{
			std::cout << (ones*x) + (twos*y) << std::endl;
		}
	}
	return 0;
}
