#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<cmath>
#define ll long long

// tea with tangerines
int main()
{
    ll t, n;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        std::vector<ll> bruh(n);
        ll min = INT_MAX;
        ll count = 0;
        for(int i = 0; i < n; i++)
        {
            std::cin >> bruh[i];
            min = std::min(min, bruh[i]);
        }
        min = (2*min)-1;
        for(int i = 0; i < n; i++)
        {
            if(bruh[i] != min && min < bruh[i])
            {
                count += std::ceil((long double)bruh[i]/min)-1;
            }
        }
        std::cout << count << std::endl;
    }
    return 0;
}
