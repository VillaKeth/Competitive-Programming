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

// spanning tree with maximum degree
int main()
{
	long long n, m, temp1, temp2;
	cin >> n >> m;
	vector<vector<long long>> bruh(n);
	for(int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		temp1--;
		temp2--;
		bruh[temp1].push_back(temp2);
		bruh[temp2].push_back(temp1);
	}
	long long maxNodes = 0;
	long long node = 0;
	for(int i = 0; i < bruh.size(); i++)
	{
		if((long long)bruh[i].size() > maxNodes)
		{
			maxNodes = (long long)bruh[i].size();
			node = i;
		}
	}
	vector<pair<long long, long long>> answer;
	std::queue<pair<long long, long long>> q;
	vector<bool> sp(n, false);
	q.push({node, -1});
	while(!q.empty())
	{
		long long top = q.front().first;
		long long prev = q.front().second;
		q.pop();
		if(sp[top])
		{
			continue;
		}
		sp[top] = true;
		if(prev != -1)
		{
			cout << top+1 << ' ' << prev+1 << '\n';
		}
		for(int i = 0; i < bruh[top].size(); i++)
		{
			q.push({bruh[top][i], top});
		}
	}
	return 0;
}
