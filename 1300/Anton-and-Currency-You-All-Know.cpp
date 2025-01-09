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

// anton and currency you all know
int main()
{
    std::string s;
    std::cin >> s;
    long long left = s[s.length()-1]-'0';
    long long evenIndex = -1;
    long long exploreIndex = INT_MAX;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if((s[i]-'0')%2 == 0 && evenIndex == -1)
        {
            evenIndex = i;
        }
        if((s[i]-'0')%2 == 0 && left > s[i]-'0')
        {
            exploreIndex = i;
        }
   }
    if(evenIndex == -1)
    {
        std::cout << -1;
    }
    else
    {
        std::swap(s[std::min(evenIndex, exploreIndex)], s[s.length()-1]);
        std::cout << s;
    }
    return 0;
}
