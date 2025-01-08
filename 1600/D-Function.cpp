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

// d-function
const unsigned long long MODDY = 1000000007;
ll powy(ll nummy, ll n)
{
	if(n == 0)
	{
		return 1;
	}
	else if(n == 1)
	{
		return nummy;
	}
	else
	{
		ll temp = powy(nummy, n/2);
		temp = (temp*temp)%MODDY;
		if(n&1)
		{
			temp = (temp*nummy)%MODDY;
		}
		return temp;
	}
}

int main()
{
	ll t, l, r, k;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> l >> r >> k;
		if(k > 9)
		{
			std::cout << 0 << std::endl;
		}
		else
		{
			ll nummy = std::ceil((10.0/k));
			ll bruh = (powy(nummy, r-l)-1)%MODDY;
			bruh = ((bruh%MODDY)*(powy(nummy, l)%MODDY))%MODDY;
			std::cout << bruh << std::endl;
		}
	}
	return 0;
}
