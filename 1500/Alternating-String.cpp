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

// alternating string 
int main()
{
	ll t,n;
	std::string s;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		if(n&1) // must delete
		{
			vector<ll> even(26, 0);
			vector<ll> odd(26, 0);
			for(int i = 1; i < n; i++)
			{
				if(i&1) // odd index
				{
					odd[s[i]-'a']++;
				}
				else // even index
				{
					even[s[i]-'a']++;
				}
			}
			ll evenMax = 0;
			ll oddMax = 0;
			for(int i = 0; i < 26; i++)
			{
				evenMax = std::max(evenMax, even[i]);
				oddMax = std::max(oddMax, odd[i]);
			}
			std::pair<ll, ll> ans = {evenMax, oddMax};
			for(int i = 1; i < n; i++)
			{
				if(i&1)
				{
					odd[s[i]-'a']--;
					odd[s[i-1]-'a']++;
				}
				else
				{
					even[s[i]-'a']--;
					even[s[i-1]-'a']++;
				}
				evenMax = 0;
				oddMax = 0;
				for(int j = 0; j < 26; j++)
				{
					evenMax = std::max(evenMax, even[j]);
					oddMax = std::max(oddMax, odd[j]);
				}
				if((evenMax+oddMax) > (ans.first+ans.second))
				{
					ans = {evenMax, oddMax};
				}
			}
			cout << (((n/2)-ans.first)+((n/2)-ans.second))+1 << endl;
		}
		else // cannot delete
		{
			vector<ll> even(26, 0);
			vector<ll> odd(26, 0);
			for(int i = 0; i < n; i++)
			{
				if(i&1) // even index
				{
					even[s[i]-'a']++;
				}
				else // odd index
				{
					odd[s[i]-'a']++;
				}
			}
			ll evenMax = 0;
			ll oddMax = 0;
			for(int i = 0; i < 26; i++)
			{
				evenMax = std::max(evenMax, even[i]);
				oddMax = std::max(oddMax, odd[i]);
			}
			cout << ((n/2)-evenMax)+((n/2)-oddMax) << endl;
		}
	}
	return 0;
}
