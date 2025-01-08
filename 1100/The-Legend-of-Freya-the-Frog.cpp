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
 
// the legend of freya the frog
int main()
{
	ll t, x, y, k;
	cin >> t;
	while(t--)
	{
		cin >> x >> y >> k;
		ll ans = 0;
		if(y >= x)
		{
			ans = (std::ceil((double)y/k))*2;
		}
		else
		{
			ans = std::ceil((double)x/k)*2;
			ll tempx = std::ceil((double)x/k);
			ll tempy = (std::ceil((double)y/k));
			if(tempx > tempy)
			{
				ans--;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
