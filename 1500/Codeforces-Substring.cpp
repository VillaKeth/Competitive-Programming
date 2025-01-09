#include <iostream>
#include <vector>
#include <string>

// codeforces substring
int main() {
    long long k, product(1);
    std::string s = "codeforces";
    std::vector<long long> bruh(10, 1);
    std::cin >> k;
    
    long long curCount = 0;
    while(product < k)
    {
        if(curCount == 10)
        {
            curCount = 0;
        }
        product /= bruh[curCount];
        bruh[curCount]++;
        product *= bruh[curCount];
        curCount++;
    }
    std::string final;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < bruh[i]; j++)
        {
            final += s[i];
        }
    }
    std::cout << final;
    return 0;
}
