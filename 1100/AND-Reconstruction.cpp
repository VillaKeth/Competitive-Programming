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

// and reconstruction
int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> bruh(n-1);
		vector<ll> ans(n);
		for(int i = 0; i < n-1; i++)
		{
			cin >> bruh[i];
		}
		ans[0] = bruh[0];
		ans[n-1] = bruh[n-2];
		for(int i = 0; i < n-2; i++)
		{
			ans[i+1] = bruh[i] | bruh[i+1];
		}
		bool flag = true;
		for(int i = 0; i < n-1; i++)
		{
			if((ans[i] & ans[i+1]) != bruh[i])
			{
				flag = false;
				break;
			}
		}
		if(flag)
		{
			for(auto i : ans)
			{
				cout << i << ' ';
			}
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
