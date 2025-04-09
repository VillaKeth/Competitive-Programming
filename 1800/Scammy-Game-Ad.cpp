#include <bits/stdc++.h>
#define ll long long
#define pb push_back
 
using namespace std;

// scammy game ad
int main()
{
    ll t, n;
    char op1, op2;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<vector<ll>> gates(n, vector<ll>(4));
        ll l(1), r(1);
        for(int i = 0; i < n; i++)
        {
            cin >> op1 >> gates[i][1] >> op2 >> gates[i][3];
            gates[i][0] = (op1 == '+' ? 0ll : 1ll);
            gates[i][2] = (op2 == '+' ? 0ll : 1ll);
        }
        ll peeps = 0;
        peeps += (gates[0][0] ? (l*gates[0][1])-l : gates[0][1]);
        peeps += (gates[0][2] ? (r*gates[0][3])-r : gates[0][3]);
        for(int i = 1; i < n; i++)
        {
            if((gates[i][0] && gates[i][2]) && gates[i][1] != gates[i][3])
            {
                if(gates[i][1] > gates[i][3])
                {
                    l += peeps;
                }
                else
                {
                    r += peeps;
                }
                peeps = 0;
                peeps += (gates[i][0] ? (l*gates[i][1])-l : gates[i][1]);
                peeps += (gates[i][2] ? (r*gates[i][3])-r : gates[i][3]);
            }
            else if((gates[i][0] && gates[i][2]) && gates[i][1] == gates[i][3])
            {
                if(l > r)
                {
                    peeps += (l+peeps)*gates[i][1]-(l+peeps);
                    peeps += (r*gates[i][3])-r;
                }
                else
                {
                    peeps += (r+peeps)*gates[i][1]-(r+peeps);
                    peeps += (l*gates[i][1])-l; 
                }
            }
            else if(gates[i][0] && !gates[i][2] || !gates[i][0] && gates[i][2])
            {
                if(gates[i][0])
                {
                    l += peeps;
                }
                else
                {
                    r += peeps;
                }
                peeps = 0;
                peeps += (gates[i][0] ? (l*gates[i][1])-l : gates[i][1]);
                peeps += (gates[i][2] ? (r*gates[i][3])-r : gates[i][3]);
            }
            else
            {
                peeps += (gates[i][0] ? (l*gates[i][1])-l : gates[i][1]);
                peeps += (gates[i][2] ? (r*gates[i][3])-r : gates[i][3]);
            }
        }
        cout << l+r+peeps << '\n';
    }
    return 0;
}
