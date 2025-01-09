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

// mr. kitayuta's colorful graph
std::vector<long long> link(101);
std::vector<long long> size(101);

long long find(long long x)
{
	while(x != link[x])
	{
		x  = link[x];
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

void dfs(std::vector<std::vector<long long>>& bruh, long long curNode)
{
	for(int i = 0; i < bruh[curNode].size(); i++)
	{
		if(!same(curNode, bruh[curNode][i]))
		{
			unite(curNode, bruh[curNode][i]);
			dfs(bruh, bruh[curNode][i]);
		}
	}
}


int main()
{
	long long n, m, temp1, temp2, color, q;
	std::cin >> n >> m;
	std::vector<std::vector<std::vector<long long>>> bruh(m, std::vector<std::vector<long long>>(n));
	for(int i = 0; i < m; i++)
	{
		std::cin >> temp1 >> temp2 >> color;
		temp1--;
		temp2--;
		color--;
		bruh[color][temp1].push_back(temp2);
		bruh[color][temp2].push_back(temp1);
	}	
	std::cin >> q;
	for(int i = 0; i < q; i++)
	{
		std::cin >> temp1 >> temp2;
		temp1--;
		temp2--;
		long long count = 0;
		for(int j = 0; j < m; j++)
		{
			for(int k = 0; k < n; k++)
			{
				link[k] = k;
				size[k] = 1;
			}
			dfs(bruh[j], temp1);
			if(same(temp1, temp2))
			{
				count++;
			}
		}
		std::cout << count << std::endl;
	}
	return 0;	
}
