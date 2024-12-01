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

// lucky division
int main()
{
    int n, flag(0);
    cin >> n;
    vector<int> luckys = {4, 7, 47, 74, 444, 447, 474, 477, 744, 747, 774, 777};
    for(int i = 0; i < luckys.size(); i++)
    {
        if(n % luckys[i] == 0)
        {
            flag = 1;
        }
    }
    if(flag)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
