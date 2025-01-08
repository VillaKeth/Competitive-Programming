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

// divide by three, multiply by two
void dfs(std::map<ll, ll>& mp, vector<ll>& ans, vector<ll>& temp, ll& n, ll& count, ll cur)
{
	if(count == n)
	{
		ans = temp;
		return;
	}
	if(mp[cur] == 0)
	{
		return;
	}
	temp.pb(cur);
	mp[cur]--;
	count++;
	dfs(mp, ans, temp, n, count, cur*2);
	mp[cur]++;
	temp.pop_back();
	count--;
	if((cur%3) == 0)
	{
		temp.pb(cur);
		mp[cur]--;
		count++;
		dfs(mp, ans, temp, n, count, cur/3);
		mp[cur]++;
		temp.pop_back();
		count--;
	}
}

int main()
{
	ll n;
	cin >> n;
	vector<ll> bruh(n);
	std::map<ll, ll> mp;
	for(int i = 0; i < n; i++)
	{
		cin >> bruh[i];
		mp[bruh[i]]++;
	}
	vector<ll> ans;
	vector<ll> temp;
	ll count = 0;
	for(int i = 0; i < n; i++)
	{
		dfs(mp, ans, temp, n, count, bruh[i]);
		if(count == n)
		{
			break;
		}
	}	
	for(auto i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
