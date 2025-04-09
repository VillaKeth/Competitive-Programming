#include <bits/stdc++.h>
#define ll long long
#define pb push_back

const ll MODDY = 998244353;

// igor and mountain
using namespace std;

int main()
{
    ll t, n, m, d;
    string temp;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> d;
        vector<string> grid(n+1);
        vector<vector<ll>> dp(n+1, vector<ll>(m+1));
        for(int i = 1; i <= n; i++)
        {
            cin >> temp;
            temp = 'Z'+temp;
            grid[i] = temp;
        }
        vector<ll> prefix(m+1);
        for(int i = 1; i <= m; i++)
        {
            if(grid[n][i] == 'X')
            {
                dp[n][i] = 1;
            }
            prefix[i] = dp[n][i]+prefix[i-1];
        }
        for(int i = 1; i <= m; i++)
        {
            if(grid[n][i] == 'X')
            {
                dp[n][i] = (prefix[min(m, i+d)]-prefix[max(1ll, i-d)-1]+MODDY)%MODDY;
            }
        }
        for(int i = n-1; i >= 1; i--)
        {
            for(int j = 1; j <= m; j++)
            {
                prefix[j] = (dp[i+1][j]+prefix[j-1])%MODDY;
            }
            for(int j = 1; j <= m; j++)
            {
                if(grid[i][j] == 'X')
                {
                    dp[i][j] = (prefix[min(m, j+(d-1))]-prefix[max(1ll, j-(d-1))-1]+MODDY)%MODDY;
                }
            }
            for(int j = 1; j <= m; j++)
            {
                prefix[j] = (dp[i][j]+prefix[j-1])%MODDY;
            }
            for(int j = 1; j <= m; j++)
            {
                if(grid[i][j] == 'X')
                {
                    dp[i][j] = (prefix[min(m, j+d)]-prefix[max(1ll, j-d)-1]+MODDY)%MODDY;
                }
            }
        }
        ll ans = 0;
        for(int i = 1; i <= m; i++)
        {
            ans = (ans+dp[1][i])%MODDY;
        }
        cout << ans << '\n';
    }
    return 0;
}
