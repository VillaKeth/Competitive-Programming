#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iomanip>
using namespace std;

// random events
int main()
{
    int t, n, m, r;
    long double p;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<int> perm(n);
        for(int i = 0; i < n; i++)
        {
            cin >> perm[i];
        }
        int count = n;
        int sortedTo = 0;
        for(int i = n-1; i >= 0; i--)
        {
            if(perm[i] != count)
            {
                break;
            }
            count--;
            sortedTo++;
        }
        sortedTo = n-sortedTo;
        vector<long double> keep;
        for(int i = 0; i < m; i++)
        {
            cin >> r >> p;
            if(r >= sortedTo)
            {
                keep.push_back(p);
            }
        }
        if(!sortedTo) // special case if it's all sorted
        {
            cout << setprecision(12) << 1.000000 << endl;
        }
        else
        {
            long double multy = 1.0;
            long double ans = 0.0;
            for(auto i : keep)
            {
                ans += multy*i;
                multy *= 1.0-i;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
