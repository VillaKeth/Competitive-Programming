#include<iostream>
#include<vector>
#include<cstdlib>
#include<climits>
#include<algorithm>
#include<cmath>
#define ll long long

// working week
int main()
{
    ll t, n;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n;
        std::cout << (n/3)-2 << std::endl;
    }
    return 0;
}
