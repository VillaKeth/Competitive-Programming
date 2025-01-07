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

// reachable numbers
int main()
{
	ll n;
	cin >> n;
	ll count = 0;
	if(n >= 10)
	{
		count++;
	}
	n++;
	while(n >= 10)
	{
		ll temp = n%10;

		if(temp != 0)
		{
			count += 10-temp;
		}
		else
		{
			n /= 10;
			continue;
		}
		n += (10-temp);
		n /= 10;
	}
	count += 9;
	cout << count;
	return 0;
}
