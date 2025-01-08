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
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// mortal kombat tower
ll dfs(vector<ll>& bruh, vector<vector<vector<ll>>>& dp, ll index, bool turn, ll bosses)
{
	if(index == bruh.size())
	{
		return 0;
	}
	if(dp[index][turn][bosses] != -1)
	{
		return dp[index][turn][bosses];
	}
	ll skip = INT_MAX;
	ll take = INT_MAX;
	if(bosses == 1)
	{
		skip = dfs(bruh, dp, index, !turn, 0);
	}
	if(bosses == 2)
	{
		take = dfs(bruh, dp, index, !turn, 0);
	}
	else
	{	
		if(turn && bruh[index]) // friend
		{
			take = dfs(bruh, dp, index+1, turn, bosses+1)+1;
		}
		else // me
		{
			take = dfs(bruh, dp, index+1, turn, bosses+1);
		}
	}
	dp[index][turn][bosses] = std::min(take, skip);
	return dp[index][turn][bosses];
}

int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> bruh(n);
		vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(2, vector<ll>(3, -1)));
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
		}
		bool turn = true;
		ll bosses = 0;
		cout << dfs(bruh, dp, 0, turn, 0) << endl;
	}
	return 0;
}
