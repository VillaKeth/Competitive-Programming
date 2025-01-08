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

// phone desktop
int main()
{
	ll t, x, y;
	cin >> t;
	while(t--) 
	{
		cin >> x >> y;
		ll screens = 0;
		screens += (y+1)/2;
		ll remainingSpaces = (screens*15)-(4*y);
		if(x > remainingSpaces)
		{
			screens += std::ceil(((double)(x-remainingSpaces)/15));
		}
		cout << screens << endl;
	}
	return 0;
}
