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

// news distribution
vector<ll> link(500001);
vector<ll> size(5000001, 1);

ll find(ll x)
{
	while(x != link[x])
	{
		x = link[x];
	}
	return x;
}

bool same(ll a, ll b)
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
	ll n, m, mtemp, temp, origin;
	cin >> n >> m;
	for(int i = 0; i < n; i++)
	{
		link[i] = i;
	}
	for(int i = 0; i < m; i++)
	{
		cin >> mtemp;
		for(int j = 0; j < mtemp; j++)
		{
			cin >> temp;
			temp--;
			if(j == 0)
			{
				origin = temp;
			}
			else
			{
				if(!same(origin, temp))
				{
					unite(origin, temp);
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
	{
		cout << size[find(i)] << ' ';
	}
	return 0;
}
