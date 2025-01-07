#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

// good sequences
int main()
{
    int n;
    cin >> n;
    vector<int> bruh(n);
    vector<int> dp(1e5 + 5, 0);
    for(int i = 0; i < n; i++)
    {
        cin >> bruh[i];
    }
    for(int i = 0; i < n; i++)
    {
        int temp = 0;
        for(int j = 2; j*j <= bruh[i]; j++)
        {
            if(bruh[i]%j == 0)
            {
                temp = std::max(temp, dp[j]+1);
                temp = std::max(temp, dp[bruh[i]/j]+1);
            }
        }
        temp = std::max(temp, dp[bruh[i]]+1);
        for(int j = 2; j*j <= bruh[i]; j++)
        {
            if(bruh[i]%j == 0)
            {
                dp[j] = temp;
                dp[bruh[i]/j] = temp;
            }
        }
        dp[bruh[i]] = temp;
    }
    int ans = 1;
    for(int i = 0; i < 1e5 + 5; i++)
    {
        ans = std::max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
