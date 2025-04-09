#include <bits/stdc++.h>
#define ll long long

using namespace std;

// elections
int main()
{
    ll t, n, c, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        vector<ll> arr(n+1);
        vector<ll> pref(n+1);
        cin >> arr[1];
        arr[0] = 0;
        arr[1] += c;
        pref[1] = arr[1];
        for(int i = 2; i <= n; i++)
        {
            cin >> arr[i];
            pref[i] = arr[i]+pref[i-1];
        }
        ll curMax = arr[1];
        ll maxIndex = 1;
        for(int i = 2; i <= n; i++)
        {
            if(arr[i] > curMax)
            {
                curMax = arr[i];
                maxIndex = i;
            }
        }
        
        for(int i = 1; i <= n; i++)
        {
            if(i == maxIndex)
            {
                ans = 0;
            }
            else if(maxIndex < i || arr[i]+pref[i-1] >= curMax)
            {
                ans = i-1;
            }
            else
            {
                ans = (i-1)+1; 
            }
            cout << ans << ' '; 
        }
        cout << '\n';
    }
    return 0;
}
