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

// long jumps
int main() {
    int testCases, n, temp;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n;
        vector<int> bruh;
        bruh.reserve(n);
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            bruh.push_back(temp);
        }
        for(int i = n-1; i >= 0; i--)
        {
            if((bruh[i] + i) >= n)
            {
                bruh[i] = bruh[i]; 
            }
            else
            {
                bruh[i] += bruh[bruh[i]+i];
            }
        }
        int max = INT_MIN;
        for(int i = 0; i < n; i++)
        {
            max = std::max(max, bruh[i]);
        }
        cout << max << endl;   
    }
    return 0;
}
