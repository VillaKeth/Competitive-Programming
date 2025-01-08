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
#define endl std::endl
#define vector std::vector
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// valera and elections 
bool dfs(vector<vector<std::pair<ll, ll>>>& bruh, vector<ll>& candidates, ll parent, ll cur, ll problemRoad)
{
	bool childRoad = false;
	for(int i = 0; i < bruh[cur].size(); i++)
	{
		if(bruh[cur][i].first != parent)
		{
			childRoad |= dfs(bruh, candidates, cur, bruh[cur][i].first, bruh[cur][i].second);
		}
	}
	if(!childRoad && problemRoad == 2) 
	{
		candidates.pb(cur);
		childRoad = true;
	}
	return childRoad;
}

int main()
{
	ll n, u, v, w;
	cin >> n;
	vector<vector<std::pair<ll, ll>>> bruh(n);
	vector<bool> visited(n, false);
	vector<ll> candidates;
	for(int i = 0; i < n-1; i++)
	{
		cin >> u >> v >> w;
		u--;
		v--;
		bruh[u].pb({v, w});
		bruh[v].pb({u, w});
	}
	dfs(bruh, candidates, -1, 0, 1);
	cout << candidates.size() << endl;
	for(auto i : candidates)
	{
		cout << i+1 << ' ';
	}
	return 0;
}
