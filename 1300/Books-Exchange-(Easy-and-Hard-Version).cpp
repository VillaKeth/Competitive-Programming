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

// books exchange
vector<ll> link(200001);
vector<ll> size(200001, 1);
ll find(ll a)
{
	while(a != link[a])
	{
		a = link[a];
	}
	return a;
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

void dfs(vector<ll>& bruh, vector<bool>& visited, ll cur)
{
	if(visited[cur])
	{
		return;
	}
	visited[cur] = true;
	if(!same(cur, bruh[cur]))
	{
		unite(cur, bruh[cur]);
	}
	dfs(bruh, visited, bruh[cur]);
}

int main()
{
	ll q, n;
	cin >> q;
	for(int i = 0; i < q; i++)
	{
		cin >> n;
		vector<ll> bruh(n);
		vector<bool> visited(n, false);
		for(int i = 0; i < n; i++)
		{
			link[i] = i;
			size[i] = 1;
		}
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
			bruh[i]--;
		}
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				dfs(bruh, visited, i);
			}
		}
		for(int i = 0; i < n; i++)
		{
			ll temp = find(i);
			cout << size[temp] << ' ';
		}
		cout << endl;
	}
	return 0;
}
