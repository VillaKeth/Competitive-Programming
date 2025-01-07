#include <iostream>

// wrong subtraction
int main()
{
    int n, k;
    std::cin >> n >> k;
    while(k--)
    {
        if(n%10)
        {
            n--;
        }
        else
        {
            n /= 10;
        }
    }
    std::cout << n;
    return 0;
}
