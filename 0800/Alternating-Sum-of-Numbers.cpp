#include <iostream>

// alternating sum of numbers
int main()
{
    int t, n, temp;
    std::cin >> t;
    while(t--)
    {
        int sum(0);
        std::cin >> n;
        for(int i = 0; i < n; i++)
        {
            std::cin >> temp;
            if(i&1)
            {
                sum -= temp;
            }
            else
            {
                sum += temp;
            }
        }
        std::cout << sum << std::endl;
    }
    return 0;
}
