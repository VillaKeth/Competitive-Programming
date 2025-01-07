#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <iostream>
#include <string>
#include <deque>
#include <queue>
#include <stack>
#include <cmath>
#include <climits>
#include <algorithm>
#include <chrono>
#include <cstdint>
#include <fstream> 
#include <numeric>
#define ll long long
#define ld long double
#define pb push_back
#define cin std::cin
#define cout std::cout
#define endl '\n'
#define vector std::vector
#define pair std::pair
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// the strict teacher (hard version) 
int main()
{   
    ll t, n, m, queries, q;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> queries;
        vector<ll> teachers(m);
        for(int i = 0; i < m; i++)
        {
            cin >> teachers[i];
        }
        std::sort(teachers.begin(), teachers.end());
        for(int i = 0; i < queries; i++)
        {
            cin >> q;
            auto iter = std::lower_bound(teachers.begin(), teachers.end(), q);
            if(iter == teachers.end()) // greater than all
            {
                cout << n-(teachers[(teachers.end()-1)-teachers.begin()]) << endl;
            }
            else if(iter == teachers.begin()) // less than all
            {
                cout << teachers[iter-teachers.begin()]-1 << endl;
            }
            else // in between two
            {
                cout << (std::abs(teachers[iter-teachers.begin()]-teachers[(iter-1)-teachers.begin()]))/2<< endl;
            }
        }
    }
    return 0;
}
