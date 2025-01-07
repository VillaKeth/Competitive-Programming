#include <iostream>
#include <vector>
#define ll long long

// another permutation problem
int main()
{
    ll t, n;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        ll ans = -1;
        for(int i = 1; i <= n; i++)
        {
            ll cur = 0;
            ll max = -1;
            for(int j = 1; j <= n-i; j++)
            {
                cur += j*j;
                max = std::max(max, (ll)j*j);
            }
            ll county = n; 
            for(int j = n-i+1; j <= n; j++)
            {
                cur += j*county;
                max = std::max(max, (ll)j*county);
                county--;
            }
            ans = std::max(ans, cur-max);
        }
        std::cout << ans << std::endl;
    }
    return 0;
}
