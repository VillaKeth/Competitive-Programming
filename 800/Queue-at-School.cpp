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

// queue at school
int main()
{
    int n, t;
    cin >> n >> t;
    std::string bruh;
    cin >> bruh;
    while(t != 0)
    {
        for(int i = 0; i < bruh.length()-1; i++)
        {
            if(bruh[i] == 'B' && bruh[i+1] == 'G')
            {
                bruh[i] = 'G';
                bruh[i+1] = 'B';
                i++;
            }
        }
        t--;
    }
    cout << bruh << endl;
    return 0;
}
