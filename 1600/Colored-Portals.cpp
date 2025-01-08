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

// colored portals
// either not connected, directly connected, or one away
int main()
{
	ll t, n, q, x, y;
	cin >> t;
	while(t--)
	{
		cin >> n >> q;
		vector<std::string> bruh(n);
		std::map<std::string, vector<ll>> colors;
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
			colors[bruh[i]].pb(i); // must be sorted
		}
		for(int i = 0; i < q; i++)
		{
			cin >> x >> y;
			x--;
			y--;
			if(x > y)
			{
				std::swap(x, y);
			}
			if(bruh[x][0] == bruh[y][0] || bruh[x][0] == bruh[y][1] || bruh[x][1] == bruh[y][0] || bruh[x][1] == bruh[y][1]) // directly connected
			{
				cout << y-x << endl; // never a better way to reach city
			}
			else
			{
				ll min = INT_MAX;
				for(int i = 0; i < 2; i++)
				{
					for(int j = 0; j < 2; j++)
					{
						std::string temp;
						temp.pb(bruh[x][i]);
						temp.pb(bruh[y][j]);
						std::sort(temp.begin(), temp.end());
						if(!colors[temp].empty())
						{
							auto iter = std::lower_bound(colors[temp].begin(), colors[temp].end(), x);
							if(iter != colors[temp].end()) // everything is smaller than x
							{
								ll xVal = colors[temp][iter-colors[temp].begin()];
								min = std::min(min, std::abs(y-xVal)+std::abs(x-xVal));
							}
							if(iter != colors[temp].begin()) // there exists an element greater than x
							{
								ll xVal = colors[temp][iter-colors[temp].begin()-1];
								min = std::min(min, std::abs(xVal-y)+std::abs(xVal-x));
							}
						}
					}
				}
				if(min == INT_MAX)
				{
					cout << -1 << endl;
				}
				else
				{
					cout << min << endl;
				}
			}
		}
	}
	return 0;
}
