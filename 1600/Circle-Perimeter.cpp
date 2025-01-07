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

// circle perimeter 
int main()
{
	ll t, r;
	cin >> t;
	while(t--)
	{
		cin >> r;
		ll limit = (r+1)*(r+1);
		ll ans = 0;
		for(ll i = r; i > 0; i--)
		{
			ll start = 0;
			ll end = r;
			ll mid = start + (end-start)/2;
			while(start < end) // find first number greater than or equal to r^2
			{
				if((i*i)+(mid*mid) >= (r*r))
				{
					end = mid;
				}
				else
				{
					start = mid+1;
				}
				mid = start + (end-start)/2;
			}
			ll squarey = ((r+1)*(r+1))-(i*i);
			start = 1;
			end = r+1;
			ll temp = start + (end-start)/2;
			while(start < end) // square root to find first number less than (r+1)^2
			{	
				if(temp*temp == squarey)
				{
					break;
				}
				else if(temp*temp > squarey)
				{
					end = temp;
				}
				else
				{
					start = temp+1;
				}
				temp = start + (end-start)/2;
			}
			// add the difference between the first number < (r+1)^2 and >= r^2
			ans += ((temp-1)-mid+1);
		}
		cout << ans*4 << endl;
	}
	return 0;
}
