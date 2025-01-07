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

// fun game
int main()
{
	ll test, n;
	std::string s, t;
	cin >> test;
	while(test--)
	{
		cin >> n >> s >> t;
		bool zeroOne = false;
		bool seenOne = false;
		bool flag = true;
		for(int i = 0; i < n; i++)
		{
			if(s[i] == '1')
			{
				seenOne = true;
			}
			else if(s[i] == '0' && t[i] == '1')
			{
				zeroOne = true;
			}
			if(zeroOne && !seenOne)
			{
				flag = false;
				break;
			}
		}
		flag ? cout << "YES" << endl : cout << "NO" << endl;
	}
	return 0;
}
