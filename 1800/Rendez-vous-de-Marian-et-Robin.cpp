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

// rendez-vous de marian et robin
struct compare
{
    bool operator()(const std::tuple<ll, ll, ll>& l, std::tuple<ll, ll, ll>& r)
    {
        return std::get<0>(l) > std::get<0>(r);
    } 
};

void dijkstra(vector<pair<bool, vector<pair<ll, ll>>>>& bruh, vector<vector<vector<bool>>>& visited, vector<vector<vector<ll>>>& distances, ll start, ll who)
{
    std::priority_queue<std::tuple<ll, ll, ll>, vector<std::tuple<ll, ll, ll>>, compare> pq;
    pq.push({0, start, bruh[start].first});
    while(!pq.empty())
    {
        ll weight = std::get<0>(pq.top());
        ll node = std::get<1>(pq.top());
        ll onHorse = std::get<2>(pq.top());
        pq.pop();
        if(visited[node][onHorse][who])
        {
            continue;
        }
        visited[node][onHorse][who] = true;
        distances[node][onHorse][who] = weight;
        for(int i = 0; i < bruh[node].second.size(); i++)
        {
            ll nextWeight = bruh[node].second[i].first;
            ll nextNode = bruh[node].second[i].second;
            ll nextOnHorse = std::max(onHorse, (ll)bruh[nextNode].first); // should always grab horse
            if(!visited[nextNode][nextOnHorse][who])
            {
                if(onHorse)
                {
                    pq.push({weight+(nextWeight/2), nextNode, nextOnHorse});
                }
                else
                {
                    pq.push({weight+nextWeight, nextNode, nextOnHorse});
                }
            }
        }
    }
}

int main()
{
    ll t, n, m, h, u, v, w;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> h;
        vector<pair<bool, vector<pair<ll, ll>>>> bruh(n, {false, {}});
        for(int i = 0; i < h; i++)
        {
            cin >> u;
            u--;
            bruh[u].first = true;
        }
        for(int i = 0; i < m; i++)
        {
            cin >> u >> v >> w;
            u--;
            v--;
            bruh[u].second.pb({w, v});
            bruh[v].second.pb({w, u});
        }
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(2, vector<bool>(2, false)));
        vector<vector<vector<ll>>> distances(n, vector<vector<ll>>(2, vector<ll>(2, LLONG_MAX)));
        dijkstra(bruh, visited, distances, 0, 0);
        dijkstra(bruh, visited, distances, n-1, 1);
        bool possible = false;
        ll min = LLONG_MAX;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < 2; j++)
            {
                for(int k = 0; k < 2; k++)
                {
                    if(visited[i][j][0] && visited[i][k][1])
                    {
                        possible = true;
                        min = std::min(min, std::max(distances[i][j][0], distances[i][k][1]));
                    }
                }
            }
        }
        cout << (possible ? min : -1) << endl;
    }
    return 0;
}
