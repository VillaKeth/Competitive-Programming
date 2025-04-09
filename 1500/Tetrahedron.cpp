#include <bits/stdc++.h>
#define ll long long
const ll MODDY = 1e9+7;

using namespace std;

// tetrahedron
int main()
{
    ll n;
    cin >> n;
    vector<vector<ll>> dp(2, vector<ll>(4));
    dp[0][3] = 1;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            dp[i%2][j] = (dp[(i-1)%2][(j+1)%4]+dp[(i-1)%2][(j+2)%4]+dp[(i-1)%2][(j+3)%4])%MODDY;
        }
    }
    cout << dp[n%2][3];
    return 0;
}
