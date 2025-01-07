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
#define hewwo cout << "hewwo" << endl;
const ll MODDY = 1000000007;

// increasing subsequence (hard version)
int main() 
{
    ll n, count(0);
    std::string ans;
    cin >> n;
    vector<ll> bruh(n);
    for(int i = 0; i < n; i++)
    {
        cin >> bruh[i];
    }
    ll prev = -1;
    ll left = 0;
    ll right = n-1;
    while(left <= right)
    {
        if(bruh[left] > prev && bruh[right] > prev)
        {
            if(bruh[left] == bruh[right])
			{
				if(right-left <= 1) // doesn't matter, base case
				{
					count++;
					ans += 'L';
				}
				else // check going all the way with left then going all the way with right
				{
					ll templ = left;
					ll tempr = right;
					ll tempPrev = -1;
					ll leftCount = 0;
					ll rightCount = 0;
					while(templ < right && bruh[templ] > tempPrev)
					{
						tempPrev = bruh[templ];
						leftCount++;
						templ++;
					}
					tempPrev = -1;
					while(tempr > left && bruh[tempr] > tempPrev)
					{
						tempPrev = bruh[tempr];
						rightCount++;
						tempr--;
					}
					if(leftCount > rightCount)
					{
						count += leftCount;
						for(int i = 0; i < leftCount; i++)
						{
							ans += 'L';
						}
					}
					else
					{
						count += rightCount;
						for(int i = 0; i < rightCount; i++)
						{
							ans += 'R';
						}
					}
				}
				break;
			}
			else if(bruh[left] < bruh[right])
            {
                count++;
                ans += 'L';
                prev = bruh[left];
                left++;
            }
            else
            {
                count++;
                ans += 'R';
                prev = bruh[right];
                right--;
            }
        }
        else if(bruh[left] > prev)
        {
            count++;
            ans += 'L';
            prev = bruh[left];
            left++;
        }
        else if(bruh[right] > prev)
        {
            count++;
            ans += 'R';
            prev = bruh[right];
            right--;
        }
        else
        {
            break;
        }
    }
    cout << count << endl;
    cout << ans << endl;
    return 0;
}
