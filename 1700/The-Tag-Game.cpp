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

// the tag game
void findBob(vector<vector<long long>>& bruh, vector<bool>& visited, vector<long long>& path, vector<long long>& temp, long long& bob, long long curNode) 
{
	if(visited[curNode])
	{
		return;
	}
	visited[curNode] = true;
	temp.push_back(curNode);
	if(curNode == bob)
	{
		path = temp;
		return;
	}
	for(int i = 0; i < bruh[curNode].size(); i++)
	{
		findBob(bruh, visited, path, temp, bob, bruh[curNode][i]);
	}
	temp.pop_back();
}
 
void dfs(vector<vector<long long>>& bruh, vector<bool>& visited, long long& forbidden, long long& max, long long curNode, long long curDepth)
{
	if(visited[curNode] || curNode == forbidden)
	{
		return;
	}
	visited[curNode] = true;
	max = std::max(max, curDepth);
	for(int i = 0; i < bruh[curNode].size(); i++)
	{
		dfs(bruh, visited, forbidden, max, bruh[curNode][i], curDepth+1);
	}
}
 
int main()
{
	long long n, x, temp1, temp2;
	cin >> n >> x;
	x--;
	vector<vector<long long>> bruh(n);
	for(int i = 0; i < n-1; i++)
	{
		cin >> temp1 >> temp2;
		temp1--;
		temp2--;
		bruh[temp1].push_back(temp2);
		bruh[temp2].push_back(temp1);
	}
	vector<bool> visited(n, false);
	vector<long long> path;
	vector<long long> temp;
	findBob(bruh, visited, path, temp, x, 0);
	visited.clear();
	visited.resize(n, false);
	long long start = std::ceil((double)path.size()/2);
	long long forbidden = start-1;
	long long max = INT_MIN;
	dfs(bruh, visited, path[forbidden], max, path[start], start);
	cout << max*2;
	return 0;
}
