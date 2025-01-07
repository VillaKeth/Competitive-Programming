#include <iostream>
#include <vector>
#include <queue>
#define ll long long

// increasing subsequence (easy version)
int main() {
    ll n, count(0);
    std::string ans;
    std::cin >> n;
    std::vector<ll> bruh(n);
    for(int i = 0; i < n; i++)
    {
        std::cin >> bruh[i];
    }
    ll prev = -1;
    ll left = 0;
    ll right = n-1;
    while(left <= right)
    {
        if(bruh[left] > prev && bruh[right] > prev)
        {
            if(bruh[left] < bruh[right])
            {
                count++;
                ans += 'L';
                prev = bruh[left];
                left++;
            }
            else
            {
                count++;
                ans += 'R';
                prev = bruh[right];
                right--;
            }
        }
        else if(bruh[left] > prev)
        {
            count++;
            ans += 'L';
            prev = bruh[left];
            left++;
        }
        else if(bruh[right] > prev)
        {
            count++;
            ans += 'R';
            prev = bruh[right];
            right--;
        }
        else
        {
            break;
        }
    }
    std::cout << count << std::endl;
    std::cout << ans << std::endl;
    return 0;
}
