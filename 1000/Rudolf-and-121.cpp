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

// rudolf and 121
int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> bruh(n);
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
		}
		for(int i = 1; i < n-1; i++)
		{
			ll min = std::min({bruh[i-1], bruh[i]/2, bruh[i+1]});
			bruh[i-1] -= min;
			bruh[i] -= 2*min;
			bruh[i+1] -= min;
		}
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			if(bruh[i])
			{
				flag = false;
			}
		}
		flag ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}
