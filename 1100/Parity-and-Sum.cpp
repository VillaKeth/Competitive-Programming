#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define ll long long

// parity and sum
int main()
{
	ll t, n, temp;
	std::cin >> t;
	while(t--)
	{
		std::cin >> n;
		std::vector<ll> evens;
		ll oddMax = -1;
		for(int i = 0; i < n; i++)
		{
			std::cin >> temp;
			if(temp&1)
			{
				oddMax = std::max(oddMax, temp);
			}
			else
			{
				evens.push_back(temp);
			}
		}
		std::sort(evens.begin(), evens.end());
		
		if(evens.size() != n)
		{
			bool flag = true;
			for(int i = 0; i < evens.size(); i++) // check if it's okay to do it consecutively
			{
				if(evens[i] < oddMax)
				{
					oddMax += evens[i];
				}
				else // just take from the back instead
				{
					flag = false;
					break;
				}
			}
			flag ? std::cout << evens.size() << std::endl : std::cout << evens.size()+1 << std::endl;
		}
		else
		{
		    std::cout << 0 << std::endl;
		}
		
	}
	return 0;
}
