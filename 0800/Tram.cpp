#include <iostream>
#include <cstdlib>
#include <algorithm>

// tram
int main()
{
    int n, x, y, ans(0), cur(0);
    std::cin >> n;
    for(int i = 0; i < n; i++)
    {
        std::cin >> x >> y;
        cur -= x;
        cur += y;
        ans = std::max(ans, cur);
    }
    std::cout << ans << std::endl;
    return 0;
}
