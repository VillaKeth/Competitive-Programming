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

// save more mice
int main()
{
    int testCases, n, k, temp;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        std::priority_queue<int> pq;
        cin >> n >> k;
        for(int i = 0; i < k; i++)
        {
            cin >> temp;
            pq.push(temp);
        }
        int counter = 0;
        int originalN = n;
        while(!pq.empty() && n > (originalN-pq.top()))
        {
            n -= (originalN-pq.top());
            pq.pop();
            counter++;
        }
        cout << counter << endl;
    }
    return 0;
}
