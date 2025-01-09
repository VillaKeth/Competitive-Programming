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

// fall down
void dfs(std::vector<std::string>& bruh, long long x, long long& y)
{	
	if(x+1 >= bruh.size() || bruh[x+1][y] == '*' || bruh[x+1][y] == 'o')
	{
		bruh[x][y] = '*';
		return;
	}
	else
	{
		bruh[x][y] = '.';
		dfs(bruh, x+1, y);
	}
}

int main()
{
	long long t, n, m;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n >> m;
		std::vector<std::string> bruh(n);
		for(int i = 0; i < n; i++)
		{
			std::cin >> bruh[i];
		}
		for(long long i = n-1; i >= 0; i--)
		{
			for(long long j = m-1; j >= 0; j--)
			{
				if(bruh[i][j] == '*')
				{
					dfs(bruh, i, j);
				}
			}
		}
		for(auto i : bruh)
		{
			std::cout << i << std::endl;
		}
		std::cout << std::endl;
	}
	return 0;
}
