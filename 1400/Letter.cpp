#include <iostream>
#include <cstdlib>
#include <vector>
#include <string>
#define cin std::cin
#define cout std::cout
#define vector std::vector
#define ll long long
#define endl '\n'

// letter
int main()
{
    ll upperCount(0), lowerCount(0);
    std::string s;
    cin >> s;
    vector<ll> dp(s.length()+1, 0);
    bool seenUpper = false;
    bool seenLower = false;
    for(int i = s.length()-1; i >= 0; i--)
    {
        if(isupper(s[i]))
        {
            upperCount++;
            seenUpper = true;
            dp[i] = dp[i+1];
        }
        else
        {
            lowerCount++;
            if(seenUpper)
            {
                dp[i] = std::min(1+dp[i+1], upperCount);
            }
        }
    }
    cout << dp[0];
    return 0;
}
