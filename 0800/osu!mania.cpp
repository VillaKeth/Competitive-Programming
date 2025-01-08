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
 
// osu!mania
int main()
{
	ll t, n;
	std::string s;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> ans;
		for(int i = 0; i < n; i++)
		{
			cin >> s;
			for(int j = 0; j < 4; j++)
			{
				if(s[j] == '#')
				{
					ans.pb(j+1);
				}
			}
		}
		ll size = ans.size()-1;
		for(int i = size; i >= 0; i--)
		{
			cout << ans[i] << ' ';
		}
		cout << endl;
	}
	return 0;
}
