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

// vlad and a sum of sum of digits
int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		ll sum = 0;
		ll county = 1;
		ll total = 0;
		ll prev = 0;
		while(n != 0)
		{
			ll temp = n%10;
			sum += temp+(total*temp)+((((temp-1)*temp)/2)*county);
			if(county > 1)
			{
				sum += temp*prev;
			}
			prev += temp*county;
			total = (total+(total+(9*county)))*5;
			county *= 10;
			n /= 10;
		}
		cout << sum << endl;
	}
	return 0;
}
