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

// dima and lisa 
// consider trying to sieve up to something like half the number, then just checking in the final for loop if a number is prime using the o(sqrtn) method.
// this idea is based off the fact that any even number can be represented as a sum of two primes
// for the final solution, i simply sieved up to 10000 banking on the idea that the largest gap between primes would be no more than that. 
// considering the density of the primes should be somewhat large up to 1 billion, the average gap is about 21 between every prime.
// however, the approximation is not entirely accurate, and i believe there are test cases that have a gap that greatly exceed 21.
// according to wikipedia, the largest gap between primes is actually 288, so it is possible I could slightly optimize this code in order to have it run better.
// upon looking at the test cases, it appears that I need to sieve to at least 523, not certain why it doesn't correlate with the largest prime gap, it seems I am misunderstanding the problem 
// however, in a competitive setting, considering the time complexity about o(n)sqrt(n), up to 10000, this is still an adequate solution.
int main()
{
    std::ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> sieve(524, 0); 
    sieve[0] = 1;
    sieve[1] = 1;
    for(int i = 2; i <= 523 && i <= n; i++) 
    {
        if(sieve[i])
        {
            continue;
        }
        for(int j = 2*i; j <= 523 && j <= n; j+=i) 
        {
            sieve[j] = i;
        }
    }
    if(n <= 523 && !sieve[n]) 
    {
        cout << 1 << endl;
        cout << n << endl;
    }
    else // is given by problem to be an odd number
    {
        cout << 3 << endl;
        cout << 3 << ' ';
        n -= 3;
        vector<int> primes;
        for(int i = 3; i <= 523 && i <= n; i++) // we don't want two in our primes array 
        {
            if(!sieve[i])
            {
                primes.push_back(i);
            }
        }
        int secondPrime = 0;
        int thirdPrime = 0;
        for(int i = 0; i < primes.size(); i++) // should start from 3, I now traverse the whole array
        {
            if(n-primes[i] <= 523 && !sieve[n-primes[i]]) 
            {
                secondPrime = primes[i];
                thirdPrime = n-primes[i];
                break;
            }
            else
            {
                int isThirdPrime = 1;
                for(int j = 3; j*j <= (n-primes[i]); j++) // remainder should always be an odd number
                {
                    if((n-primes[i]) % j == 0)
                    {
                        isThirdPrime = 0;
                        break;
                    }
                }
                if(isThirdPrime)
                {
                    secondPrime = primes[i];
                    thirdPrime = n-primes[i];
                    break;
                }
            }
        }
        cout << secondPrime << ' ' << thirdPrime;
    }
    return 0;
}
