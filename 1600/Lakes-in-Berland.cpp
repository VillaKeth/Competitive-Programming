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

// lakes in berland 
vector<ll> link(2501);
vector<ll> size(2501, 1);

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

void dfs(vector<std::string>& bruh, vector<bool>& visited, bool& ocean, std::pair<ll, ll> cur)
{
	if(visited[(cur.first*bruh[0].size())+cur.second])
	{
		return;
	}
	visited[(cur.first*bruh[0].size())+cur.second] = true;
	if(cur.first+1 < bruh.size() && bruh[cur.first+1][cur.second] == '.' && !visited[((cur.first+1)*bruh[0].size())+cur.second])
	{
		if(!same((cur.first*bruh[0].size())+cur.second, ((cur.first+1)*bruh[0].size())+cur.second))
		{
			unite((cur.first*bruh[0].size())+cur.second, ((cur.first+1)*bruh[0].size())+cur.second);
		}
		dfs(bruh, visited, ocean, {cur.first+1, cur.second});
	}
	if(cur.first-1 >= 0 && bruh[cur.first-1][cur.second] == '.' && !visited[((cur.first-1)*bruh[0].size())+cur.second])
	{
		if(!same((cur.first*bruh[0].size())+cur.second, ((cur.first-1)*bruh[0].size())+cur.second))
		{
			unite((cur.first*bruh[0].size())+cur.second, ((cur.first-1)*bruh[0].size())+cur.second);
		}
		dfs(bruh, visited, ocean, {cur.first-1, cur.second});
	}
	if(cur.second+1 < bruh[0].size() && bruh[cur.first][cur.second+1] == '.' && !visited[(cur.first*bruh[0].size())+(cur.second+1)])
	{
		if(!same((cur.first*bruh[0].size())+cur.second, (cur.first*bruh[0].size())+(cur.second+1)))
		{
			unite((cur.first*bruh[0].size())+cur.second, ((cur.first*bruh[0].size())+(cur.second+1)));
		}
		dfs(bruh, visited, ocean, {cur.first, cur.second+1});
	}
	if(cur.second-1 >= 0 && bruh[cur.first][cur.second-1] == '.' && !visited[(cur.first*bruh[0].size())+(cur.second-1)])
	{
		if(!same((cur.first*bruh[0].size())+cur.second, (cur.first*bruh[0].size())+(cur.second-1)))
		{
			unite((cur.first*bruh[0].size())+cur.second, ((cur.first*bruh[0].size())+(cur.second-1)));
		}
		dfs(bruh, visited, ocean, {cur.first, cur.second-1});
	}
	if(cur.first+1 == bruh.size() || cur.first-1 < 0 || cur.second+1 == bruh[0].size() || cur.second-1 < 0)
	{
		ocean = true;
	}
}


int main()
{
	ll n, m, k, lakes(0);
	cin >> n >> m >> k;
	vector<std::string> bruh(n);
	for(int i = 0; i < n*m; i++)
	{
		link[i] = i;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> bruh[i];
	}
	vector<bool> visited(n*m, false);
	std::set<std::pair<ll, ll>> sp; // {size, lake representative}
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(bruh[i][j] == '.')
			{
				if(!visited[(i*m)+j])
				{
					bool ocean = false;
					dfs(bruh, visited, ocean, {i, j});
					if(!ocean)
					{
						lakes++;
						sp.insert({size[find((i*m)+j)], find((i*m)+j)});
					}
				}
			}
		}
	}
	auto iter = sp.begin();
	ll cells = 0;
	while(lakes > k)
	{
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(find((i*m)+j) == (*iter).second)
				{
					bruh[i][j] = '*';
					cells++;
				}
			}
		}
		iter++;
		lakes--;
	}
	cout << cells << endl;
	for(auto i : bruh)
	{
		cout << i << endl;
	}
	return 0;
}
