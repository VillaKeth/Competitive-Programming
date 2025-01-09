#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_set>
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
 
// stone age problem
int main()
{
	long long n, q, temp1, temp2, temp3;
	std::cin >> n >> q;
	std::vector<long long> bruh(n);
	long long curSum = 0;
	for(int i = 0; i < n; i++)
	{
	    std::cin >> bruh[i];
	    curSum += bruh[i];
	}
	bool twoFlag = false;
	long long twoVal = 0;
	std::unordered_set<long long> sp;
	while(q-- > 0)
	{
	    std::cin >> temp1;
	    if(temp1 == 1)
	    {
	        std::cin >> temp2 >> temp3;
	        temp2--;
	        if(!twoFlag)
	        {
	            curSum -= bruh[temp2];
	            bruh[temp2] = temp3;
	            curSum += temp3;
	            std::cout << curSum << std::endl;
	        }
	        else
	        {
	            if(sp.find(temp2) == sp.end())
	            {
	               curSum -= twoVal; 
	            }
	            else
	            {
	                curSum -= bruh[temp2];
	            }
	            sp.insert(temp2);
	            bruh[temp2] = temp3;
	            curSum += temp3;
	            std::cout << curSum << std::endl;
	        }
	    }
	    else
	    {
	        twoFlag = true;
	        std::cin >> twoVal;
	        curSum = twoVal*n;
	        std::cout << curSum << std::endl;
	        sp.clear();
	    }
	}
	return 0;
}
