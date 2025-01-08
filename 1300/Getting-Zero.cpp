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

// getting zero 
ll dfs(vector<vector<ll>>& dp, ll cur, ll count)
{
	if(dp[cur][count] != -1)
	{
		return dp[cur][count];
	}
	if(!cur || count == 15)
	{
		return count;
	}
	ll take = dfs(dp, (cur+1)%32768, count+1);
	ll skip = dfs(dp, (2*cur)%32768, count+1);
	dp[cur][count] = std::min(take, skip);
	return dp[cur][count];
}

int main() 
{ 
    ll n, nummy;
    cin >> n;
    vector<vector<ll>> dp(32769, vector<ll>(16, -1));
    for(int i = 0; i < n; i++)
    {
        cin >> nummy;
		if(dp[nummy][0] == -1)
		{
			dp[nummy][0] = dfs(dp, nummy, 0);
		}
		cout << dp[nummy][0] << ' ';
    }
    return 0;
} 
