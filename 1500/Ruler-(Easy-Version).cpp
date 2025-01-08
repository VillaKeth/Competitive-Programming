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

// ruler (easy version)
int main()
{
	ll t;
	cin >> t;
	while(t-- > 0)
	{
		ll start = 1;
		ll end = 1000;
		ll mid = start + (end-start)/2;
		ll response = 0;
		while(start < end)
		{
			cout << "? " << start << ' ' << mid << endl;
			cout.flush();
			cin >> response;
			ll area = start*mid;
			if(response == area)
			{
				start = mid+1;
			}
			else
			{
				end = mid;
			}
			mid = start + (end-start)/2;
		}
		cout << "! " << mid << endl;
		cout.flush();
	}
	return 0;
}
