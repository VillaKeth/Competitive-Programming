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

// t-shirt buying
struct compare
{
	bool operator()(const ll& l, const ll& r)
	{
		return l > r;
	}
};

int main()
{
	ll n, m, buyer;
	cin >> n;
	vector<ll> prices(n);
	vector<std::pair<ll, ll>> colors(n);
	for(int i = 0; i < n; i++)
	{
		cin >> prices[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> colors[i].first;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> colors[i].second;
		if(colors[i].second < colors[i].first)
		{
			std::swap(colors[i].second, colors[i].first);
		}
	}
	std::priority_queue<ll, vector<ll>, compare> pq12;
	std::priority_queue<ll, vector<ll>, compare> pq13;
	std::priority_queue<ll, vector<ll>, compare> pq23;
	std::priority_queue<ll, vector<ll>, compare> pq1;
	std::priority_queue<ll, vector<ll>, compare> pq2;
	std::priority_queue<ll, vector<ll>, compare> pq3;
	for(int i = 0; i < n; i++)
	{
		if(colors[i].first == 1)
		{
			if(colors[i].second == 1)
			{
				pq1.push(prices[i]);
			}
			else if(colors[i].second == 2)
			{
				pq12.push(prices[i]);
			}
			else
			{
				pq13.push(prices[i]);
			}
		}
		else if(colors[i].first == 2)
		{
			if(colors[i].second == 2)
			{
				pq2.push(prices[i]);
			}
			else
			{
				pq23.push(prices[i]);
			}
		}
		else
		{
			pq3.push(prices[i]);
		}
	}
	cin >> m;
	for(int i = 0; i < m; i++)
	{
		cin >> buyer;
		ll min = INT_MAX;
		if(buyer == 1)
		{
			if(!pq1.empty())
			{
				min = std::min(min, pq1.top());
			}
			if(!pq12.empty())
			{
				min = std::min(min, pq12.top());
			}
			if(!pq13.empty())
			{
				min = std::min(min, pq13.top());
			}
			if(!pq1.empty() && min == pq1.top())
			{
				pq1.pop();
			}
			else if(!pq12.empty() && min == pq12.top())
			{
				pq12.pop();
			}
			else
			{
				if(!pq13.empty())
				{
					pq13.pop();
				}
			}
		}
		else if(buyer == 2)
		{
			if(!pq2.empty())
			{
				min = std::min(min, pq2.top());
			}
			if(!pq12.empty())
			{
				min = std::min(min, pq12.top());
			}
			if(!pq23.empty())
			{
				min = std::min(min, pq23.top());
			}
			if(!pq2.empty() && min == pq2.top())
			{
				pq2.pop();
			}
			else if(!pq12.empty() && min == pq12.top())
			{
				pq12.pop();
			}
			else
			{
				if(!pq23.empty())
				{
					pq23.pop();
				}
			}
		}
		else
		{
			if(!pq3.empty())
			{
				min = std::min(min, pq3.top());
			}
			if(!pq23.empty())
			{
				min = std::min(min, pq23.top());
			}
			if(!pq13.empty())
			{
				min = std::min(min, pq13.top());
			}
			if(!pq3.empty() && min == pq3.top())
			{
				pq3.pop();
			}
			else if(!pq23.empty() && min == pq23.top())
			{
				pq23.pop();
			}
			else
			{
				if(!pq13.empty())
				{
					pq13.pop();
				}
			}
		}
		if(min == INT_MAX)
		{
			cout << -1 << ' ';
		}
		else
		{
			cout << min << ' ';
		}
	}
	return 0;
}
