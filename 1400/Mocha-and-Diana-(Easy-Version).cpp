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

// mocha and diana (easy version) 
std::vector<long long> link1(1001);
std::vector<long long> link2(1001);
std::vector<long long> size1(1001, 1);
std::vector<long long> size2(1001, 1);

long long find1(long long x)
{
    while(x != link1[x])
    {
        x = link1[x];
    }
    return x;
}

bool same1(long long a, long long b)
{
    return find1(a) == find1(b);
}

void unite1(long long a, long long b)
{
    a = find1(a);
    b = find1(b);
    if(size1[b] > size1[a])
    {
        std::swap(a, b);
    }
    link1[b] = a;
    size1[a] += size1[b];
}

long long find2(long long x)
{
    while(x != link2[x])
    {
        x = link2[x];
    }
    return x;
}

bool same2(long long a, long long b)
{
    return find2(a) == find2(b);
}

void unite2(long long a, long long b)
{
    a = find2(a);
    b = find2(b);
    if(size2[b] > size2[a])
    {
        std::swap(a, b);
    }
    link2[b] = a;
    size2[a] += size2[b];
}

int main()
{
    long long n, m1, m2, u, v;
    std::cin >> n >> m1 >> m2;
    for(int i = 0; i < n; i++)
    {
        link1[i] = i;
        link2[i] = i;
    }
    for(int i = 0; i < m1; i++)
    {
        std::cin >> u >> v;
        u--;
        v--;
        if(same1(u, v))
        {
            continue;
        }
        unite1(u, v);
    }
    for(int i = 0; i < m2; i++)
    {
        std::cin >> u >> v;
        u--;
        v--;
        if(same2(u, v))
        {
            continue;
        }
        unite2(u, v);
    }
    long long count = 0;
    std::vector<std::pair<long long, long long>> answer;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(!same1(i, j) && !same2(i, j))
            {
                count++;
                unite1(i, j);
                unite2(i, j);
                answer.push_back({i+1, j+1});
            }
        }
    }
    std::cout << count << std::endl;
    for(int i = 0; i < count; i++)
    {
        std::cout << answer[i].first << ' ' << answer[i].second << std::endl;
    }
    return 0;
}
