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

// primes on interval
int main()
{
    int a, b, k;
    std::cin >> a >> b >> k;
    std::vector<int> sieve(b+1, 0);
    sieve[1] = 1; // can't be zero, thogg don't care
    for(int i = 2; i <= b; i++)
    {
        if(sieve[i])
        {
            continue;
        }
        for(int j = 2*i; j <= b; j+=i)
        {
            sieve[j] = i;
        }
    }
    int max = -1; // if there are not enough primes in the range to even satisfy a single k, then we return max which is already -1
    int mover = a;
    int start = a;
    int curPrimes = 0;
    while(mover <= b)
    {
		if(!sieve[mover])
		{
			curPrimes++;
			while(curPrimes > k)
			{
				if(!sieve[start])
				{
					curPrimes--;
				}
				start++;
			}
			if(curPrimes == k)
			{
				max = std::max(max, mover-start+1);
				while(sieve[start])
				{
					start++;
				}
			}	
		}
		if(curPrimes == k) 
		{
			max = std::max(max, mover-start+1);
		}
		
		mover++;
    }
    std::cout << max << std::endl;
    return 0;
}
