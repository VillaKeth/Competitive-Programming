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
#define pb push_back
#define hewwo std::cout << "hewwo" << std::endl;

// vitaliy and pie
int main()
{
	ll n, count(0);
	std::string s;
	std::cin >> n >> s;
	std::map<char, ll> mp;
	for(int i = 0; i < (2*n)-2; i+=2)
	{
		mp[s[i]]++;
		if(mp[tolower(s[i+1])])
		{
			mp[tolower(s[i+1])]--;
		}
		else
		{
			count++;
		}
	}
	std::cout << count;
	return 0;
}
