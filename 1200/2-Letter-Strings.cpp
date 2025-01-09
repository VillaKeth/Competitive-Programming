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

// 2-letter strings
int main()
{
	long long t, n;
	std::string s;
	std::cin >> t;
	while(t-- > 0)
	{
		std::cin >> n;
		std::map<char, long long> first;
		std::map<char, long long> second;
		std::map<std::string, long long> bofa;
		long long count = 0;
		for(int i = 0; i < n; i++)
		{
			std::cin >> s;
			first[s[0]]++;
			second[s[1]]++;
			bofa[s]++;
		}
		for(auto i : bofa)
		{
			count += (first[i.first[0]]-i.second)*i.second;
			count += (second[i.first[1]]-i.second)*i.second;
		}
		std::cout << count/2 << std::endl;
	}
	return 0;
}
