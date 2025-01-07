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
#include <ext/pb_ds/assoc_container.hpp>
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
using namespace __gnu_pbds;
typedef tree<ll, null_type, std::less_equal<ll>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

// array optimization by deque
int main()
{
    ll t, n, findy;
    cin >> t;
    while(t--)
    {
        cin >> n;
        indexed_set sp;
        std::multiset<ll> ms;
        ll count = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> findy;
            sp.insert(findy);
            ll oof = sp.order_of_key(findy); // if you put at beginning 
            ll doof = (ll)sp.size()-sp.order_of_key(findy+1); // if you put at end
            count += std::min(oof, doof);
        }
        cout << count << endl;
    }
    return 0;
}
