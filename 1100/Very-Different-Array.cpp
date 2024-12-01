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

// very different array
int main()
{
    long long testCases, n, m, temp;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n >> m;
        vector<long long> nVec;
        nVec.reserve(n);
        vector<long long> mVec;
        mVec.reserve(m);
        for(int i = 0; i < n; i++)
        {
            cin >> temp;
            nVec.push_back(temp);
        }
        std::sort(nVec.begin(), nVec.end());
        for(int i = 0; i < m; i++)
        {
            cin >> temp;
            mVec.push_back(temp);
        }
        std::sort(mVec.begin(), mVec.end());
        long long counter = 0;
        long long beginN = 0;
        long long endN = n-1;
        long long beginM = 0;
        long long endM = m-1;
        while(beginN <= endN)
        {
            if(std::max(std::abs(nVec[beginN]-mVec[beginM]), std::abs(nVec[beginN]-mVec[endM])) > std::max(std::abs(nVec[endN]-mVec[beginM]), std::abs(nVec[endN]-mVec[endM])))
            {
                if(std::abs(nVec[beginN]-mVec[beginM]) > std::abs(nVec[beginN]-mVec[endM]))
                {
                    counter += std::abs(nVec[beginN]-mVec[beginM]);
                    beginM++;
                }
                else
                {
                    counter += std::abs(nVec[beginN]-mVec[endM]);
                    endM--;
                }
                beginN++;
            }
            else
            {
                if(std::abs(nVec[endN]-mVec[beginM]) > std::abs(nVec[endN]-mVec[endM]))
                {
                    counter += std::abs(nVec[endN]-mVec[beginM]);
                    beginM++;
                }
                else
                {
                    counter += std::abs(nVec[endN]-mVec[endM]);
                    endM--;
                }
                endN--;
            }
        }
        cout << counter << endl;
    } 
    return 0;
}
