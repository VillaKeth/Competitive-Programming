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
 
// cut ribbon
void dfs(long long n, long long count, long long& a, long long&b, long long& c, long long& max, std::vector<long long>& dp)
{
	if(n < 1 || count+1 <= dp[n])
	{
		return;
    }
	if(n == a || n == b || n == c)
	{
		max = std::max(max, count+1); 
		
	}
	dp[n] = std::max(max, count+1);
	dfs(n-a, count+1, a, b, c, max, dp);
	dfs(n-b, count+1, a, b, c, max, dp);
	dfs(n-c, count+1, a, b, c, max, dp);
}
 
int main()
{
	long long n, a, b, c, max(0);
	std::cin >> n >> a >> b >> c;
	std::vector<long long> sorty(3);
	sorty[0] = a;
	sorty[1] = b;
	sorty[2] = c;
	std::sort(sorty.begin(), sorty.end());
	std::vector<long long> dp(n+1, INT_MIN);
	dfs(n, 0, sorty[0], sorty[1], sorty[2], max, dp);
	std::cout << max;
	return 0;	
}
