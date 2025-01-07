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

// igor in the museum 
vector<int> link(1e6+5);
vector<pair<int, int>> size(1e6+5, {1, 0});

int find(int x)
{
    if(link[x] != x)
    {
        link[x] = find(link[x]);
    }
    return link[x];
}

bool same(int a, int b)
{
    return find(a) == find(b);
}

void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    if(size[a].first < size[b].first)
    {
        std::swap(a, b);
    }
    size[a].first += size[b].first;
    size[a].second += size[b].second;
    link[b] = a;
}

int main()
{
    int n, m, k, x, y;
    cin >> n >> m >> k;
    vector<std::string> grid(n);
    for(int i = 0; i < n*m; i++)
    {
        link[i] = i;
    }
    for(int i = 0; i < n; i++)
    {
        cin >> grid[i];
    }
    vector<bool> visited(n*m, false);
    vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    std::queue<vector<int>> q;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(!visited[(i*m)+j] && grid[i][j] != '*')
            {
                q.push({i, j, i, j});
                while(!q.empty())
                {
                    int prevX = q.front()[0];
                    int prevY = q.front()[1];
                    int x = q.front()[2];
                    int y = q.front()[3];
                    q.pop();
                    if(visited[(x*m)+y])
                    {
                        continue;
                    }
                    visited[(x*m)+y] = true;
                    int tempCount = 0;
                    for(int l = 0; l < 4; l++)
                    {
                        int nextX = x+directions[l].first;
                        int nextY = y+directions[l].second;
                        if(nextX >= 0 && nextX < n && nextY >= 0 && nextY < m && !visited[(nextX*m)+nextY])
                        {
                            if(grid[nextX][nextY] == '*')
                            {
                                tempCount++;
                            }
                            else
                            {
                                q.push({x, y, nextX, nextY});
                            }
                        }
                    }
                    size[(x*m)+y].second = tempCount;
                    if(!same((prevX*m)+prevY, (x*m)+y))
                    {
                        unite((prevX*m)+prevY, (x*m)+y);
                    }
                }
            }
        }
    }
    for(int i = 0; i < k; i++)
    {
        cin >> x >> y;
        x--;
        y--;
        cout << size[find((x*m)+y)].second << endl; 
    }
    return 0;
}
