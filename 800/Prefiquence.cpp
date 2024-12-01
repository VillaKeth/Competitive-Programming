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

// prefiquence
int main() 
{
    long long testCases, n, m;
    std::string a, b;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n >> m >> a >> b;
        long long beginA = 0;
        long long beginB = 0;
        long long count = 0;
        while(beginB < m && beginA < n)
        {
            if(a[beginA] == b[beginB])
            {
                count++;
                beginA++;
            }
            beginB++;
        }
       cout << count << endl;
    }        
    return 0;
}
