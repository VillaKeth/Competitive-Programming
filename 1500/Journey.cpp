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

// journey
void dfs(std::vector<std::vector<ll>>& bruh, std::vector<bool>& visited, long double& allLen, long double& proportion, ll& curLen, ll cur)
{
	visited[cur] = true;
	bool flag = true;
	for(int i = 0; i < bruh[cur].size(); i++)
	{
		if(!visited[bruh[cur][i]])
		{
			flag = false;
			curLen++;
			if(cur != 0)
			{
				proportion /= bruh[cur].size()-1;
				dfs(bruh, visited, allLen, proportion, curLen, bruh[cur][i]);
				proportion *= (bruh[cur].size()-1);
			}
			else
			{
				proportion /= bruh[cur].size();
				dfs(bruh, visited, allLen, proportion, curLen, bruh[cur][i]);
				proportion *= bruh[cur].size();
			}
			curLen--;
		}
	}
	if(flag)
	{
		allLen += (((long double)curLen)*((long double)proportion));
	}
}

int main()
{
	ll n, m, u, v, curLen(0);
	long double allLen(0.0), proportion(1.0);
	std::cin >> n;
	std::vector<std::vector<ll>> bruh(n);
	for(int i = 0; i < n-1; i++)
	{
		std::cin >> u >> v;
		u--;
		v--;
		bruh[u].pb(v);
		bruh[v].pb(u);
	}
	std::vector<bool> visited(n, false);
	dfs(bruh, visited, allLen, proportion, curLen, 0);
	std::cout << std::setprecision(11) << allLen;
	return 0;
}
