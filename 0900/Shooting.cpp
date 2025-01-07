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

// shooting
int main()
{
    ll n, count(0);
    cin >> n;
    vector<ll> bruh(n);
    std::map<ll, std::queue<ll>> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> bruh[i];
        mp[bruh[i]].push(i+1);
    }
    vector<ll> newBruh = bruh;
    std::sort(bruh.begin(), bruh.end());
    ll shot = 0;
    for(int i = n-1; i >= 0; i--)
    {
        count += 1+(shot*bruh[i]);
        shot++;
    }
    vector<ll> ans;
    for(int i = n-1; i >= 0; i--)
    {
        ans.pb(mp[bruh[i]].front());
        mp[bruh[i]].pop();
    }
    cout << count << endl;
    for(auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}
