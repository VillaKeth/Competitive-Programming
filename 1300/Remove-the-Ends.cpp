#include <bits/stdc++.h>
#define ll long long

using namespace std;

// remove the ends
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> arr(n+1);
        vector<vector<ll>> dp(2, vector<ll>(n+2));
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            dp[0][i] = dp[0][i-1];
            if(arr[i] > 0)
            {
                dp[0][i] += arr[i];
            }
        }
        for(int i = n; i >= 1; i--)
        {
            dp[1][i] = dp[1][i+1];
            if(arr[i] < 0)
            {
                dp[1][i] += -arr[i];
            }
        }
        ll max1 = 0;
        for(int i = 0; i <= n; i++)
        {
            max1 = max(max1, dp[0][i]+dp[1][i+1]);
        }
        cout << max1 << '\n';
    }
    return 0;
}
