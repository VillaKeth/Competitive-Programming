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
const ll MODDY = 1000000007;

// interview 
int main()
{
	ll t, n, temp;
	cin >> t;
	while(t-- > 0)
	{
		cin >> n;
		ll curSum = 0;
		vector<ll> bruh(n+1);
		bruh[0] = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> temp;
			curSum += temp;
			bruh[i] = curSum;
		}
		ll start = 1;
		ll end = n;
		ll mid = start + (end-start)/2;
		while(start < end)
		{
			cout << "? " << mid-start+1 << ' ';
			for(int i = start; i <= mid; i++)
			{
				cout << i << ' ';
			}
			cout << endl;
			cout.flush();
			curSum = bruh[mid]-bruh[start-1];
			ll response = 0;
			cin >> response;
			if(response == curSum)
			{
				start = mid+1;
			}
			else
			{
				end = mid;
			}
			mid = start + (end-start)/2;
		}
		cout << "! " << mid << endl;
		cout.flush(); 
	}
	return 0;
}
