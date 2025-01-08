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
#define hewwo std::cout << "hewwo" << std::endl;
#define cin std::cin
#define cout std::cout
#define endl std::endl
#define vector std::vector

// a+b again?
int main()
{
	ll t, n;
	cin >> t;
	while(t-- > 0)
	{
		cin >> n;
		ll sum = 0;
		while(n != 0)
		{
			sum += n%10;
			n /= 10;
		}	
		cout << sum << endl;
	}
	return 0;
}
