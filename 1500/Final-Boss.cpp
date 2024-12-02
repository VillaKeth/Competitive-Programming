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
const ll MODDY = 1e9+7;
const ll MODDY2 = 998244353;
const ll MODDY3 = 1e8;

// final boss
struct compare  
{  
    bool operator()(const vector<long long>& l, const vector<long long>& r)  
    {  
        return l[0] > r[0];  
    }  
}; 
 
int main() 
{
    long long t, h, n, temp;
    cin >> t;
    while(t != 0)
    {
        cin >> h >> n;
        std::priority_queue<vector<long long>, vector<vector<long long>>, compare> pq;
        std::map<long long, long long> mp;
        vector<long long> damage;
        vector<long long> cooldown;
        damage.reserve(n);
        cooldown.reserve(n);
        long long firstAttack = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            damage.push_back(temp);
            firstAttack += temp;
        }
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            cooldown.push_back(temp);
        }
        if(firstAttack >= h)
        {
            cout << 1 << endl;
            t--;
            continue;
        }
        h -= firstAttack;
        for(int i = 0; i < n; i++)
        {
            mp[cooldown[i]] += damage[i];
        }
        std::sort(cooldown.begin(), cooldown.end());
        long long max = cooldown[n-1]; // array is sorted, max is at the end
        for(auto i : mp)
        {
            pq.push({i.first, i.second, i.first}); 
        }
        long long turn = 0;
        while(h > 0)
        {
            h -= pq.top()[1];
            pq.push({pq.top()[0]+pq.top()[2], pq.top()[1], pq.top()[2]});
            turn = pq.top()[0];
            pq.pop();
        }
        cout << turn+1 << endl;
        t--;
    }
    return 0;
}
