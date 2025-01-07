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

// string problem
int main()
{
    ll n, w;
    char a, b;
    std::string s, t;
    cin >> s >> t >> n;
    if(s.length() != t.length())
    {
        cout << -1;
        return 0;
    }
    vector<vector<ll>> matrix(26, vector<ll>(26, INT_MAX));
    for(int i = 0; i < 26; i++)
    {
        matrix[i][i] = 0;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a >> b >> w;
        matrix[a-'a'][b-'a'] = std::min(matrix[a-'a'][b-'a'], w);
    }
    for(int i = 0; i < 26; i++)
    {
        for(int j = 0; j < 26; j++)
        {
            for(int k = 0; k < 26; k++)
            {
                if(matrix[j][i] != INT_MAX && matrix[i][k] != INT_MAX)
                {
                    matrix[j][k] = std::min(matrix[j][k], matrix[j][i]+matrix[i][k]); // through i 
                }
            }
        }
    }
    ll ans = 0;
    bool possible = true;
    for(int i = 0; i < s.length(); i++)
    {
        ll temp = INT_MAX;
        char tempc;
        for(int j = 0; j < 26; j++)
        {
            if(matrix[s[i]-'a'][j] != INT_MAX && matrix[t[i]-'a'][j] != INT_MAX && matrix[s[i]-'a'][j]+matrix[t[i]-'a'][j] < temp) // meeting at j
            {
                temp = matrix[s[i]-'a'][j]+matrix[t[i]-'a'][j];
                tempc = j+'a';
            }
        }
        if(temp == INT_MAX)
        {
            possible = false;
            break;
        }
        ans += temp;
        s[i] = tempc;
    }
    possible ? cout << ans << endl << s : cout << -1;
    return 0;
}
