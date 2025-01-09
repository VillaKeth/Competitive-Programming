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

// potions easy and hard version 
int main()
{
    long long n, temp, health(0), count(0), max(0);
    std::cin >> n;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> pq; // should be max heap
    for(int i = 0; i < n; i++)
    {
        std::cin >> temp;
		health += temp;
		pq.push(temp);
		while(health < 0)
		{
			health -= pq.top();
			pq.pop();
		}
    }
    std::cout << pq.size();
    return 0;
}
