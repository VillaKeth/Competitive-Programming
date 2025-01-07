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
const ll MODDY = 1000000007;
const ll MODDY2 = 998244353;

// password cracking
int main()
{
    int t, n, response;
    cin >> t;
    while(t--)
    {
        cin >> n;
        response = 0;
        std::string ans = "0";
        bool zeroBack = false;
        bool oneBack = false;
        bool direction = false;
        while(ans.length() < n || response == 0)
        {
            cout << "? " << ans << endl;
            cout.flush();
            if(!direction)
            {
                if(ans[ans.length()-1] == '0')
                {
                    zeroBack = true;
                }
                else
                {
                    oneBack = true;
                }
            }
            else
            {
                if(ans[0] == '0')
                {
                    zeroBack = true;
                }
                else
                {
                    oneBack = true;
                }
            }
            cin >> response;
            if(response == -1)
            {
                cout << -1 << "WRONG" << endl;
                break;
            }
            if(response)
            {
                if(!direction)
                {
                    if(ans.length() < n)
                    {
                        ans += "0";
                        response = false;
                    }
                }
                else
                {
                    if(ans.length() < n)
                    {
                        ans = "1"+ans;
                        response = false;
                    }
                }
                zeroBack = false;
                oneBack = false;
            }
            else
            {
                char prev;
                if(!direction)
                {
                    prev = ans[ans.length()-1];
                    ans.pop_back();
                }
                else
                {
                    prev = ans[0];
                    std::reverse(ans.begin(), ans.end());
                    ans.pop_back();
                    std::reverse(ans.begin(), ans.end());
                }
                if(zeroBack && oneBack) // already tried both
                {
                    ans = "1"+ans;
                    direction = true;
                }
                else if(prev == '0')
                {
                    if(!direction)
                    {
                        ans += "1";
                    }
                    else
                    {
                        ans = "1"+ans;
                    }
                }
                else
                {
                    if(!direction)
                    {
                        ans += "0";
                    }
                    else
                    {
                        ans = "0"+ans;
                    }
                    
                }
            }
        }
        cout << "! " << ans << endl;
        cout.flush();
    }  
    return 0;
}
