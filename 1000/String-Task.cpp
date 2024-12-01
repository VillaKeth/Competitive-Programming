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

// string task
int main()
{
    std::string bruh, ans(""); 
    cin >> bruh;
    for(int i = 0; i < bruh.length(); i++)
    {
        if((bruh[i] == 'a') || (bruh[i] == 'e') || (bruh[i] == 'i') || (bruh[i] == 'o') || (bruh[i] == 'u') || (bruh[i] == 'y') || (bruh[i] == 'A') || (bruh[i] == 'E') || (bruh[i] == 'I') || (bruh[i] == 'O') || (bruh[i] == 'U') || (bruh[i] == 'Y'))
        {
            continue;
        }
        else
        {
            ans += '.';
            ans += tolower(bruh[i]);
        }
    }
    cout << ans;
    return 0;
}
