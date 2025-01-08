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

// turtle and piggy are playing a game 2
int main()
{
	ll t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> bruh(n);
		for(int i = 0; i < n; i++)
		{
			cin >> bruh[i];
		}
		std::sort(bruh.begin(), bruh.end());
		cout << bruh[n/2] << endl;
	}
	return 0;
}
