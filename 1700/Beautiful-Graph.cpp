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

// beautiful graph
void dfs(vector<pair<vector<unsigned long long>, bool>>& bruh, vector<bool>& visited, unsigned long long curNode, bool prevColor, unsigned long long& blue, unsigned long long& nodeCount)
{
	visited[curNode] = true;
	bruh[curNode].second = !prevColor;
	nodeCount++;
	if(bruh[curNode].second) // blue if true
	{
		blue++;
	}
	for(int i = 0; i < bruh[curNode].first.size(); i++)
	{
		if(!visited[bruh[curNode].first[i]])
		{
			dfs(bruh, visited, bruh[curNode].first[i], !prevColor, blue, nodeCount);
		}
	}
}

int main()
{
	unsigned long long t, n, m, temp1, temp2;
	cin >> t;
	while(t-- > 0)
	{
		cin >> n >> m;
		vector<pair<vector<unsigned long long>, bool>> bruh(n);
		for(int i = 0; i < m; i++)
		{
		    cin >> temp1 >> temp2;
			temp1--;
			temp2--;
			bruh[temp1].first.push_back(temp2);
			bruh[temp2].first.push_back(temp1);
		}
		vector<bool> visited(n, false);
		vector<pair<long long, long long>> countVec;
		for(int i = 0; i < bruh.size(); i++) // graph is not necessarily connected
		{
			if(!visited[i])
			{
				unsigned long long blue = 0;
				unsigned long long nodeCount = 0;
				dfs(bruh, visited, i, 0, blue, nodeCount);
				countVec.push_back({nodeCount, blue});
			}
		}
		bool isBi = 1;
		for(unsigned long long i = 0; i < bruh.size(); i++) 
		{
			for(unsigned long long j = 0; j < bruh[i].first.size(); j++)
			{
				if(bruh[i].second == bruh[bruh[i].first[j]].second) // graph is not bipartite
				{
					isBi = 0;
					i = bruh.size();
					break;
				}
			}
		}
		if(isBi)
		{
			unsigned long long count = 1;
			for(int i = 0; i < countVec.size(); i++)
			{
				unsigned long long first = 1; 
				unsigned long long second = 1;
				for(unsigned long long j = 0; j < countVec[i].second; j++)
				{
					first = (first*2) % MODDY2;
					
				}
				for(unsigned long long j = 0; j < countVec[i].first-countVec[i].second; j++)
				{
					second = (second*2) % MODDY2;
				}
				count = (count * ((first+second)%MODDY2))%MODDY2;
			}
			cout << count << endl;
		}
		else // if graph isn't bipartite, graph can't be beautiful
		{
			cout << 0 << endl;
		}
	}
	return 0;
}
