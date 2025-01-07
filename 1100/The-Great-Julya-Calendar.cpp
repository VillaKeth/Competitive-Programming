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

// the great julya calender 
ll dfs(vector<ll>& dp, ll cur)
{
	if(!cur)
	{
		return 0;
	}
	if(dp[cur] != -1)
	{
		return dp[cur];
	}
	ll tempCur = cur;
	ll take = INT_MAX;
	while(tempCur != 0)
	{
		ll minus = tempCur%10;
		if(minus <= cur && minus)
		{
			take = std::min(take, 1+dfs(dp, cur-minus));
		}
		tempCur /= 10;
	}
	dp[cur] = take;
	return dp[cur];
}

int main() 
{
	ll n; 
	cin >> n;
	vector<ll> dp(n+1, -1);
	cout << dfs(dp, n);
	return 0;
}
