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
const ll MODDY = 1000000007;

// guess the tree 
vector<ll> link(1001);
vector<ll> size(1001, 1);
ll find(ll a)
{
	if(a != link[a])
	{
		link[a] = find(link[a]);
	}
	return link[a];
}

ll same(ll a, ll b)
{
	return find(a) == find(b);
}

void unite(ll a, ll b)
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

void dfs(vector<pair<ll, ll>>& ans, ll cur, ll next)
{
	if(same(cur, next))
	{
		return;
	}
	cout << "? " << cur << ' ' << next << endl;
	cout.flush();
	ll node;
	cin >> node;
	if(cur == node) // directly connected
	{
		ans.pb({cur, next});
		unite(cur, next);
	}
	else
	{
		dfs(ans, node, next);
	}
}

int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<pair<ll, ll>> ans;
		vector<bool> visited(n+1, false);
		for(int i = 1; i <= n; i++)
		{
			link[i] = i;
		}
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				dfs(ans, i, j);
			}
		}
		cout << "! ";
		for(auto i : ans)
		{
			cout <<	i.first << ' ' << i.second << ' ';
		}
		cout << endl;
		cout.flush();
	}
	return 0;
}
