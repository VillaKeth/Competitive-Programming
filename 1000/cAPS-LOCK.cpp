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

// cAPS LOCK 
int main()
{
    std::string bruh;
    cin >> bruh;
	bool allCaps = true;
	bool firstLower = true;
    for(int i = 0; i < bruh.length(); i++)
	{
		if(islower(bruh[i]))
		{
			if(i)
			{
				firstLower = false;
			}
			allCaps = false;
		}
	}
	if(firstLower)
	{
		for(int i = 0; i < bruh.length(); i++)
		{
			if(!i)
			{
				bruh[i] = toupper(bruh[i]);
			}
			else
			{
				bruh[i] = tolower(bruh[i]);
			}
		}
	}
	if(allCaps)
	{
		for(int i = 0; i < bruh.length(); i++)
		{
			bruh[i] = tolower(bruh[i]);
		}
	}
	cout << bruh;
    return 0;
}
