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

// books queries
int main()
{
    int queries, id, left(0), right(0);
    cin >> queries;
    char bruh;
    std::deque<int> dq;
    std::map<int, pair<char, int>> mp;
    for(int i = 0; i < queries; i++)
    {
        cin >> bruh >> id;
        if(bruh == 'L')
        {
            dq.push_front(id);
            mp[id] = std::make_pair(bruh, left);
            left++;
        }
        else if(bruh == 'R')
        {
            dq.push_back(id);
            mp[id] = std::make_pair(bruh, right);
            right++;
        }
        else
        {
            if(mp[id].first == 'L')
            {
                int temp1 = left - mp[id].second - 1;
                int temp2 = mp[id].second + right;
                cout << std::min(temp1, temp2) << endl;
            }
            else // 'R'
            {
                int temp1 = left + mp[id].second;
                int temp2 = right - mp[id].second - 1;
                cout << std::min(temp1, temp2) << endl;
            }
        }
    }
    return 0;
}
