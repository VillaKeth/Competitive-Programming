#include <iostream>

// minimal coprime
int main(){
    int t, l, r;
    std::cin >> t;
    while(t--) {
        std::cin >> l >> r;
        if(l == 1 && r == 1 || l == 1 && r == 2) {
            std::cout << 1 << '\n';
        } else {
            std::cout << r-l << '\n';
        }
    }
    return 0;
}
