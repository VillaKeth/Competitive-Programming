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
#define hewwo std::cout << "hewwo" << std::endl;
#define cin std::cin
#define cout std::cout
#define endl std::endl
#define vector std::vector

// showering
int main()
{
	ll t, n, s, m, l, r;
	cin >> t;
	while(t-- > 0)
	{
		cin >> n >> s >> m;
		vector<std::pair<ll, ll>> bruh(n);
		for(int i = 0; i < n; i++)
		{
			cin >> l >> r;
			bruh[i] = {l, r};
		}
		bool flag = false;
		for(int i = 0; i < n; i++)
		{
			if(i == 0)
			{
				if(n == 1)
				{
					if(bruh[i].first >= s || m-bruh[i].second >= s)
					{
						flag = true;
						break;
					}
				}
				else
				{
					if(bruh[i].first >= s)
					{
						flag = true;
						break;
					}
				}
			}
			else if(i == n-1)
			{
				if(bruh[i].first-bruh[i-1].second >= s || m-bruh[i].second >= s)
				{
					flag = true;
					break;
				}
			}
			else
			{
				if(bruh[i].first-bruh[i-1].second >= s)
				{
					flag = true;
					break;
				}
			}
		}
		if(flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
