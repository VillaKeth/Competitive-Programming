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

// polandball and forest
std::vector<long long> link(10001);
std::vector<long long> size(10001, 1);

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
	long long n, temp;
	std::cin >> n;
	for(int i = 0; i < n; i++)
	{
		link[i] = i;
	}
	for(int i = 0; i < n; i++)
	{
		std::cin >> temp;
		temp--;
		if(!same(i, temp))
		{
			unite(i, temp);
		}
	}
	std::set<long long> sp;
	for(int i = 0; i < n; i++)
	{
		sp.insert(find(i)); // need to do this if you don't do path compression
	}
	std::cout << sp.size();
	return 0;
}
