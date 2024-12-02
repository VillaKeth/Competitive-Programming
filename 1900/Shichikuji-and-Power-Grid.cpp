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

// shichikuji and power grid 
// union find
vector<long long> link(2001);
vector<long long> size(2001, 1);

long long find(long long x)
{
	while(x != link[x])
	{
		x = link[x];
	}
	return x;
}

bool same(long long a, long long b)
{
	return find(a) == find(b);
}

void unite(long long a, long long b)
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
	long long n;
	cin >> n;
	vector<pair<long long, long long>> coords(n); // coordinates for each vertex
	vector<std::tuple<long long, long long, long long>> bruh; // edge list with weight
	vector<long long> cost(n);
	vector<long long> wire(n);
	for(int i = 0; i < n; i++)
	{
		cin >> coords[i].first >> coords[i].second;
	}
	for(int i = 0; i < n; i++)
	{
		cin >> cost[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> wire[i];
	}
	for(int i = 0; i < n; i++) // connects graph
	{	
		for(int j = 0; j < n; j++)
		{
			if(i == j)
			{
				continue;
			}
			long long sum = (wire[i]+wire[j])*(std::abs(coords[i].first-coords[j].first)+std::abs(coords[i].second-coords[j].second));
			bruh.push_back({sum, i, j});
		}
	}
	for(int i = 0; i < n; i++) // construction node
	{
		bruh.push_back({cost[i], i, n});
	}
	vector<long long> stationsVec;
	vector<pair<long long, long long>> connectionsVec;
	long long yen = 0;
	long long stations = 0;
	long long connections = 0;
	std::sort(bruh.begin(), bruh.end());
	for(int i = 0; i <= n; i++) // note that it is equal to n
	{
		link[i] = i;
	}
	for(int i = 0; i < bruh.size(); i++)
	{
		long long weight = std::get<0>(bruh[i]);
		long long first = std::get<1>(bruh[i]);
		long long second = std::get<2>(bruh[i]);
		if(same(first, second)) 
		{
			continue;
		}
		unite(first, second);
		yen += weight;
		if(first == n || second == n)
		{
			stations++;
			stationsVec.push_back(std::min(first+1, second+1));
		}
		else
		{
			connections++;
			connectionsVec.push_back({first+1, second+1});
		}
	}
	cout << yen << endl;
	cout << stations << endl;
	for(int i = 0; i < stations; i++)
	{
		cout << stationsVec[i] << ' ';
	}
	cout << endl;
	cout << connections << endl;
	for(int i = 0; i < connections; i++)
	{
		cout << connectionsVec[i].first << ' ' << connectionsVec[i].second << endl;
	}
	return 0;
}
