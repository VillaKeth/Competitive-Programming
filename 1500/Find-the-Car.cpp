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
// #define cin std::cin
// #define cout std::cout
// #define endl std::endl
// #define vector std::vector


// find the car dont use doubles unless you want to kill yourself
int main()
{
	ll t, n, k, q, searchy;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n >> k >> q;
		std::vector<ll> a(k+1); // distances
		std::vector<ll> b(k+1); // times
		a[0] = 0; 
		b[0] = 0;
		for(int i = 1; i <= k; i++)
		{
			std::cin >> a[i];
		}
		for(int i = 1; i <= k; i++)
		{
			std::cin >> b[i];
		}
		for(int i = 0; i < q; i++)
		{
			std::cin >> searchy;
			ll start = 0;
			ll end = k;
			ll mid = start + (end-start)/2;
			while(start < end)
			{
				if(searchy < a[mid]) 
				{
					end = mid;
				}
				else
				{
					start = mid+1;
				}
				mid = start + (end-start)/2;
			}
			mid--; // first element greater than searchy
			ll top = b[mid+1] - b[mid];
			ll bottom = a[mid+1] - a[mid];
			searchy -= a[mid];
			std::cout << b[mid]+((ll)((searchy*top)/bottom)) << ' ';
		}
		std::cout << std::endl;
	}
	return 0;
}
