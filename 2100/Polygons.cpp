#include <cstdlib>
#include <vector>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
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

// polygons
ll GCD(ll a, ll b)
{
	while(b != 0)
	{
		ll temp = b;
		b = a%b;
		a = temp;
	}
	return a;
}

ll LCM(ll a, ll b)
{
	return (a*b)/GCD(a, b);
}

bool compareSlopes(ll x1, ll y1, ll x2, ll y2, ll x3, ll y3)
{
    ll slope1 = std::abs(y2-y1); // prev-(prev-1)
    ll slope2 = std::abs(y3-y2); // cur-prev
    ll lcm = LCM(std::abs(x2-x1), std::abs(x3-x2));
    if(x1 == x2)
    {
        slope1 = LLONG_MAX;
    }
    else
    {
        slope1 = slope1*(lcm/(x2-x1));
        if(x2 < x1 && y2 >= y1 || x2 >= x1 && y2 < y1)
        {
            slope1 = -slope1;
        }
    }
    if(x2 == x3)
    {
        slope2 = LLONG_MAX;
    }
    else
    {
        slope2 = slope2*(lcm/(x3-x2));
        if(x3 < x2 && y3 >= y2 || x3 >= x2 && y3 < y2)
        {
            slope2 = -slope2;
        }
    }
    if(slope2 > slope1)
    {
        return true;
    }
    return false;
}

int main()
{
    ll n, m, x, y;
    cin >> n;
    std::map<pair<ll, ll>, bool> mp;
    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        mp[{x, y}] = 0;
    }
    cin >> m;
    for(int i = 0; i < m; i++)
    {
        cin >> x >> y;
        mp[{x, y}] = 1;
    }
    vector<std::tuple<ll, ll, ll>> upperPoints(n+m);
    vector<std::tuple<ll, ll, ll>> lowerPoints(n+m);
    ll count = 0;
    for(auto i : mp) // vectors with no duplicates
    {
        upperPoints[count] = {i.first.first, i.first.second, i.second};
        lowerPoints[count] = {-i.first.first, -i.first.second, i.second};
        count++;
    }
    std::sort(upperPoints.begin(), upperPoints.end());
    std::sort(lowerPoints.begin(), lowerPoints.end());
    ll min = std::get<0>(upperPoints[0]);
    ll newStart = 0;
    vector<std::tuple<ll, ll, ll>> upperHull;
    while(std::get<0>(upperPoints[newStart]) == min) // don't need to bound since polygon a is convex
    {
        upperHull.pb({upperPoints[newStart]});
        newStart++;
    }
    auto prev = upperHull.end()-1;
    for(int i = newStart; i < n+m; i++)
    {
        ll prevIndex = prev-upperHull.begin();
        while(upperHull.size() >= 2 && compareSlopes(std::get<0>(upperHull[prevIndex-1]), std::get<1>(upperHull[prevIndex-1]), std::get<0>(upperHull[prevIndex]), std::get<1>(upperHull[prevIndex]), std::get<0>(upperPoints[i]), std::get<1>(upperPoints[i]))) // if it goes up compared to the previous line segment
        {
            upperHull.pop_back();
            prevIndex--;
        }
        upperHull.pb(upperPoints[i]);
        prev = upperHull.end()-1;
    }
    min = std::get<0>(lowerPoints[0]);
    newStart = 0;
    vector<std::tuple<ll, ll, ll>> lowerHull;
    while(std::get<0>(lowerPoints[newStart]) == min) // don't need to bound since no three consecutive points lie on the same straight line
    {
        lowerHull.pb({lowerPoints[newStart]});
        newStart++;
    }
    for(int i = newStart; i < n+m; i++)
    {
        ll prevIndex = prev-lowerHull.begin();
        while(lowerHull.size() >= 2 && compareSlopes(std::get<0>(lowerHull[prevIndex-1]), std::get<1>(lowerHull[prevIndex-1]), std::get<0>(lowerHull[prevIndex]), std::get<1>(lowerHull[prevIndex]), std::get<0>(lowerPoints[i]), std::get<1>(lowerPoints[i])))
        {
            lowerHull.pop_back();
            prevIndex--; 
        }
        lowerHull.pb(lowerPoints[i]);
        prev = lowerHull.end()-1;
    }
    bool can = true;
    for(int i = 0; i < upperHull.size(); i++)
    {
        if(std::get<2>(upperHull[i]))
        {
            can = false;
            break;
        }
    }
    for(int i = 0; i < lowerHull.size(); i++)
    {
        if(std::get<2>(lowerHull[i]))
        {
            can = false;
            break;
        }
    }
    cout << (can ? "YES" : "NO");
    return 0;
}
