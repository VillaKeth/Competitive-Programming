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

// hierarchy
int main()	
{
	long long n, m, temp1, temp2, temp3;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		std::cin >> temp1; 
	}
	std::cin >> m;
	std::vector<std::pair<long long, long long>> bruh;
	std::set<long long> sp;
	for(int i = 0; i < m; i++)
	{
		std::cin >> temp1 >> temp2 >> temp3;
		temp2--;
		bruh.push_back({temp3, temp2});
	}
	long long sum = 0;
	std::sort(bruh.begin(), bruh.end());
	for(int i = 0; i < bruh.size(); i++)
	{
		long long weight = bruh[i].first;
		long long node = bruh[i].second;
		if(sp.find(node) != sp.end())
		{
			continue;
		}
		sp.insert(node);
		sum += weight;	
	}
	if(sp.size() == n-1)
	{
		std::cout << sum;
	}
	else
	{
		std::cout << -1;
	}
	return 0;
}
