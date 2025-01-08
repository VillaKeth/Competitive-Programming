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

// mad city 
void bfs(vector<std::pair<bool, vector<ll>>>& bruh, vector<bool>& visited, vector<ll>& dist, ll cur, ll depth)
{
	std::queue<std::pair<ll, ll>> q;
	q.push({cur, depth});
	while(!q.empty())
	{
		ll node = q.front().first;
		ll d = q.front().second;
		q.pop();
		if(visited[node])
		{
			continue;
		}
		visited[node] = true;
		dist[node] = d;
		for(int i = 0; i < bruh[node].second.size(); i++)
		{
			if(!visited[bruh[node].second[i]])
			{
				q.push({bruh[node].second[i], d+1});
			}
		}
	}
}

void findPath(vector<std::pair<bool, vector<ll>>>& bruh, vector<bool>& visited, vector<ll>& path, vector<ll>& tempPath, ll& endPoint, ll cur)
{
	if(visited[cur])
	{
		return;
	}
	visited[cur] = true;
	tempPath.pb(cur);
	if(cur == endPoint)
	{
		path = tempPath;
		tempPath.pop_back();
		return;
	}
	for(int i = 0; i < bruh[cur].second.size(); i++)
	{
		if(!visited[bruh[cur].second[i]])
		{
			findPath(bruh, visited, path, tempPath, endPoint, bruh[cur].second[i]);
		}
	}
	tempPath.pop_back();
}

void findCycle(vector<std::pair<bool, vector<ll>>>& bruh, vector<bool>& visited, std::pair<ll, ll>& cycle, ll cur, ll prev)
{
	if(visited[cur])
	{
		return;
	}
	visited[cur] = true;
	for(int i = 0; i < bruh[cur].second.size(); i++)
	{
		if(!visited[bruh[cur].second[i]])
		{
			findCycle(bruh, visited, cycle, bruh[cur].second[i], cur);
		}
		else
		{
			if(bruh[cur].second[i] != prev)
			{
				cycle.first = cur;
				cycle.second = bruh[cur].second[i];
			}
			
		}
	}
}

int main()
{
	ll t, n, a, b, u, v;
	cin >> t;
	while(t--)
	{
		cin >> n >> a >> b;
		vector<std::pair<bool, vector<ll>>> bruh(n, {false, {}});
		vector<bool> visited(n, false);
		vector<ll> path;
		vector<ll> tempPath;
		vector<ll> val(n, INT_MAX);
		vector<ll> mar(n, INT_MAX);
		std::pair<ll, ll> cycle;
		for(int i = 0; i < n; i++)
		{
			cin >> u >> v;
			u--;
			v--;
			bruh[u].second.pb(v);
			bruh[v].second.pb(u);
		}
		findCycle(bruh, visited, cycle, 0, -1);
		visited.clear();
		visited.resize(n, false);
		findPath(bruh, visited, path, tempPath, cycle.second, cycle.first);
		visited.clear();
		visited.resize(n, false);
		bfs(bruh, visited, mar, a-1, 0);
		visited.clear();
		visited.resize(n, false);
		bfs(bruh, visited, val, b-1, 0);
		for(auto i : path)
		{
			bruh[i].first = true;
		}
		bool flag = false;
		for(int i = 0; i < n; i++)
		{
			if(bruh[i].first && val[i] < mar[i]) // strictly less than
			{
				flag = true;
				break;
			}
		}
		if(flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
