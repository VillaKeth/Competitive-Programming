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
#define cin std::cin
#define cout std::cout
#define endl std::endl
#define vector std::vector

// triple operations
int main()
{
	ll t, l, r;
	cin >> t;
	while(t-- > 0)
	{
		cin >> l >> r;
		ll templ = l;
		ll total = 0;
		ll special = 0;
		while(templ != 0)
		{
			special++;
			templ /= 3;
		}
		ll timey = pow(3, special-1);
		ll next = pow(3, special);
		ll county = special;
		while(timey <= r)
		{
			if(timey < l) // first iteration
			{
				total += county*std::min(next-l, r-l+1);
			}
			else if(next > r) // last iteration
			{
				total += county*(r-timey+1);
			}	
			else
			{
				total += county*(next-timey);
			}
			timey *= 3;
			next *= 3;
			county++;
		}
	
		cout << total+special << endl;
	}
	return 0;
}
