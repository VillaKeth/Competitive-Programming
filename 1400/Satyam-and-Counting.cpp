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
 
// satyam and counting
int main()
{
	ll t, n, x, y;
	cin >> t;
	while(t--)
	{
		cin >> n;
		std::map<std::pair<ll, ll>, ll> mp;
		vector<std::pair<ll, ll>> bruh(n);
		vector<ll>xCount(2, 0);		
		for(int i = 0; i < n; i++)
		{
			cin >> x >> y;
			bruh[i] = {x, y};
			mp[bruh[i]]++;
			xCount[y]++;
		}
		ll ans = 0;
		for(int i = 0; i < n; i++)
		{
			ll tempx = bruh[i].first;
			ll tempy = bruh[i].second;
			if(tempy == 0) // check horizontal and vertical
			{
				if(mp[{tempx, 1}])
				{
					ans += xCount[0]-1;
					ans += xCount[1]-1;
				}
				ans += mp[{tempx+1, 1}]*mp[{tempx+2, tempy}]; // check diagonal
			}
			else
			{
				ans += mp[{tempx+1, 0}]*mp[{tempx+2, tempy}]; // check diagonal
			}

		}
		cout << ans << endl;
	}
	return 0;
}
