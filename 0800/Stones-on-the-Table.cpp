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

// stones on the table
int main()
{
	ll n;
	std::string s;
	cin >> n >> s;
	ll count = 0;
	for(int i = 0; i < n-1; i++)
	{
		if(s[i] == s[i+1])
		{
			count++;
		}
	}
	cout << count;
	return 0;
}
