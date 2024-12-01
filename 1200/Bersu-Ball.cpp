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

// bersu ball
int main()
{
    int n, m, temp;
    cin >> n;
    vector<int> nVec;
    nVec.reserve(n);
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        nVec.push_back(temp);
    }
    cin >> m;
    vector<int> mVec;
    mVec.reserve(m);
    for(int i = 0; i < m; i++)
    {
        cin >> temp;
        mVec.push_back(temp);
    }
    std::sort(nVec.begin(), nVec.end());
    std::sort(mVec.begin(), mVec.end());
    int endN = n-1;
    int endM = m-1;
    int counter = 0;
    while(endN >= 0 && endM >= 0)
    {
        if(std::abs(nVec[endN]-mVec[endM]) <= 1)
        {
            counter++;
            endN--;
            endM--;
        }
        else if(nVec[endN] > mVec[endM])
        {
            endN--;
        }
        else
        {
            endM--;
        }
    }
    cout << counter;
    return 0;
}
