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

// call during the journey
struct compare
{
	bool operator()(const pair<ll, ll>& l, const pair<ll, ll>& r)
	{
		return l.first > r.first;
	}
};

ll dijkstra(vector<vector<std::tuple<ll, ll, ll>>> bruh, ll phoneStart, ll phoneEnd, ll& mid)
{
	std::priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, compare> pq;
	vector<ll> distance(bruh.size(), INT_MAX);
	vector<bool> visited(bruh.size(), false);
	pq.push({mid, 0});
	while(!pq.empty())
	{
		ll weight = pq.top().first;
		ll node = pq.top().second;
		pq.pop();
		if(visited[node])
		{
			continue;
		}
		visited[node] = true;
		distance[node] = weight;
		for(int i = 0; i < bruh[node].size(); i++)
		{
			if(!visited[std::get<0>(bruh[node][i])])
			{
				// fix this so it checks whether its better to wait for the phone call to end and then take the bus or if it's better to just walk outright
				if((weight <= phoneStart && weight+std::get<1>(bruh[node][i]) > phoneStart) || (weight >= phoneStart && weight < phoneEnd)) // big ass needs to walk
				{
					if(weight+std::get<2>(bruh[node][i]) < phoneEnd+std::get<1>(bruh[node][i]))
					{
						pq.push({weight+std::get<2>(bruh[node][i]), std::get<0>(bruh[node][i])});
					}
					else
					{
						pq.push({phoneEnd+std::get<1>(bruh[node][i]), std::get<0>(bruh[node][i])});
					}
					
				}
				else
				{
					pq.push({weight+std::get<1>(bruh[node][i]), std::get<0>(bruh[node][i])});
				}
			}
		}
	}
	return distance[bruh.size()-1];
}

int main()
{
	ll t, n, m, eventTime, phoneStart, phoneEnd, u, v, busTime, footTime;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> eventTime >> phoneStart >> phoneEnd;
		vector<vector<std::tuple<ll, ll, ll>>> bruh(n);
		for(int i = 0; i < m; i++)
		{
			cin >> u >> v >> busTime >> footTime;
			u--;
			v--;
			bruh[u].pb({v, busTime, footTime});
			bruh[v].pb({u, busTime, footTime});
		}
		ll start = 0;
		ll end = eventTime;
		ll mid = start + (end-start)/2;
		ll max = -1;
		while(start < end)
		{
			ll val = dijkstra(bruh, phoneStart, phoneEnd, mid);
			if(val <= eventTime)
			{
				max = std::max(max, mid);
				start = mid+1;
			}
			else
			{
				end = mid;
			}
			mid = start + (end-start)/2;
		}
		cout << max << endl;
	}
}
