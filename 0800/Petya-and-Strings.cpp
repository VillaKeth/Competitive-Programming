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

// petya and strings
int main()
{
	std::string s, t;
	cin >> s >> t;
	ll out = 0;
	for(int i = 0; i < s.length(); i++)
	{
		if(tolower(s[i]) < tolower(t[i]))
		{
			out = -1;
			break;
		}
		if(tolower(s[i]) > tolower(t[i]))
		{
			out = 1;
			break;
		} 
	}
	cout << out;
}
