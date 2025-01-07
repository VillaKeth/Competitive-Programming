#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#define ll long long

// odd sum
int main()
{
    ll n, temp;
    std::cin >> n;
    std::vector<ll> odds;
    std::vector<ll> evens;
    for(int i = 0; i < n; i++)
    {
        std::cin >> temp;
        if(temp&1)
        {
            odds.push_back(temp);
        }
        else
        {
            evens.push_back(temp);
        }
    }
    std::sort(odds.rbegin(), odds.rend());
    std::sort(evens.rbegin(), evens.rend());
    ll sum = odds[0]; // must exist according to problem
    for(int i = 2; i < odds.size(); i+=2)
    {
        if(odds[i]+odds[i-1] > 0)
        {
            sum += odds[i]+odds[i-1];
        }
    }
    for(int i = 0; i < evens.size(); i++)
    {
        if(evens[i] > 0)
        {
            sum += evens[i];
        }
        else
        {
            break;
        }
    }
    std::cout << sum;
    return 0;
}
