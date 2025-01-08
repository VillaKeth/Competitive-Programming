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

// absolute zero
int main()
{
	ll t, n, temp;
	cin >> t;
	while(t--)
	{
		cin >> n;
		std::set<ll> sp; 
		vector<ll> bruh;
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			sp.insert(temp);
		}
		for(auto i : sp)
		{
			bruh.pb(i);
		}
		bool flag = true;
		ll k = 0;
		vector<ll> answer;
		int i = 0;
		while(i < bruh.size()-1)
		{
			if(bruh[i] == bruh[i+1])
			{
				i++;
				continue;
			}
			else
			{
				ll min = INT_MAX;
				ll minI = 0;
				ll max = INT_MIN;
				ll maxI = 0;
				for(int i = 0; i < bruh.size(); i++)
				{
					if(bruh[i] < min)
					{
						min = bruh[i];
						minI = i;
					}
					if(bruh[i] > max)
					{
						max = bruh[i];
						maxI = i;
					}
				}
				temp = bruh[minI]+bruh[maxI];
				if(temp&1 || k > 40)
				{
					flag = false;
					break;
				}
				temp /= 2;
				for(int j = 0; j < bruh.size(); j++)
				{
					bruh[j] = std::abs(bruh[j]-temp);
				}
				k++;
				answer.pb(temp);
				i = 0;
			}
		}
		if(bruh[0]) // edge case
		{
			k++;
			answer.pb(bruh[0]);
		}
		if(flag && k <= 40) 
		{
			cout << k << endl;
			for(auto i : answer)
			{
				cout << i << ' ';
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
