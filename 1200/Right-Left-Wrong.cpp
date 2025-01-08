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

// right left wrong
int main()
{
	ll t, n;
	std::string s;
	cin >> t;
	while(t--)
	{
		cin >> n;
		vector<ll> score(n+1);
		vector<ll> prefix(n+1);
		prefix[0] = 0;
		ll curSum = 0;
		for(int i = 1; i <= n; i++)
		{
			cin >> score[i];
			curSum += score[i];
			prefix[i] = curSum;
		}	
		cin >> s;
		s = 'a' + s;
		ll left = 1;
		ll right = n;
		ll maxScore = 0;
		while(left < right)
		{
			if(s[left] == 'L' && s[right] == 'R')
			{
				maxScore += prefix[right]-prefix[left-1];
				left++;
				right--;
			}
			if(s[left] != 'L')
			{
				left++;
			}
			if(s[right] != 'R')
			{
				right--;
			}
		}
		cout << maxScore << endl;
	}
	return 0;
}
