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

// longest good array
int main()
{
	ll t, l, r;
	cin >> t;
	while(t--)
	{
		cin >> l >> r;
		ll ans = 0;
		ll start = 1;
		ll end = 1000000001;
		ll mid = start + (end-start)/2;
		while(start < end)
		{
			if((mid*(mid+1))/2  == (r-l+1))
			{
				break;
			}
			else if((mid*(mid+1))/2 > (r-l+1))
			{
				end = mid;
			}
			else
			{
				start = mid+1;
			}
			mid = start + (end-start)/2;
		}
		cout << mid << endl;
	}
	return 0;
}
