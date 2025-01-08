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

// numeric string template
int main()
{
	ll t, n, m;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> bruh(n);
		std::map<ll, vector<ll>> mp;
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
			mp[bruh[i]].pb(i);
		}
		cin >> m;
		std::string temp;
		for(int i = 0; i < m; i++)
		{
			cin >> temp;
			if(temp.length() != n)
			{
				cout << "NO" << endl;
				continue;
			}
			else
			{
				bool flag1 = true;
				bool flag2 = true;
				for(auto p : mp)
				{
					char checker;
					for(int j = 0; j < p.second.size(); j++)
					{
						if(j == 0)
						{
							checker = temp[(p.second[j])];
						}
						else
						{
							if(temp[p.second[j]] != checker)
							{
								flag1 = false;
								break;
							}
						}
					}
				}
				std::map<char, vector<ll>> mps;
				for(int j = 0; j < temp.length(); j++)
				{
					mps[temp[j]].pb(j);
				}
				for(auto p : mps)
				{
					ll checker;
					for(int j = 0; j < p.second.size(); j++)
					{
						if(j == 0)
						{
							checker = bruh[p.second[j]];
						}
						else
						{
							if(bruh[p.second[j]] != checker)
							{
								flag2 = false;
								break;
							}
						}
					}
				}
				
				if(flag1 && flag2)
				{
					cout << "YES" << endl;
				}
				else
				{
					cout << "NO" << endl;
				}
			}
		}
	}
	return 0;
}
