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
 
// minimize!
int main()
{
	ll t, a, b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		ll c = b-a;
		cout << (c-a)+(b-c) << endl;
	}
	return 0;
}
