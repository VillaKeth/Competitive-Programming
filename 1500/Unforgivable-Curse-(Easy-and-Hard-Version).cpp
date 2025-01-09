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

// unforgivable curse easy and hard version
void dfs(std::vector<std::vector<long long>>& bruh, std::map<char, long long>& mps, std::map<char, long long>& mpt, std::vector<bool>& visited, std::string& s, std::string& ts, long long curNode)
{
	if(visited[curNode])
	{
		return;
	}
	visited[curNode] = true;
	mps[s[curNode]]++;
	mpt[ts[curNode]]++;
	for(int i = 0; i < bruh[curNode].size(); i++)
	{
		if(!visited[bruh[curNode][i]])
		{
			dfs(bruh, mps, mpt, visited, s, ts, bruh[curNode][i]);
		}
	}
}

int main()
{
	long long t, n, k;
	std::string s, ts;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n >> k >> s >> ts;
		std::vector<std::vector<long long>> bruh(n);
		for(long long i = 0; i < n; i++)
		{
			if(i+k < n)
			{
				bruh[i].push_back(i+k);
				bruh[i+k].push_back(i);
			}
			if(i+k+1 < n)
			{
				bruh[i].push_back(i+k+1);
				bruh[i+k+1].push_back(i);
			}
		}
		std::vector<bool> visited(n, false);
		std::map<char, long long> mps;
		std::map<char, long long> mpt;
		bool flag = 1;
		for(int i = 0; i < n; i++)
		{
			if(!visited[i])
			{
				dfs(bruh, mps, mpt, visited, s, ts, i);
			}
			if(!mps.empty())
			{
				for(auto j : mps)
				{
					if(j.second != mpt[j.first])
					{
						flag = 0;
						i = n;
						break;
					}
				}
				mps.clear();
				mpt.clear();
			}
			
		}
		if(flag)
		{
			std::cout << "YES" << std::endl;
		}
		else
		{
			std::cout << "NO" << std::endl;
		}
	}
	return 0;
}
