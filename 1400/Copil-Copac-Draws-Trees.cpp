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
#define ld long double
#define pb push_back
#define cin std::cin
#define cout std::cout
#define endl '\n'
#define vector std::vector
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// copil copac draws trees 
ll dfs(vector<vector<std::pair<ll, ll>>>& bruh, vector<bool>& visited, ll cur, ll prev)
{
	visited[cur] = true;
	ll max = 0;
	for(int i = 0; i < bruh[cur].size(); i++)
	{
		if(!visited[bruh[cur][i].first])
		{
			if(bruh[cur][i].second < prev)
			{
				max = std::max(max, dfs(bruh, visited, bruh[cur][i].first, bruh[cur][i].second)+1);
			}
			else
			{
				max = std::max(max, dfs(bruh, visited, bruh[cur][i].first, bruh[cur][i].second));	
			}
		}
	}
	return max;
}

int main()
{
	ll t, n, u, v;
	cin >> t;
	while(t-- > 0)
	{
		cin >> n;
		vector<vector<std::pair<ll, ll>>> bruh(n);
		for(int i = 0; i < n-1; i++)
		{	
			cin >> u >> v;
			u--;
			v--;
			bruh[u].pb({v, i});
			bruh[v].pb({u, i});
		}
		vector<bool> visited(n, false);
		ll max = 0;
		ll curDepth = 0;
		cout << dfs(bruh, visited, 0, -1)+1 << endl;
	}
	return 0;
}
