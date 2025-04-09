#include <bits/stdc++.h>
#define ll long long
#define pb push_back

using namespace std;

// mysterious present
int main()
{
    ll n, w, h, u, v;
    cin >> n >> w >> h;
    vector<pair<ll, ll>> arr;
    map<pair<ll, ll>, ll> originalIndex;
    for(int i = 0; i < n; i++)
    {
        cin >> u >> v;
        if(u > w && v > h)
        {
            arr.pb({u, v});
            originalIndex[{u, v}] = i+1;
        }
    }
    sort(arr.begin(), arr.end());
    n = arr.size();
    vector<ll> dp(n, 1);
    for(int i = 0; i < n; i++)
    {
        for(int j = i+1; j < n; j++)
        {
            if(arr[j].first > arr[i].first && arr[j].second > arr[i].second)
            {
                dp[j] = std::max(dp[j], dp[i]+1);
            }
        }
    }
    ll ans = 0;
    if(n)
    {
        ans = *max_element(dp.begin(), dp.end());  
    }
    cout << ans << '\n';
    vector<ll> order(ans);
    ll prevW = INT_MAX;
    ll prevU = INT_MAX;
    for(int i = ans-1; i >= 0; i--)
    {
        for(int j = n-1; j >= 0; j--)
        {
            if(dp[j] == i+1 && arr[j].first < prevW && arr[j].second < prevU)
            {
                prevW = arr[j].first;
                prevU = arr[j].second;
                order[i] = originalIndex[{prevW, prevU}];
            }
        }
    }
    for(auto i : order)
    {
        cout << i << ' ';
    }
    return 0;
}
