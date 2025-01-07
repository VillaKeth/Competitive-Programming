#include <iostream>
#include <vector>
#include <set>
#define ll long long

// chamo and mocha's array
int main()
{
    ll t, n;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        std::vector<ll> bruh(n);
        for(int i = 0; i < n; i++)
        {
            std::cin >> bruh[i];
        }
        if(n == 2)
        {
            std::cout << std::min(bruh[0], bruh[1]) << std::endl;
        }
        else
        {
            ll max = -1;
            std::multiset<ll> ms;
            for(int i = 0; i < 3; i++)
            {
                ms.insert(bruh[i]);
            }
            auto iter = std::next(ms.begin(), ((ms.size()+1)/2)-1);
            max = std::max(max, *iter);
            for(int i = 3; i < n; i++)
            {
                ms.erase(ms.find(bruh[i-3])); 
                ms.insert(bruh[i]);
                auto iter = std::next(ms.begin(), ((ms.size()+1)/2)-1);
                max = std::max(max, *iter);
            }
            std::cout << max << std::endl;
        }
    }
    return 0;
}
