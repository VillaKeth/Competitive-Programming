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

// minutes before the new year
int main()
{
    int testCases, h, m;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> h >> m;
        int sum = 60-m;
        h++;
        if(h != 24)
        {
            sum += (24-h)*60;
        }
        cout << sum << endl;
    }
    return 0;
}

