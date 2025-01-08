#include <iostream>

// dora's set
int main()
{
    int t, l, r;
    std::cin >> t;
    while(t--)
    {
        std::cin >> l >> r;
        if(!(l&1) || !(r&1))
        {
            std::cout << ((r-l+1)/2)/2<< std::endl;
        }
        else
        {
            std::cout << (((r-l+1)/2)+1)/2 << std::endl;
        }
        
    }
    return 0;
}
