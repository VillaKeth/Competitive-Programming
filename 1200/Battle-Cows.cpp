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

// battle cows 
int main()
{
	ll t, n, k;
	cin >> t;
	while(t--)
	{
		cin >> n >> k;
		k--;
		vector<ll> bruh(n);
		ll max = 0;
		ll maxI = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
		}
		for(int i = 0; i < n; i++)
		{
			if(bruh[i] > bruh[k])
			{
				max = bruh[i];
				maxI = i;
				break;
			}
		}
		ll tempCount = 0;
		ll battles = 0;
		tempCount = 0;
		std::swap(bruh[0], bruh[k]);
		for(int i = 1; i < n; i++) // check swap with begin
		{
			if(bruh[0] > bruh[i])
			{
				tempCount++;
			}
			else
			{
				break;
			}
		}
		std::swap(bruh[0], bruh[k]);
		battles = tempCount;
		tempCount = 0;
		if(maxI != 0) // check with swap first greater than my cow
		{
			std::swap(bruh[k], bruh[maxI]);
			std::priority_queue<ll> pq;
			for(int i = 0; i < n; i++)
			{
				pq.push(bruh[i]);
				if(pq.top() == bruh[maxI])
				{
					tempCount++;
				}
			}
			battles = std::max(battles, tempCount);
		}
		cout << battles << endl;
	}
	return 0;
}
