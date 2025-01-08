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

// round dance
std::vector<long long> link(200001);
std::vector<long long> size(200001, 1);

long long find(long long x)
{
	while(x != link[x])
	{
		x = link[x];
	}
	return x;
}

bool same(long long a, long long b)
{
	return find(a) == find(b);
}

void unite(long long a, long long b)
{
	a = find(a);
	b = find(b);
	if(size[a] < size[b])  
	{
		std::swap(a, b);
	}
	size[a] += size[b];
	link[b] = a;
}

int main()
{
	long long t, n, temp;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n;
		std::vector<std::set<long long>> neighbors(n);
		for(int i = 0; i < n; i++)
		{
			link[i] = i;
		}
		for(int i = 0; i < n; i++)
		{
			std::cin >> temp;
			temp--;
			neighbors[i].insert(temp);
			neighbors[temp].insert(i);
			if(!same(i, temp))
			{
				unite(i, temp);
			}
		}
		long long max = 0;
		long long count = 0;
		std::set<long long> sp;
		for(int i = 0; i < n; i++)
		{
			sp.insert(find(i));
		}
		max = sp.size();
		long long min = max;
		sp.clear();
		for(int i = 0; i < n; i++)
		{
			long long findy = find(i);
			if(sp.find(findy) == sp.end() && neighbors[i].size() < 2)
			{
				sp.insert(findy);
				count++;
			}
		}
		if(count >= 2)
		{
			min -= count-1;
		}
		std::cout << min << ' ' << max << std::endl;
	}
	return 0;
}
