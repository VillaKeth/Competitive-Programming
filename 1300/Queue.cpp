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

// queue 
int main()
{
	ll n;
	cin >> n;
	vector<ll> bruh(n);
	for(int i = 0; i < n; i++)
	{
		cin >> bruh[i];
	}
	std::sort(bruh.begin(), bruh.end());
	ll time = 0;
	ll count = 0;
	for(auto i : bruh)
	{
		if(time <= i)
		{	
			time += i;
			count++;
		}
	}
	cout << count;
	return 0;
}
