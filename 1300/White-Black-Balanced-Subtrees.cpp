#include <bits/stdc++.h>
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

// white-black balanced subtrees
int f[100020];
int d[100020];
char s[100020];

int main()
{
    int t, n, temp;
    cin >> t;
    while(t--)
    {
        memset(d,0,sizeof d);
    		scanf("%d",&n);
    		for (int i=2;i<=n;i++)
    			scanf("%d",&f[i]);
    		scanf("%s",s+1);
    		int ans=0;
    		for (int i=n;i>0;i--)
    		{
    			if (s[i]=='B') d[i]++;
    			else d[i]--;
    			if (d[i]==0) ans++;
    			d[f[i]]+=d[i];
    		}
    		cout<<ans<<endl;
    }
    return 0;
}
