#include <iostream>
#include <vector>
#define ll long long

// long number
int main() {
    ll n;
    std::string s;
    std::cin >> n >> s;
    std::vector<ll> bruh(10);
    for(int i = 1; i <= 9; i++)
    {
        std::cin >> bruh[i];
    }
    bool started = false;
    for(int i = 0; i < n; i++)
    {
        ll temp = s[i]-'0';
        if(temp == bruh[temp])
        {
            if(!started)
            {
                continue;
            }
        }
        else if(temp <= bruh[temp])
        {
            if(!started)
            {
                started = true;
            }
            s[i] = bruh[temp]+'0';
        }
        else
        {
            if(started)
            {
                break;
            }
        }
    }
    std::cout << s;
    return 0;
}
