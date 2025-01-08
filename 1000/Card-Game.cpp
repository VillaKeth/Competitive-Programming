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

// card game
int main()
{
	ll t, a1, a2, b1, b2;
	cin >> t;
	while(t-- > 0)
	{
		cin >> a1 >> a2 >> b1 >> b2;
		ll total = 0;
		for(int i = 0; i < 4; i++)
		{
			ll suneet = 0;
			ll slavic = 0;
			if(i == 0)
			{
				if(a1 > b1)
				{
					suneet++;
				}
				else if(a1 == b1)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(a2 > b2)
				{
					suneet++;
				}
				else if(a2 == b2)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(suneet > slavic)
				{
					total++;
				}
			}
			else if(i == 1)
			{
				if(a1 > b2)
				{
					suneet++;
				}
				else if(a1 == b2)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(a2 > b1)
				{
					suneet++;
				}
				else if(a2 == b1)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(suneet > slavic)
				{
					total++;
				}
			}
			else if(i == 2)
			{
				if(a2 > b1)
				{
					suneet++;
				}
				else if(a2 == b1)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(a1 > b2)
				{
					suneet++;
				}
				else if(a1 == b2)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(suneet > slavic)
				{
					total++;
				}
			}
			else
			{
				if(a2 > b2)
				{
					suneet++;
				}
				else if(a2 == b2)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(a1 > b1)
				{
					suneet++;
				}
				else if(a1 == b1)
				{
					suneet++;
					slavic++;
				}
				else
				{
					slavic++;
				}
				if(suneet > slavic)
				{
					total++;
				}
			}
		}
		cout << total << endl;
	}
	return 0;
}
