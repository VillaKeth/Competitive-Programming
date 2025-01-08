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

// learning languages
vector<ll> link(101);
vector<ll> size(101, 1);
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

int main()
{
	ll n, m, tempn, tempm, zeroes(0);
	cin >> n >> m;
	vector<vector<ll>> bruh(m);
	for(int i = 0; i < n; i++)
	{
		link[i] = i;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> tempn;
		if(!tempn)
		{
			zeroes++;
		}
		for(int j = 0; j < tempn; j++)
		{
			cin >> tempm;
			tempm--;
			bruh[tempm].pb(i);
		}
	}
	for(int i = 0; i < m; i++)
	{
		ll size = bruh[i].size()-1;
		for(int j = 0; j < size; j++)
		{
			if(!same(bruh[i][j], bruh[i][j+1]))
			{
				unite(bruh[i][j], bruh[i][j+1]);
			}
		}
	}
	std::set<ll> sp;
	for(int i = 0; i < n; i++)
	{	
		sp.insert(find(link[i]));
	}
	cout << std::max((ll)sp.size()-1, zeroes);
	return 0;
}
