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

// rumor
void dfs(std::vector<std::vector<ll>>& bruh, std::vector<bool>& visited, std::vector<std::pair<ll, ll>>& cost, ll curNode)
{
	if(visited[curNode])
	{
		return;
	}
	visited[curNode] = true;
	for(int i = 0; i < bruh[curNode].size(); i++)
	{
		dfs(bruh, visited, cost, bruh[curNode][i]);
	}
}

int main()
{
	ll n, m, u, v, sum(0);
	std::cin >> n >> m;
	std::vector<std::pair<ll, ll>> cost(n);
	std::vector<std::vector<ll>> bruh(n); 
	std::vector<bool> visited(n, false);
	for(int i = 0; i < n; i++)
	{
		std::cin >> u;
		cost[i] = {u, i};
	}
	for(int i = 0; i < m; i++)
	{
		std::cin >> u >> v;
		u--;
		v--;
		bruh[u].pb(v);
		bruh[v].pb(u);
	}
	std::sort(cost.begin(), cost.end());
	for(int i = 0; i < n; i++)
	{
		if(!visited[cost[i].second])
		{
			sum += cost[i].first;
			dfs(bruh, visited, cost, cost[i].second);
		}
	}
	std::cout << sum;
	return 0;
}
