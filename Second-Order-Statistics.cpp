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

// second order statistics
int main()
{
    int length, temp;
    cin >> length;
    std::set<int> sp;
    for(int i = 0; i < length; i++)
    {
        cin >> temp;
        sp.insert(temp);
    }
    auto iter = sp.begin();
    iter++;
    if (sp.size() > 1) cout << *iter;
    else cout << "NO";
    return 0;
}
