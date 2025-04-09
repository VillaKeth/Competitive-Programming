#include <bits/stdc++.h>
#define ll long long

using namespace std;

// breach of faith
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> arr(2*n);
        vector<ll> ans((2*n)+1);
        ll sum = 0;
        ll sum2 = 0;
        for(int i = 0; i < 2*n; i++)
        {
            cin >> arr[i];
        }
        std::sort(arr.begin(), arr.end());
        for(int i = 0; i < n+1; i++)
        {
            sum += arr[(2*n)-i-1];
            ans[2*i] = arr[(2*n)-i-1];
        }
        for(int i = 0; i < n-1; i++)
        {
            sum2 += arr[i];
            ans[(2*i)+1] = arr[i];
        }
        ans[(2*n)-1] = sum-sum2;
        for(auto i : ans)
        {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
