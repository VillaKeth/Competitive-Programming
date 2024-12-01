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

// graph without long directed paths
void dfs(vector<pair<vector<long long>, bool>>& undirected, vector<bool>& visited, long long curNode, bool prevColor)
{
	visited[curNode] = true;
	undirected[curNode].second = !prevColor;
	for(int i = 0; i < undirected[curNode].first.size(); i++)
	{
		if(!visited[undirected[curNode].first[i]])
		{
			dfs(undirected, visited, undirected[curNode].first[i], !prevColor);
		}
	}
}

int main()
{
	long long n, m, temp1, temp2;
	cin >> n >> m;
	vector<pair<vector<long long>, bool>> undirected(n);
	vector<pair<long long, long long>> directed(m);
	vector<char> answer(m, '0');
	for(int i = 0; i < m; i++)
	{
		cin >> temp1 >> temp2;
		temp1--;
		temp2--;
		undirected[temp1].first.push_back(temp2);
		undirected[temp2].first.push_back(temp1);
		directed[i] = {temp1, temp2};
	}
	vector<bool> visited(n, false);
	dfs(undirected, visited, 0, 0); // graph assumed to be connected	
	bool isBi = 1;
	for(int i = 0; i < undirected.size(); i++) // checks if it is bipartite
	{
		for(int j = 0; j < undirected[i].first.size(); j++)
		{
			if(undirected[i].second == undirected[undirected[i].first[j]].second)
			{
				isBi = 0;
				i = undirected.size();
				break;
			}
		}
	}
	if(isBi)
	{
		cout << "YES" << endl;
		for(int i = 0; i < directed.size(); i++)
		{
			temp1 = directed[i].first;
			if(undirected[temp1].second) // if it's one
			{
				answer[i] = '1';
			}
		}
		for(auto i : answer)
		{
			cout << i;
		}
	    cout << endl;
	}
	else
	{
		cout << "NO" << endl;
	}
	return 0;
}
