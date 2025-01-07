#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <string>
#define ll long long

// reverse binary strings
int main()
{
	ll t, n;
	std::string s;
	std::cin >> t;
	while(t--)
	{
		std::cin >> n >> s;
		ll count01 = 0;
		ll count10 = 0;
		for(int i = 0; i < n-1; i++)
		{
		    if(s[i] == '0' && s[i+1] == '1')
		    {
		        count01++;
		    }
		    else if(s[i] == '1' && s[i+1] == '0')
		    {
		        count10++;
		    }
		}
		std::cout << (n/2)-std::max(count01, count10) << std::endl;
	}
	return 0;
}
