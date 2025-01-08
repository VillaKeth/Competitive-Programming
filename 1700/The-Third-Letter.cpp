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
#include <numeric>
#define ll long long
#define pb push_back
#define hewwo std::cout << "hewwo" << std::endl;

// the third letter 
void dfs(std::vector<std::pair<ll, std::vector<std::pair<ll, ll>>>>& bruh, std::vector<bool>& visited, bool& flag, ll cur)
{
	if(visited[cur])
	{
		return;
	}
	visited[cur] = true;
	for(int i = 0; i < bruh[cur].second.size(); i++)
	{
		if(!visited[bruh[cur].second[i].first])
		{
			bruh[bruh[cur].second[i].first].first = bruh[cur].first+bruh[cur].second[i].second;
			dfs(bruh, visited, flag, bruh[cur].second[i].first);
		}
		else
		{
			if(bruh[cur].first+bruh[cur].second[i].second != bruh[bruh[cur].second[i].first].first)
			{
				flag = false;
			}
		}
	}
}

int main()
{
	ll t, n, m, u, v, d;
	std::cin >> t;
	
	while(t-- > 0)
	{
		std::cin >> n >> m;
		std::vector<std::pair<ll, std::vector<std::pair<ll, ll>>>> bruh(n, {LLONG_MAX, {}});
		std::vector<bool> visited(n, false);
		for(int i = 0; i < m; i++)
		{
			std::cin >> u >> v >> d;
			u--;
			v--;
			bruh[u].second.pb({v, -d});
			bruh[v].second.pb({u, d}); // shouldn't matter either way
		}
		
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				bruh[i].first = 0; // just set it here
				dfs(bruh, visited, flag, i);
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
