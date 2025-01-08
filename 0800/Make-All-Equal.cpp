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

// make all equal
int main()
{
	ll t, n, temp;
	cin >> t;
	while(t--)
	{
		cin >> n;
		std::map<ll, ll> mp;
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			mp[temp]++;
		}
		ll max = INT_MIN;
		ll maxSec = INT_MIN;
		for(auto i : mp)
		{
			if(i.second > maxSec)
			{
				maxSec = i.second;
				max = i.first;
			}
		}
		cout << n-maxSec << endl;
	}
	return 0;
}
