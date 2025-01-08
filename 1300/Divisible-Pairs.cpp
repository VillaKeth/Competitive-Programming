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

// divisible pairs 
int main()
{
	ll t, n, x, y, temp;
	cin >> t;
	while(t--)
	{
		cin >> n >> x >> y;
		std::map<std::pair<ll, ll>, ll> mp;
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			mp[{temp%x, temp%y}]++;
		}
		ll count = 0;
		for(auto i : mp) 
		{
			std::pair<ll, ll> temp = {(x-i.first.first)%x, i.first.second};
			if(i.first.first == temp.first)
			{
				count += (i.second*(i.second-1));
			}
			else
			{
				count += i.second*mp[temp];
			}
		}
		cout << (count/2) << endl;
	}
	return 0;
}
