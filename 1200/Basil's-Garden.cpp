#include <iostream>
#include <vector>

// basil's garden
int main(){
    long long t, n;
    std::cin >> t;
    while(t--){
        std::cin >> n;
        std::vector<long long> bruh(n);
        for(int i = 0; i < n; i++){
            std::cin >> bruh[i];
        }
        long long cur = -1;
        for(int i = n-1; i >= 0; i--){
            if(bruh[i] <= cur){
                cur++;
            }
            else{
                cur = bruh[i];
            }
        }
        std::cout << cur << std::endl;
    }
}
