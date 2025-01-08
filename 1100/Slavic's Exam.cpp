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

// slavic's exam
int main()
{
	ll test;
	std::string s, t;
	cin >> test;
	while(test-- > 0)
	{
		cin >> s >> t;
		ll tpoint = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == t[tpoint])
			{
				if(tpoint < t.length())
				{
					tpoint++;
				}
				continue;
			}
			if(s[i] == '?')
			{
				if(tpoint < t.length())
				{
					s[i] = t[tpoint];
					tpoint++;
				}
				else
				{
					s[i] = 'a';
				}
			}
		}
		if(tpoint >= t.length())
		{
			cout << "YES" << endl;
			cout << s << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
