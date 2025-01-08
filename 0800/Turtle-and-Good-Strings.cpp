#include <iostream>
#include <cstdlib>

// turtle and good strings
int main()
{
    int t, n;
    std::string s;
    std::cin >> t;
    while(t--)
    {
        std::cin >> n >> s;
        if(s[0] != s[n-1])
        {
            std::cout << "YES" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }
    return 0;
}
