#include <iostream>
#include <cstdlib>
#include <algorithm>

// kar salesman
int main()
{
    long long t, n, x, temp;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n >> x;
        long long max = 0;
        long long sum = 0;
        for(int i = 0; i < n; i++)
        {
            std::cin >> temp;
            max = std::max(max, temp);
            sum += temp;
        }
        std::cout << std::max(max, (sum+x-1)/x) << std::endl;
    }
    return 0;
}
