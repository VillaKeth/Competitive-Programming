#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#define ll long long
using namespace std;

// sakurako's field trip
int main()
{
    ll t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<ll> bruh(n);
        for(int i = 0; i < n; i++)
        {
            cin >> bruh[i];
        }
        ll left = 1;
        ll right = n-2;
        while(left < right) 
        {
            if(bruh[left] == bruh[left-1] || bruh[right] == bruh[right+1])
            {
                std::swap(bruh[left], bruh[right]);
            }
            left++;
            right--;
        }
        ll ans = 0;
        for(int i = 0; i < n-1; i++)
        {
            if(bruh[i] == bruh[i+1])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
