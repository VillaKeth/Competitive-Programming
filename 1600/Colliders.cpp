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

// colliders
int main()
{
    long long n, m;
    std::string request, hadronNumberString;
    cin >> n >> m;
    std::map<long long, pair<bool, long long>> status; // should store the common divisor, then a pair of if it's on and what the stored hadron is
    std::map<long long, bool> hadronMap;
    for(int i = 0; i < m; i++)
    {
        cin >> request;
        cin >> hadronNumberString;
        int loggy = 1;
        long long hadronNumber = 0;
        for(int j = hadronNumberString.length()-1; j >= 0; j--)
        {
            hadronNumber += (loggy*(hadronNumberString[j]-'0'));
            loggy *= 10;
        }
        if(request == "+") // attempt to turn on
        {
            if(hadronMap[hadronNumber]) // is already on
            {
                cout << "Already on" << endl;
            }
            else // try to turn on but check if collision
            {
                int flag = 0;
                if(status[hadronNumber].first && hadronMap[status[hadronNumber].second])
                {
                    flag = 1;
                    cout << "Conflict with " << status[hadronNumber].second << endl;
                }
                if(!flag)
                {
                    for(int j = 2; j*j <= hadronNumber; j++)
                    {
                        if(hadronNumber % j == 0)
                        {
                            if(status[j].first && hadronMap[status[j].second]) // if found other number with common divisor
                            {
                                cout << "Conflict with " << status[j].second << endl;
                                flag = 1;
                                break;
                            }
                            else if(status[hadronNumber/j].first && hadronMap[status[hadronNumber/j].second]) // if found multiplicative pair
                            {
                                cout << "Conflict with " << status[hadronNumber/j].second << endl;
                                flag = 1;
                                break;
                            }
                            else
                            {
                                //std::cout << "hadron number is: " << hadronNumber << " j is: " << j << " hadronnunmber/j is: " << hadronNumber/j;
                                status[j].first = true;
                                status[j].second = hadronNumber;
                                status[hadronNumber/j].first = true;
                                status[hadronNumber/j].second = hadronNumber;
                            }
                        }
                    }
                }  
                if(!flag)
                {
                    cout << "Success" << endl;
                    hadronMap[hadronNumber] = true;
                    status[hadronNumber].first = true;
                    status[hadronNumber].second = hadronNumber;
                }
            }
        }
        else // turn off
        {
            if(hadronMap[hadronNumber]) // if it's on
            {
                hadronMap[hadronNumber] = false; // now it's off
                cout << "Success" << endl;
            }
            else
            {
                cout << "Already off" << endl;
            }
        }
    }
    return 0;
}
