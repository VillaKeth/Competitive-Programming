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

// klee's super duper large array
int main()
{
	ll t, n, k;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		ll min = k;
		ll max = (k+n)-1;
		ll start = k;
		ll end = (k+n)-1;
		ll mid = start + (end-start)/2;
		ll left = (mid*(mid+1))/2 - ((min-1)*min)/2;
		ll right = (max*(max+1))/2 - ((mid)*(mid+1))/2;
		ll ans = std::abs(left-right);
		while(start < end)
		{
			if(left > right)
			{
				end = mid;
			}
			else
			{
				start = mid+1;
			}
			mid = start + (end-start)/2;
			left = (mid*(mid+1))/2 - ((min-1)*min)/2;
			right = (max*(max+1))/2 - ((mid)*(mid+1))/2;
			ans = std::min(ans, std::abs(left-right));
		}
		cout << ans << endl;
	}
	return 0;
}
