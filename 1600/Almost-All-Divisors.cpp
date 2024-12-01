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

// almost all divisors 
int main()
{
    long long testCases, n, temp;
    cin >> testCases;
    for(int i = 0; i < testCases; i++)
    {
        cin >> n;
        vector<long long> bruh;
        bruh.reserve(n);
        for(int j = 0; j < n; j++)
        {
            cin >> temp;
            bruh.push_back(temp);
        }
        std::sort(bruh.begin(), bruh.end());
        int begin = 0;
        int end = n-1;
        std::set<long long> sp;
        std::set<long long> divisors;
        while(begin <= end)
        {
            long long multiplied = bruh[begin]*bruh[end];
            sp.insert(multiplied);
            divisors.insert(bruh[begin]);
            divisors.insert(bruh[end]);
            begin++;
            end--;
        }
        if(sp.size() != 1)
        {
            cout << -1 << endl;
        }
        else
        {
            auto bruhiter = sp.begin();
            long long possibleNummy = *bruhiter;
            long long value = bruh[n-1];
            int flag = 0;
            for(int j = 2; j < value; j++)
            {
                if(possibleNummy % j == 0 && divisors.find(j) == divisors.end())
                {
                    flag = 1;
                    break;
                } 
            }
            auto iter = sp.begin();
            if(!flag)
            {
                cout << *iter << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
    return 0;
}
