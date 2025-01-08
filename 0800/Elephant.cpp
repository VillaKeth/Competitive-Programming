#include <iostream> 
#include <cmath>

// elephant
int main(){
    long long x;
    std::cin >> x;
    if((x%5) == 0){
        std::cout << (x/5) << std::endl;
    }
    else{
        std::cout << (x/5)+1 << std::endl;
    }
    return 0;
}
