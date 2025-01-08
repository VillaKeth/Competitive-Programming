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

// primary task
int main()
{
	ll t;
	std::string s;
	cin >> t;
	while(t--)
	{
		cin >> s;
		ll rest = 0;
		bool firstTrue = true;
		bool hasLeadZero = true;
		if(s.length() < 3)
		{
			firstTrue = false;
		}
		for(int i = 0; i < s.length(); i++)
		{
			if(i < 2)
			{
				if(i == 0)
				{
					if(s[i] != '1')
					{
						firstTrue = false;
					}
				}
				else
				{
					if(s[i] != '0')
					{
						firstTrue = false;
					}
				}
			}
		}
		ll count = 0;
		for(int i = s.length()-1; i >= 2; i--)
		{
			if(i == 2)
			{
				if(s[i] == '0')
				{
					hasLeadZero = false;
				}
			}
			rest += pow(10, count)*(s[i]-'0');
			count++;
		}
		if(firstTrue && hasLeadZero && rest >= 2)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}	
	return 0;
}
