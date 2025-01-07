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

// corner twist
int main()
{
    ll t, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<std::string> bruh1(n);
        vector<std::string> bruh2(n);
        for(int i = 0; i < n; i++)
        {
            cin >> bruh1[i];
        }
        for(int i = 0; i < n; i++)
        {
            cin >> bruh2[i];
        }
        for(int i = 0; i < n-1; i++)
        {
            for(int j = 0; j < m-1; j++)
            {
                if(bruh1[i][j] != bruh2[i][j])
                {
                    ll temp = ((bruh2[i][j])-(bruh1[i][j]));
                    if(temp < 0) // can't do negative modulo
                    {
                        temp += 3;
                    }
                    temp %= 3;
                    bruh1[i][j] = (((bruh1[i][j]-'0')+temp)%3)+'0';
                    bruh1[i+1][j+1] = (((bruh1[i+1][j+1]-'0')+temp)%3)+'0';
                    bruh1[i+1][j] = (((bruh1[i+1][j]-'0')+((!(temp-1))+1))%3)+'0'; // opposite of temp
                    bruh1[i][j+1] = (((bruh1[i][j+1]-'0')+((!(temp-1))+1))%3)+'0';
                }
            }
        }
        bool flag = true;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(bruh1[i][j] != bruh2[i][j])
                {
                    flag = false;
                    i = n;
                    break;
                }
            }
        }
        flag ? cout << "YES" : cout << "NO";
        cout << endl;
    }
    return 0;
}
