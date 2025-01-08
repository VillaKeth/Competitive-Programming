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

// ruler (hard version)
int main()
{
	ll t;
	cin >> t;
	while(t-- > 0)
	{
		ll start = 1;
		ll end = 1000;
		ll fThird = start + (end-start)/3;
		ll sThird = end - (end-start)/3;
		ll response = 0;
		while(start < end)
		{
			cout << "? " << fThird << ' ' << sThird << endl;
			cout.flush();
			cin >> response;
			ll area1 = fThird*sThird;
			ll area2 = fThird*(sThird+1);
			if(response == area1)
			{
				start = sThird+1;
			}
			else if(response == area2)
			{
				start = fThird+1;
				end = sThird;
			}
			else
			{
				end = fThird;
			}
			fThird = start + (end-start)/3;
			sThird = end - (end-start)/3;
		}
		cout << "! " << start << endl;
		cout.flush();
	}
	return 0;
}
