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
#define endl std::endl
#define vector std::vector
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// remainder
int main()
{
    int n, x, y;
    std::string bruh;
    cin >> n >> x >> y >> bruh;
    int start = n-x;
    int endish = n-y-1;
    int count = 0;
    for(int i = start; i < n; i++)
    {
        if(i == endish)
        {
            if(bruh[i] == '0')
            {
                count++;
            }
        }
        else
        {
            if(bruh[i] == '1')
            {
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
