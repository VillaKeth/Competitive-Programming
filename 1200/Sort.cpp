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

// sort
int main()
{
	ll t, n, q, l, r;
	std::string a, b;
	cin >> t;
	while(t--)
	{
		cin >> n >> q >> a >> b;
		vector<ll> lettersA(26, 0);
		vector<ll> lettersB(26, 0);
		vector<vector<ll>> prefix1(n+1, vector<ll> (26, 0));
		vector<vector<ll>> prefix2(n+1, vector<ll> (26, 0));
		for(int i = 1; i <= n; i++)
		{
			prefix1[i][a[i-1]-'a']++;
			prefix2[i][b[i-1]-'a']++;
			for(int j = 0; j < 26; j++)
			{
				prefix1[i][j] += prefix1[i-1][j];
				prefix2[i][j] += prefix2[i-1][j];
			}
		}
		for(int i = 0; i < q; i++)
		{
			cin >> l >> r;
			ll sum = 0;
			for(int i = 0; i < 26; i++)
			{
				sum += std::abs((prefix1[r][i]-prefix1[l-1][i])-(prefix2[r][i]-prefix2[l-1][i]));
			}
			cout << sum/2 << endl;
		}
	}
	return 0;
}
