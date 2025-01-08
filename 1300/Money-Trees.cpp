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

// money trees 
int main()
{
    long long t, n, k;
    std::cin >> t;
    while(t-- > 0)
    {
        std::cin >> n >> k;
        std::vector<long long> fruits(n);
        std::vector<long long> heights(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> fruits[i];
        }    
        for(int i = 0; i < n; i++)
        {
            std::cin >> heights[i];
        }
        long long start = 0;
        long long mover = 0;
		long long prevTree = 0;
        long long curSum = 0;
        long long maxLength = 0;
        while(mover < n)
        {
            curSum += fruits[mover];
			if(start == mover)
			{
				prevTree = heights[mover];
			}
			else
			{
				if(prevTree % heights[mover] != 0)
				{
					while(start < mover)
					{
						curSum -= fruits[start];
						start++;
					}
				}
				prevTree = heights[mover];
			}
			while(curSum > k && start < n)
			{
				curSum -= fruits[start];
				start++;
			}
			maxLength = std::max(maxLength, mover-start+1);
			mover++;
        }
        std::cout << maxLength << std::endl;
    }
    return 0;
}
