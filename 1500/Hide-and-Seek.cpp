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
 
// hide and seek
int main()
{
	long long n, k, x;
	std::cin >> n >> k;
	long long count = 2*(n-1)+n;
	std::vector<std::set<long long>> spair(n);
	std::vector<int> visited(n, 0);
	for(int i = 0; i < k; i++)
	{
		std::cin >> x;
		x--;
		visited[x] = 1;
		if(x-1 >= 0 && visited[x-1])
		{
		    spair[x-1].insert(x);
		}
		if(x+1 < n && visited[x+1])
		{
		    spair[x+1].insert(x);
		}
	}
	for(int i = 0; i < n; i++)
	{
	    count -= (spair[i].size()+visited[i]);
	}
	std::cout << count; 
}
