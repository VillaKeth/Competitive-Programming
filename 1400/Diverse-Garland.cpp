#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <map>
using namespace std;

// diverse garland
int main()
{
    int n, ans(0);
    string s;
    cin >> n >> s;
    vector<char> choices = {'R', 'G', 'B'};
    if(n == 2)
    {
        if(s[0] == s[1])
        {
            char change;
            for(int j = 0; j < 3; j++)
            {
                if(s[0] != choices[j])
                {
                    change = choices[j];
                }
            }
            s[0] = change;
            ans++;
        }
        cout << ans << endl << s;
        return 0;
    }
    for(int i = 1; i < n-1; i++)
    {
        if(s[i] == s[i-1] && s[i] == s[i+1])
        {
            char change;
            for(int j = 0; j < 3; j++)
            {
                if(s[i] != choices[j])
                {
                    change = choices[j];
                    break;
                }
            }
            s[i] = change;
            ans++;
        }
    }
    for(int i = 1; i < n-1; i++)
    {
        if(s[i] == s[i-1] || s[i] == s[i+1])
        {
            char change;
            for(int j = 0; j < 3; j++)
            {
                if(s[i-1] != choices[j] && s[i+1] != choices[j])
                {
                    change = choices[j];
                    break;
                }
            }
            s[i] = change;
            ans++;
        }
    }
    cout << ans << endl << s;
    return 0;
}
