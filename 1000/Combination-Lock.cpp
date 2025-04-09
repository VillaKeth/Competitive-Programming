#include <bits/stdc++.h>
#define ll long long
#define pb push_back
 
const ll MODDY = 998244353;
 
using namespace std;

// combination lock
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n&1)
        {
            cout << 1 << ' ';
            for(int i = n; i > 1; i--)
            {
                cout << i << ' ';
            }
            cout << '\n';
        }
        else
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}
