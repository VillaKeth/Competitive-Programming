#include <bits/stdc++.h>
#define ll long long
#define pb push_back
 
using namespace std;

// quiz master
int main()
{
    ll t, n, m;
    cin >> t; 
    vector<set<int>> factors(1e5+1);
    for(int i = 1; i <= 1e5; i++)
    {
        factors[i].insert(i);
        for(int j = 2*i; j <= 1e5; j+=i)
        {
            factors[j].insert(i);
        }
    }
    while(t--)
    {
        cin >> n >> m;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr.begin(), arr.end());
        int ans = INT_MAX;
        set<int> curFactors;
        vector<int> allFactors(1e5+1);
        curFactors.insert(1);
        int l = 0, r = 0;
        while(r < n)
        {
            for(auto i : factors[arr[r]])
            {
                if(i <= m && i > 1)
                {
                    allFactors[i]++;
                    curFactors.insert(i);
                }
            }
            while(curFactors.size() == m && l <= r)
            {
                ans = min(ans, arr[r]-arr[l]);
                for(auto i : factors[arr[l]])
                {
                    if(i <= m && i > 1)
                    {
                        allFactors[i]--;   
                        if(!allFactors[i])
                        {
                            curFactors.erase(i);
                        }
                    }
                }
                l++;
            }
            r++;
        }
        cout << (ans == INT_MAX ? -1 : ans) << '\n';
    }
    return 0;
}
