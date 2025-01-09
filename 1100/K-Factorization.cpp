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

// k-factorization
int main()
{
	long long n, k;
	std::cin >> n >> k;
	std::stack<long long> factors;
	for(int i = 2; i*i <= n; i++)
	{
		while(n % i == 0)
		{
			factors.push(i);
			n /= i;
		}
	}
	if(n > 1)
	{
		factors.push(n);
	}
	if(factors.size() < k)
	{
		std::cout << -1;
	}
	else
	{
		int size = factors.size(); // size changes
		for(int i = 0; i < size-k; i++)
		{
			long long temp1 = factors.top();
			factors.pop();
			long long temp2 = factors.top();
			factors.pop();
			factors.push(temp1*temp2);
		}
		while(!factors.empty())
		{
			std::cout << factors.top() << ' ';
			factors.pop();
		}
	}
	return 0;
}
