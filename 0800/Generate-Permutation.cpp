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

// generate permutation
int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n&1)
		{
			std::deque<ll> dq;
			dq.push_front(1);
			for(ll i = 2; i <= n; i++)
			{
				if(i&1)
				{
					dq.push_back(i);
				}
				else
				{
					dq.push_front(i);
				}
			}
			for(int i = 0; i < dq.size(); i++)
			{
				cout << dq[i] << ' ';
			}
			cout << endl;
		}
		else
		{
			cout << -1 << endl;
		}
	}
	return 0;
}
