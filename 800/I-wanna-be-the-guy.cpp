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

// i wanna be the guy
int main()
{
    int n, p, temp;
    std::set<int> sp;
    cin >> n >> p;
    for(int i = 0; i < p; i++)
    {
        cin >> temp;
        sp.insert(temp);
    }
    cin >> p;
    for(int i = 0; i < p; i++)
    {
        cin >> temp;
        sp.insert(temp);
    }
    if(sp.size() == n)
    {   
        cout << "I become the guy." << endl;
    }
    else
    {
        cout << "Oh, my keyboard!" << endl;
    }
    return 0;
}
