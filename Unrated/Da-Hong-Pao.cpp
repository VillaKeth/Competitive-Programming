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

// da hong pao 
ll dfs(vector<ll>& bruh, vector<vector<ll>>& dp, ll& sum, ll left, ll right, ll index)
{
	if(left > right)
	{
		return sum;
	}
	if(dp[left][right] != -1)
	{
		return dp[left][right];
	}
	
	ll takeFront = bruh[left]*(index+1) + dfs(bruh, dp, sum, left+1, right, index+1);
	ll takeBack = bruh[right]*(index+1) + dfs(bruh, dp, sum, left, right-1, index+1);
	dp[left][right] = std::max(takeFront, takeBack);
	return dp[left][right];
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> bruh(n);
	vector<vector<ll>> dp(n, vector<ll>(n, -1));
	for(int i = 0; i < n; i++)
	{
		cin >> bruh[i];
	}
	
	cout << endl;
	ll sum = 0;
	cout << dfs(bruh, dp, sum, 0, n-1, 0);
	return 0;
}
