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

// minimum array
int main()
{
	ll n, temp;
	cin >> n;
	vector<ll> a(n);
	std::map<ll, ll> mp;
	vector<ll> ans(n);
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> temp;
		mp[temp]++;
	}
	for(int i = 0; i < n; i++)
	{
		ll findy = n-a[i];
		auto iter = mp.lower_bound(findy);
		if(iter == mp.end())
		{
			iter--;
		}
		auto chosen = mp.begin();
		if((a[i]+iter->first)%n <= (a[i]+chosen->first)%n)
		{
			chosen = iter;
		}
		ans[i] = (a[i]+chosen->first)%n;
		chosen->second--;
		if(!chosen->second)
		{
			mp.erase(chosen->first);
		}
	}
	for(auto i : ans)
	{
		cout << i << ' ';
	}
	return 0;
}
