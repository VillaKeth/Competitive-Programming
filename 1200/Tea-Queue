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

// tea queue
int main()
{
    int testCases, n, temp1, temp2;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n;
        std::deque<pair<int, int>> dq;
        for(int i = 0; i < n; i++)
        {
            cin >> temp1 >> temp2;
            dq.push_back(std::make_pair(temp1, temp2));
        }
        int timer = 1;
        std::deque<pair<int, int>>::iterator iter = dq.begin();
        while(!dq.empty() && iter != dq.end()) 
        {
            if(iter->first <= timer && timer <= iter->second)
            {
                cout << timer << ' '; 
                iter++;
                dq.pop_front();
                timer++;
                continue;
                
            }
            else if(iter->first <= timer && timer > iter->second)
            {
                cout << 0 << ' '; 
                iter++;
                dq.pop_front();
                continue;
            }
            timer++;
        }
        cout << endl;
    }
    return 0;
}
