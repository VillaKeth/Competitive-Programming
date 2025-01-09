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

// permutation minimization by deque
int main()
{
	long long t, n, temp;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n;
		std::deque<long long> dq;
		for(int i = 0; i < n; i++)
		{
			std::cin >> temp;
			if(!dq.empty() && temp < dq.front())
			{
				dq.push_front(temp);
			}
			else
			{
				dq.push_back(temp);
			}
		}
		while(!dq.empty())
		{
			std::cout << dq.front() << ' ';
			dq.pop_front();
		}
		std::cout << std::endl;
	}
	return 0;
}
