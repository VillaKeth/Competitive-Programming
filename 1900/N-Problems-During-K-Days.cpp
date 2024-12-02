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

// n problems during k days 
int main()
{
	ll n, k;
	cin >> n >> k;
	vector<ll> ans(k);
	if((k*(k+1))/2 > n) // smallest case is already impossible
	{
		cout << "NO";
	}
	else
	{
		ll remainder = (n-((k*(k+1))/2))/k;
		for(int i = 0; i < k; i++)
		{
			ans[i] = (i+1)+remainder;
		}
		ll remainder2 = (n-(k*(k+1))/2)%k;
		if(remainder2 && k != 1)
		{
			if(remainder2 == 1)
			{
				ans[k-1]++;
			}
			else
			{
				ans[k-1] += remainder2-1;
				ans[k-2] += std::min(1LL, remainder2-1);
			}
		}
		ll sum = 0;
		bool flag = true;
		for(int i = 0; i < k; i++) // check answer
		{
			if(i)
			{
				if(ans[i] <= ans[i-1] || 2*ans[i-1] < ans[i])
				{
					flag = false;
					break;
				}
			}
			sum += ans[i];
		}
		if(sum == n && flag)
		{
			cout << "YES" << endl;
			for(auto i : ans)
			{
				cout << i << ' ';
			}
		}
		else
		{
			cout << "NO";
		}
	}
	return 0;
}
