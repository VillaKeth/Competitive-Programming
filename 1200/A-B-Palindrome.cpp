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
 
// a-b palindrome
int main()
{
	ll t, a, b;
	std::string s;
	cin >> t;
	while(t--)
	{
		cin >> a >> b >> s;
		ll aCount = 0;
		ll bCount = 0;
		for(int i = 0; i < s.length(); i++)
		{
			if(s[i] == '0')
			{
				aCount++;
			}
			else if(s[i] == '1')
			{
				bCount++;
			}
		}
		ll start = 0;
		ll end = s.length()-1;
		while(start <= end)
		{
			if(s[start] == '?' || s[end] == '?')
			{
				if(s[start] == '1')
				{
					bCount++;
					s[end] = '1';
				}
				else if(s[end] == '1')
				{
					bCount++;
					s[start] = '1';
				}
				else if(s[start] == '0')
				{
					aCount++;
					s[end] = '0';
				}
				else if(s[end] == '0')
				{
					aCount++;
					s[start] = '0';
				}
			}
			start++;
			end--;
		}
		start = 0;
		end = s.length()-1;
		while(start <= end)
		{
			if(start == end && s[start] == '?')
			{
				if((a-aCount) == 1)
				{
					s[start] = '0';
					aCount++;
				}
				else
				{
					s[end] = '1';
					bCount++;
				}
			}
			else
			{	
				if(s[start] == '?')
				{
					if((a-aCount) >= 2)
					{
						s[start] = '0';
						s[end] = '0';
						aCount += 2;
					}
					else
					{
						s[start] = '1';
						s[end] = '1';
						bCount += 2;
					}
				}
			}
			start++;
			end--;
		}
		bool isPalin = true;
		start = 0;
		end = s.length()-1;
		while(start <= end)
		{
			if(s[start] != s[end])
			{
				isPalin = false;
				break;
			}
			start++;
			end--;
		}
		
		if(!(a-aCount) && !(b-bCount) && isPalin)
		{
			cout << s << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
