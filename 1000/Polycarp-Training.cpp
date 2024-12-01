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

// polycarp training
int main()
{
    int n, temp;
    cin >> n;
    vector<int> bruh;
    bruh.reserve(n);    
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        bruh.push_back(temp);
    }
    std::sort(bruh.begin(), bruh.end());
    int county = 1;
    int counter = 0;
    for(int i = 0; i < bruh.size(); i++)
    {
        if(bruh[i] >= county)
        {
            counter++;
            county++;
        }   
    }
    cout << counter;
    return 0;
}
