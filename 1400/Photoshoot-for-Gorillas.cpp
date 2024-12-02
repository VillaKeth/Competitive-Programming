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
#define pair std::pair
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1e9+7;
const ll MODDY2 = 998244353;
const ll MODDY3 = 1e8;

// photoshoot for gorillas
int main()
{
	ll t, n, m, k, w;
	cin >> t;
	while(t--)
	{
		cin >> n >> m >> k >> w;
		vector<ll> gorillas(w);
		std::priority_queue<ll> pqG;
		for(int i = 0; i < w; i++)
		{
			cin >> gorillas[i];
			pqG.push(gorillas[i]);
		}
		vector<ll> nSize(n);
		vector<ll> mSize(m);
		for(ll i = 1; i <= n; i++)
		{
			nSize[i-1] = std::min({i, (n-k)+1, k, (n+1)-i});
		}
		for(ll i = 1; i <= m; i++)
		{
			mSize[i-1] = std::min({i, (m-k)+1, k, (m+1)-i});
		}
		std::priority_queue<ll> pqS;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				pqS.push(nSize[i]*mSize[j]);
			}
		}
		ll sum = 0;
		while(!pqG.empty())
		{
			sum += pqG.top()*pqS.top();
			pqG.pop();
			pqS.pop();
		}
		cout << sum << endl;
	}
	return 0;
}
