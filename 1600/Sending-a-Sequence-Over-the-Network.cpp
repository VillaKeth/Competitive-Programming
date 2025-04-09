#include <bits/stdc++.h>
#define ll long long
#define pb push_back
 
using namespace std;

// sending a sequence over the network
int main()
{
    ll t, n;
    cin >> t; 
    while(t--)
    {
        cin >> n;
        vector<ll> arr(n+1);
        vector<ll> dp(n+1);
        for(int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        dp[0] = 1;
        for(int i = 1; i <= n; i++)
        {
            if(arr[i]+i <= n && dp[i-1])
            {
                dp[arr[i]+i] = 1;
            }
            if(i-arr[i] >= 1 && dp[i-arr[i]-1])
            {
                dp[i] = 1;
            }
        }
        cout << (dp[n] ? "YES" : "NO") << '\n';
    }
    return 0;
}
