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

// good string
int main()
{
	ll n, k(0); 
	std::string s, newS;
	cin >> n >> s;
	std::stack<ll> st;
	ll i = 0;
	while(i < n)
	{
		if(st.size() % 2 == 0)
		{
			st.push(s[i]);
		}
		else if(st.top() != s[i])
		{
			st.push(s[i]);
		}
		else
		{
			k++;
		}
		i++;
	}
	if(st.size()&1)
	{
		st.pop();
		k++;
	}
	while(!st.empty())
	{
		newS += st.top();
		st.pop();
	}
	std::reverse(newS.begin(), newS.end());
	cout << k << endl;
	cout << newS;
	return 0;
}
