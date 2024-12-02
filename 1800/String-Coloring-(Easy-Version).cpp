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
#define pair std::pair
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1e9+7;
const ll MODDY2 = 998244353;
const ll MODDY3 = 1e8;

// string coloring (easy version) 
int main()
{
	long long n;
	std::string s;
	bool flag = true;
	cin >> n >> s;
	vector<std::tuple<int, char, bool>> bruh(n);
	for(int i = 0; i < n; i++)
	{
		bruh[i] = {i, s[i], false};
	}
	std::sort(s.begin(), s.end());
	for(int i = 0; i < n; i++)
	{
		if(std::get<1>(bruh[i]) != s[i])
		{
			int index = 0;
			for(int j = i; j < n; j++)
			{
				if(std::get<1>(bruh[j]) == s[i])
				{
					index = j;
					break;
				}
			}
			for(int j = index; j > i; j--)
			{
				if(std::get<2>(bruh[j]) && std::get<2>(bruh[j-1]))
				{
					flag = false;
					i = n;
					break;
				}
				std::get<2>(bruh[j-1]) = 1; 
				std::swap(bruh[j], bruh[j-1]); 
			}
		}
	}
	std::sort(bruh.begin(), bruh.end());
	if(flag)
	{
		cout << "YES" << endl;
		for(auto i : bruh)
		{
			cout << std::get<2>(i);
		}
	}
	else
	{
		cout << "NO";
	}
	return 0;
}
