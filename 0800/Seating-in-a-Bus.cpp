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

// seating in a bus
int main()
{
	ll t, n, temp;
	cin >> t;
	while(t--)
	{
		cin >> n;
		bool flag = true;
		vector<bool> visited(n, false);
		for(int i = 0; i < n; i++)
		{
			cin >> temp;
			temp--;
			if(i == 0)
			{
				visited[temp] = true;
			}
			else
			{
				visited[temp] = true;
				bool temp1 = false;
				bool temp2 = false;
				if(temp+1 < n && visited[temp+1])
				{	
					temp1 = true;
				}
				if(temp-1 >= 0 && visited[temp-1])
				{
					temp2 = true;
				}
				if(!temp1 && !temp2)
				{
					flag = false;
				}
			}
		}
		if(flag)
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}
	return 0;
}
