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
#define pair std::pair
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1e9+7;
const ll MODDY2 = 998244353;
const ll MODDY3 = 1e8;

// dijkstra?
struct compare  
{  
	bool operator()(const pair<long long, long long>& l, const pair<long long, long long>& r)  
    {  
    	return l.first > r.first;  
    }  
};

void dfs(vector<vector<pair<long long, long long>>>& bruh, vector<vector<long long>>& megabruh, vector<long long>& path, vector<bool>& visited, long long& minDistance, long long curNode, long long curDistance)
{
	path.push_back(curNode+1); // due to 1-indexing
	visited[curNode] = true;
	if(curNode == bruh.size()-1 && curDistance == minDistance) 
	{
		megabruh.push_back(path);
		return;
	}
	if(curDistance > minDistance) // strong heuristic
	{
		path.pop_back(); 
		visited[curNode] = false;
		return;
	}
	for(int i = 0; i < bruh[curNode].size(); i++)
	{
		if(!visited[bruh[curNode][i].second])
		{
			dfs(bruh, megabruh, path, visited, minDistance, bruh[curNode][i].second, curDistance+bruh[curNode][i].first);
		}
	}
	visited[curNode] = false;
	path.pop_back();
}

int main()
{
	long long n, m, temp1, temp2, weight;
	cin >> n >> m;
	vector<vector<pair<long long, long long>>> bruh(n);
	std::priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, compare> pq;
	for(int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2 >> weight;
		temp1--;
		temp2--;
		bruh[temp1].push_back({weight, temp2});
		bruh[temp2].push_back({weight, temp1});
	}
	vector<bool> visited(n, false);
	vector<long long> distance(n, LLONG_MAX);
	pq.push({0, 0}); // starting point is 0, and the starting weight is 0 too
	while(!pq.empty())
	{
		long long w = pq.top().first; // weight is first
		long long v = pq.top().second; // next node is second
		visited[v] = true;
		if(w < distance[v]) // needed since we don't discriminately add specific nodes, so a later weight that is processed can be worse than the global minimum
		{
			distance[v] = w;
		}
		for(int j = 0; j < bruh[v].size(); j++)
		{
			if(!visited[bruh[v][j].second])
			{
				pq.push({w+bruh[v][j].first, bruh[v][j].second}); // push the new weight at the node, then we push said node as well
			}
		}
		pq.pop();
	}

	long long minDistance = distance[n-1];
	if(minDistance == LLONG_MAX) // no path
	{
		cout << -1 << endl;
	}
	else
	{
		vector<long long> path;
		vector<vector<long long>> megabruh;
		vector<bool> visited2(n, false);
		dfs(bruh, megabruh, path, visited2, minDistance, 0, 0);
		for(int i = 0; i < megabruh[0].size(); i++)
		{
			cout << megabruh[0][i] << ' ';
		}
		cout << endl;
	}
	return 0;
}

