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

// square or not
int main()
{
	ll t, n;
	std::string s;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		bool isSquare = false;
		ll square = 0;
		for(int i = 2; i*i <= n; i++)
		{
			if((n%i) == 0 && n/i == i)
			{
				isSquare = true;
				square = i;
				break;
			}
		}
		if(isSquare)
		{
			ll start = 0;
			ll end = n-1;
			ll zeroCount = 0;	
			bool flag = true;
			while(start <= end)
			{
				if(s[start] != s[end])
				{	
					flag = false;
					break;
				}
				if(start == end && s[start] == '0')
				{
					zeroCount++;
				}
				if(start != end)
				{
					if(s[end] == '0')
					{
						zeroCount++;
					}
					if(s[start] == '0')
					{
						zeroCount++;
					}
				}
				start++;
				end--;
			}
			if(flag && zeroCount == (square-2)*(square-2))
			{
				cout << "YES" << endl;
			}
			else
			{
				cout << "NO" << endl;
			}
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
