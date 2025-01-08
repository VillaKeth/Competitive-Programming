#include <iostream>

// bear and big brother
int main(){
    long long a, b;
    std::cin >> a >> b;
    long long count = 0;
    while(a <= b){
        count++;
        a *= 3;
        b *= 2;
    }
    std::cout << count;
    
    return 0;
}
