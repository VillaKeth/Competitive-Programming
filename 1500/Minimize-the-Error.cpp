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

// minimize the error 
int main()
{
	int n, ka, kb, k;
	cin >> n >> ka >> kb;
	k = ka+kb;
	vector<long long> v1(n);
	vector<long long> v2(n);
	for(int i = 0; i < n; i++)
	{
		cin >> v1[i];
	}
	for(int i = 0; i < n; i++)
	{
		cin >> v2[i];
	}
	vector<long long> difference(n);
	for(int i = 0; i < n; i++)
	{
		difference[i] = std::abs(v1[i]-v2[i]);
	}
	std::sort(difference.rbegin(), difference.rend());
	std::priority_queue<long long> pq;
	for(int i = 0; i < n; i++)
	{
		pq.push(difference[i]);
	}
	while(k != 0)
	{
		long long temp = pq.top();
		pq.pop();
		if(temp == 0)
		{
			temp++;
		}
		else
		{
			temp--;
		}		
		pq.push(temp);	
		k--;
	}
	long long sum = 0;
	while(!pq.empty())
	{
		sum += pq.top()*pq.top();
		pq.pop();
	}
	cout << sum;
    return 0;
}
