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

// t-primes (asks for if the number is either 4, or a square number where the root is PRIME not including 1 but must do it in log time i.e, binary search)
int main()
{
    long long n, temp;
    cin >> n;
    vector<long long> allNs;
    allNs.reserve(n);
    for(int i = 0; i < n; i++)
    {
        cin >> temp;
        long long start = 1;
        long long end = temp;
        while(start < end)
        {
            start *= 2;
            end /= 2;
        }
        start /= 2;
        end *= 2;
        long long mid = start + (end-start)/2;
        int midFlag = 0;
        while(start < end)
        {
            mid = start + (end-start)/2;
            if(mid*mid == temp)
            {
                midFlag = 1;
                break;
            }
            else if(mid*mid > temp)
            {
                end = mid;
            }
            else
            {
                start = mid+1;
            }
        }   
        if(midFlag)
        {
            allNs.push_back(mid);
        }
        else
        {
            allNs.push_back(0);
        }
    }
    long long max = -1;
    for(int i = 0; i < n; i++)
    {
        max = std::max(max, allNs[i]);
    }
    vector<int> sieve(max+1, 0);
    cout << max << endl;
    for (int x = 2; x <= max; x++) 
    {
        if(sieve[x])
        {
            continue;
        } 
        for (int u = 2*x; u <= max; u += x) // skips when a multiple of x is already in
        {
            sieve[u] = x;
        }
    }
    sieve[0] = 1;
    sieve[1] = 1; 
    for(int i = 0; i < n; i++)
    {
        if(sieve[allNs[i]] == 0)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
